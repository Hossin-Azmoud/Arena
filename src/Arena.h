#ifndef ARENA_H
#define ARENA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NOTE: A private structure to allocate memory with.
typedef struct arena {
	unsigned char *_mem;
	size_t _cap;
	size_t cursor;
} Arena;


void          arena_free(Arena *A);
Arena         *new_arena(size_t cap);
void          arena_init();
unsigned char *allocate(size_t byte_count);
void           arena_deallocate();
unsigned char *arena_alloc(Arena *A, size_t byte_count);

#endif // ARENA_H
