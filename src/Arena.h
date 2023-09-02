#ifndef ARENA_H
#define ARENA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARENA_SIZE 64000
typedef struct arena {
	void   *_mem;
	size_t _cap;
	size_t cursor;
} Arena;

void arena_init();
void *allocate(size_t byte_count);
void arena_deallocate();

#endif // ARENA_H
