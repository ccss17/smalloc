#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "smalloc.h" 

static int memory_accumulate;
static int memory_all;
static int memory_allocated;
static int retain_ct;

sm_container_ptr sm_first = 0x0 ;
sm_container_ptr sm_last = 0x0 ;
sm_container_ptr sm_unused_containers = 0x0 ;

void sm_container_split(sm_container_ptr hole, size_t size)
{
	sm_container_ptr remainder = hole->data + size ;

	remainder->data = ((void *)remainder) + sizeof(sm_container_t) ;
	remainder->dsize = hole->dsize - size - sizeof(sm_container_t) ;
	remainder->status = Unused ;
	remainder->next = hole->next ;
	hole->next = remainder ;

	if (hole == sm_last)
		sm_last = remainder ;
}

void * sm_retain_more_memory(int size)
{
	sm_container_ptr hole ;
	int pagesize = getpagesize() ;
	int n_pages = 0 ;
    int alloc_size;

	n_pages = (sizeof(sm_container_t) + size + sizeof(sm_container_t)) / pagesize  + 1 ;
    alloc_size = n_pages * pagesize;
	hole = (sm_container_ptr) sbrk(n_pages * pagesize) ;
    memory_all += alloc_size;
	if (hole == 0x0)
		return 0x0 ;

	hole->data = ((void *) hole) + sizeof(sm_container_t) ;
	hole->dsize = n_pages * getpagesize() - sizeof(sm_container_t) ;
	hole->status = Unused ;

    retain_ct+=1;

	return hole ;
}

void * smalloc(size_t size) 
{
    size_t min=0x0;
	sm_container_ptr min_hole = 0x0 ;
	sm_container_ptr hole = 0x0 ;

	sm_container_ptr itr = 0x0 ;
	for (itr = sm_first ; itr != 0x0 ; itr = itr->next) {
		if (itr->status == Busy)
			continue ;

        /*if (size == itr->dsize) {*/
        if (size + sizeof(sm_container_t) == itr->dsize) {
			// a hole of the exact size
			itr->status = Busy ;
            memory_accumulate += itr->dsize;
            memory_allocated += itr->dsize;
			return itr->data ;
		}
		else if (size + sizeof(sm_container_t) < itr->dsize) {
			// a hole large enought to split 

            if (min == 0x0) {
                min = itr->dsize;
                min_hole = itr ;
            }
            else {
                if (min > itr->dsize){
                    min = itr->dsize;
                    min_hole = itr ;
                }
            }

			continue ; 
		}
	}

    hole = min_hole;

	if (hole == 0x0) {
		hole = sm_retain_more_memory(size) ;

		if (hole == 0x0)
			return 0x0 ;

		if (sm_first == 0x0) {
			sm_first = hole ;
			sm_last = hole ;
			hole->next = 0x0 ;
		}
		else {
			sm_last->next = hole ;
			sm_last = hole ;
			hole->next = 0x0 ;
		}
	}
	sm_container_split(hole, size) ;
	hole->dsize = size ;
	hole->status = Busy ;
    memory_accumulate += size;
    memory_allocated += size;
	return hole->data ;
}



void sfree(void * p)
{
	sm_container_ptr itr ;
	for (itr = sm_first ; itr->next != 0x0 ; itr = itr->next) {
		if (itr->data == p) {
			itr->status = Unused ;
            memory_allocated -= itr->dsize;
			break ;
		}
	}
}

void print_sm_containers()
{
	sm_container_ptr itr ;
	int i = 0 ;

	printf("==================== sm_containers ====================\n") ;
	for (itr = sm_first ; itr != 0x0 ; itr = itr->next, i++) {
		char * s ;
		printf("%3d:%p:%s:", i, itr->data, itr->status == Unused ? "Unused" : "  Busy") ;
		printf("%8d:", (int) itr->dsize) ;

		for (s = (char *) itr->data ;
			 s < (char *) itr->data + (itr->dsize > 8 ? 8 : itr->dsize) ;
			 s++) 
			printf("%02x ", *s) ;
		printf("\n") ;
	}

}
void print_sm_uses()
{
	fprintf(stderr, "==================== sm_uses ==========================\n") ;
    fprintf(stderr, "AMOUNT OF MEMORY (all):%d\n", memory_all);
    fprintf(stderr, "AMOUNT OF MEMORY (allocated at now):%d\n", memory_allocated);
    fprintf(stderr, "AMOUNT OF MEMORY (unallocated):%d\n", memory_all - (memory_allocated + retain_ct * 64));
    fprintf(stderr, "AMOUNT OF MEMORY (allocated so far):%d\n", memory_accumulate);
	fprintf(stderr, "=======================================================\n") ;
}
