#include "Arena.h"

typedef struct Point {
	int x, y;
} Point;

int main()
{
	arena_init();
	{
		// 1. for strings
		char *str = (char *) allocate(20);
		strcpy(str, "Hello, world!\n");

		// 2. for other structures.
		Point *p = (Point *) allocate(sizeof(Point));
		p->x     = 69;
		p->y     = 96;

		// 3. 2D array structures
		char **tokens = (char **)allocate(sizeof(char *) * 10); // allocates 10 char arrays.
		
		for (int k = 0; k < 9; ++k) {
			tokens[k] = allocate(10);
			tokens[k] = strcpy(tokens[k], ".........");
		}

		for (int k = 0; k < 9; ++k){
			printf(
				"[%p] [%i] %s\n",
				(tokens[k]),
				(k),
				(tokens[k])
			);
		}

		// printing.
		printf("%s", str);
		printf("(%i, %i)\n", p->x, p->y);
	}

	// NOTE: I don't need to free alot of things, only the arena.
	arena_deallocate();
	return 0;
}
