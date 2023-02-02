#include <stdlib.h>
#include <stdbool.h>

void *_memalloc_malloc (size_t);

#define malloc _memalloc_malloc