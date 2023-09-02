#ifndef ARENA_H
#define ARENA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arena Arena;
Arena *new_arena();
void   arena_init();
void  *allocate(size_t byte_count);
void   arena_deallocate();

#endif // ARENA_H
