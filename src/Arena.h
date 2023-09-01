#ifndef ARENA_H
#define ARENA_H
#include <stdio.h>
#include <stdlib.h>
#define ARENA_SIZE 64000
typedef enum ArenaAction {
	INIT,
	FREE,
	ALLOC
} ArenaAction;

typedef struct arena {
	void   *_mem;
	size_t cursor;
	size_t _cap;
} Arena;

void arena_init();
void *arena_station(ArenaAction a, size_t byte_count);
void *allocate(size_t byte_count);
void arena_deallocate();

#endif // ARENA_H
