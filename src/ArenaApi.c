#include "Arena.h"

#define INIT 0
#define FREE -1
#define ARENA_SIZE 640000 /* initialization memory. */

static unsigned char *s_arena_station(ssize_t byte_count)
{
	static Arena   *(A) = NULL;

	switch (byte_count) {
		case INIT: {
			A = new_arena(ARENA_SIZE);
		} break;
		case FREE: {
			arena_free(A);
		} break;
		default: {
			return (arena_alloc(A, byte_count));
		}
	}
	return NULL;
}


void *allocate(size_t byte_count)
{
	return s_arena_station(byte_count);
}

void arena_deallocate()
{
	s_arena_station(FREE);
}

void arena_init()
{
	s_arena_station(INIT);
}
