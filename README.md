# Arena.
An arena allocator implementation for C.

# Quick Start.
## How to use!
```c
    // NOTE (#1): allocate the whole arena which has a size of 64kb. (Which u can change btw.)
	arena_init();

	{
        // NOTE (#2): Use the memory instead of malloc.
        // 1. for strings.

        char *str = (char *)allocate(20);
		strcpy(str, "Hello, world!\n");

        // 2. for other structures.
		Point *p = (Point *) allocate(sizeof(Point));
		p->x = 69;
		p->y = 96;
		
        // printing.
		printf("%s", str);
		printf("(%i, %i)\n", p->x, p->y);

	}
    // NOTE (#3): Free the 64kb that were allocated.
	// valgrind says: All heap blocks were freed -- no leaks are possible
    arena_deallocate();
```
