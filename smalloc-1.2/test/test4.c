#include <stdio.h>
#include "smalloc.h"

int 
main()
{
    const int const test_alloc[] = {2500, 3000, 1000, 1500};
	void *p1, *p2, *p3, *p4 ;

	p1 = smalloc(test_alloc[0]) ; 
	printf("smalloc(%d)\n", test_alloc[0]) ; 
	print_sm_containers() ;
#if VERSION > 11
    print_sm_unuses() ;
#endif
#if VERSION > 10
	print_sm_uses() ;
#endif

	p2 = smalloc(test_alloc[1]) ; 
	printf("smalloc(%d)\n", test_alloc[1]) ; 
	print_sm_containers() ;
#if VERSION > 11
    print_sm_unuses() ;
#endif
#if VERSION > 10
	print_sm_uses() ;
#endif


	p3 = smalloc(test_alloc[2]) ; 
	printf("smalloc(%d)\n", test_alloc[2]) ; 
	print_sm_containers() ;
#if VERSION > 11
    print_sm_unuses() ;
#endif
#if VERSION > 10
	print_sm_uses() ;
#endif

	printf("sfree(%p)\n", p3);
    sfree(p3);
	print_sm_containers() ;
#if VERSION > 11
    print_sm_unuses() ;
#endif
#if VERSION > 10
	print_sm_uses() ;
#endif


	p4 = smalloc(test_alloc[3]) ; 
	printf("smalloc(%d)\n", test_alloc[3]) ; 
	print_sm_containers() ;
#if VERSION > 11
    print_sm_unuses() ;
#endif
#if VERSION > 10
	print_sm_uses() ;
#endif
}
