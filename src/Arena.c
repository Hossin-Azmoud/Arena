#include "Arena.h"

#define INIT 0
#define FREE -1
#define ARENA_SIZE 640000 /* initialization memory. */

// NOTE: A private structure to allocate memory with.
typedef struct arena {
	unsigned char *_mem;
	size_t _cap;
	size_t cursor;
} Arena;

Arena *new_arena()
{
	Arena *A           = malloc(sizeof(Arena));
	
	(A)->_mem   = malloc(ARENA_SIZE);
	(A)->cursor = 0;
	(A)->_cap   = ARENA_SIZE;
	memset((A)->_mem, 0, ARENA_SIZE);

	return A;
}

static void *s_arena_station(ssize_t byte_count)
{
	static Arena   *(A) = NULL;
	void *temp_ptr;

	switch (byte_count) {
		case INIT: {
			A = new_arena();
		} break;
		case FREE: {
			printf("MEM_LOG: Window (1 byte)\n");
			for (int k = 0; k < (A)->cursor; ++k) {
				printf("[%i][%p][%i]\n", k, ((A)->_mem + k), *(char*)((A)->_mem + k));
			}
			printf("UNUSED MEM   %li\n", (A)->_cap - (A)->cursor);
			printf("CURSOR       %li\n", (A)->cursor);
			free(A->_mem);
			free(A);
		} break;
		default: {
			if (A->cursor + byte_count < A->_cap) {
				temp_ptr   = (A)->_mem + A->cursor;
				A->cursor += byte_count;
				return temp_ptr;
			}

			fprintf(stderr, "FAILED TO ALLOCATE MEMORY IN ARENA SO WE WILL ALLOCATE FROM OTHER PLACE\n");
			return (malloc(byte_count));
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
