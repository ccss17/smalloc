# smalloc

---

## overview
- Upgrade __smalloc__ version 1.0 to 1.1 to 1.2 as requested
- 1.0 (given)
  - basic APIs
  - first fit algorithm for allocating memory
- 1.1
  - memory usage report
  - best fit algorithm for allocating memory
- 1.2
  - fast allocation with unused container list
  - merge unused continuous containers at free

#### requirements
- source code for **each version**
  - two archive (ver1.1.tar.gz, ver1.2.tar.gz)
- write-up: up to 3 pages **PDF**

#### background
- `&etext` : first address of __text__ segment
- `&edata` : first address of __data__ segment
- `&end` : first address of __bss__ segment
- `sbrk(0)` : first address of __heap__ segment
- `sbrk(s)` : retains additional __s bytes__ in heap and return starting address.
- `getpagesize()` : returns the number of bytes in a page

---

## smalloc 1.0

#### APIs
- `void * smalloc(size_t s)` : allocate unused, continuous **s bytes** in the heap, and return its starting address. Depending on the memory use, __smalloc__ may retain more memory to allocate s bytes. Or, it returns __null__ if it fails at allocating s bytes.
- `void sfree(void * p)` : reclaims the continuous memory region allocated by sammloc, which starts from address __p__.
- `void print_sm_containers()`

#### Data Structure

