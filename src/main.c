#include "Arena.h"

int main()
{

	arena_init();

	{
		// 1. for strings
		char *str = (char *) allocate(15);
		strcpy(str, "Hello, world!\n");

		// printing.
		printf("%s", str);
	}

	// NOTE: I don't need to free alot of things, only the arena.
	arena_deallocate();
	return 0;
}
