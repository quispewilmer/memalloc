#include <memalloc.h>

typedef struct header {
    int is_free;
    size_t size;
    struct header *next;
} header_t;

#define HEADER_SIZE         sizeof(struct header)
#define BRK_ERROR           -1
#define MIN_SIZE            8

static header_t *head = NULL;

header_t *
find_free_block (size_t size) 
{
    header_t *h = head;
    while (h != NULL) {
        if (size <= (h->size + HEADER_SIZE) && h->is_free) {
            return h;
        }
        h = h->next;
    }
    return NULL;
}

header_t *
more_memory (size_t size) 
{
    header_t *h = (header_t *) sbrk(size);
    if (h == (void *) BRK_ERROR) {
        return 0;
    }
    return h;
}

void * 
malloc (size_t size) 
{
    header_t *h;
    /* Sanitize in case of useless size */
    if ((int) size < 0)
        goto err;
    size += HEADER_SIZE;
    if (!head) {
        h = more_memory(size);
        h->is_free = 0;
        h->size = size;
        h->next = NULL;
        head = h;
        return h;
    }
    h = find_free_block(size);
    if (h == NULL)
        h = more_memory(size);
    return h;

    err:
        return NULL;
}

void
free (void *addr)
{
    assert(brk(addr) != BRK_ERROR);
    
    return ;
}