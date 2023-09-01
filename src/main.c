#include "Arena.h"
#include <string.h>
int main()
{
	arena_init();
	char *str = (char *)allocate(20);
	strcpy(str, "Hello, world!\n");
	printf("%s", str);
	arena_deallocate();
	return 0;
}
