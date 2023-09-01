#include "Arena.h"
#include <string.h>

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
		p->x = 69;
		p->y = 96;
		// printing.
		printf("%s", str);
		printf("(%i, %i)\n", p->x, p->y);
	}
	// NOTE: I don't need to free alot of things, only the arena.
	arena_deallocate();
	return 0;
}
