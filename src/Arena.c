#include "Arena.h"
#define INIT 0
#define FREE -1
static void *s_arena_station(ssize_t byte_count)
{
	static Arena *(A) = NULL;
	void *temp_ptr;
	
	switch (byte_count) {
		case INIT: {
			A = malloc(sizeof(Arena));
			(A)->_mem = malloc(ARENA_SIZE);
			memset((A)->_mem, 0, ARENA_SIZE);
			(A)->cursor = 0;
			(A)->_cap = ARENA_SIZE;
		} break;
		case FREE: {
			printf("MEM_LOG: \n");
			for (int k = 0; k < (A)->cursor; ++k) {
				printf("[%i][%p][%i]\n", k, ((A)->_mem + k), *(char*)((A)->_mem + k));
			}
			free(A->_mem);
			free(A);
		} break;
		default: {
			if (A->cursor + byte_count < A->_cap) {
				temp_ptr   = (A)->_mem + A->cursor;
				A->cursor += byte_count;
				return temp_ptr;
			}
			return NULL;
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
