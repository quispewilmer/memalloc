#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

void *_memalloc_malloc (size_t);
void _memalloc_free (void *);

/// @brief Returns a pointer that points where the program break is.
/// @param param_1 Quantity of bytes for which the program break will be moved
/// @return A void pointer that points the start of program break
#define malloc _memalloc_malloc

/// @brief Frees memory displaying the program counter.
/// @param param_1 Pointer to which the program break will go
#define free _memalloc_free