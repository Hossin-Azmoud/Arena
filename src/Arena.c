#include "Arena.h"

void *arena_station(ArenaAction a, size_t byte_count)
{
	static Arena *(A) = NULL;
	void *temp_ptr;

	switch (a) {
		case INIT: {
			A = malloc(sizeof(Arena));
			(A)->_mem = malloc(ARENA_SIZE);
			(A)->cursor = 0;
			(A)->_cap = ARENA_SIZE;
		} break;
		case FREE: {
			free(A->_mem);
			free(A);
		} break;
		case ALLOC: {
			if (A->cursor + byte_count < A->_cap) {
				temp_ptr   = (A)->_mem + A->cursor;
				A->cursor += byte_count;
				return temp_ptr;
			}

			return NULL;
		} break;
		default: {
			printf("This is unreachable.!\n");
		}
	}

	return NULL;
}

void *allocate(size_t byte_count)
{
	return arena_station(ALLOC, byte_count);
}

void arena_deallocate()
{
	arena_station(FREE, 0);
}

void arena_init()
{
	arena_station(INIT, 0);
}

