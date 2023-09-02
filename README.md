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

# About the api
## Files

[Arena.h](https://github.com/Hossin-Azmoud/Arena/blob/main/src/Arena.h): Arena api header file.
[ArenaApi.c](https://github.com/Hossin-Azmoud/Arena/blob/main/src/ArenaApi.c): The file that has the source for an arena interface to manage an entity of a global static arena.
[ArenaMethods.c](https://github.com/Hossin-Azmoud/Arena/blob/main/src/Arena.h): arena methods like initializers, allocators and deallocators.

## Funcs
### Initializers
```c
// Creates a new arena with `cap` as an initiall capacity.
Arena *new_arena(size_t cap);
// initializer for the global static arena.
void arena_init();
```
### Allocators

```c
// allocate `byte_count` from the global static arena.
unsigned char *allocate(size_t byte_count);
// allocates `byte_count` from the arena (A)
unsigned char *arena_alloc(Arena *A, size_t byte_count);
```
## Deallocators
```c
// Frees an arena (A).
void arena_free(Arena *A);
// Frees the global arena.
void arena_deallocate();
```
