#include <memalloc.h>

typedef struct header {
    size_t size;
    bool is_free;
    header_t *next;
} header_t;

#define HEADER_SIZE     sizeof(struct header)
#define MIN_SIZE        8

void *
malloc (size_t size) 
{
    /* Sanitize in case of useless size */
    if ((int) size < 0)
        goto err;

    err:
        return NULL;
}