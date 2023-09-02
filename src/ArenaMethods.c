#include "Arena.h"

Arena *new_arena(size_t cap)
{
	Arena *A    = malloc(sizeof(Arena));
	(A)->_mem   = calloc(cap, sizeof(unsigned char));
	(A)->cursor = 0;
	(A)->_cap   = cap;
	return A;
}

void arena_free(Arena *A)
{
	free(A->_mem);
	free(A);
}

unsigned char *arena_alloc(Arena *A, size_t byte_count)
{
	void *temp_ptr;

	if (A->cursor + byte_count < A->_cap) {
		temp_ptr   = (A)->_mem + A->cursor;
		A->cursor += byte_count;
		return temp_ptr;
	}

	fprintf(stderr, "FAILED TO ALLOCATE MEMORY IN ARENA SO WE WILL ALLOCATE FROM OTHER PLACE\n");
	return (calloc(byte_count, sizeof(unsigned char))); // Needs a way to be freed :/
}
