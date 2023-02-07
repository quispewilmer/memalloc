#include <memalloc.h>

typedef struct header {
    size_t size;
    int is_free;
    header_t *next;
} header_t;

#define HEADER_SIZE         sizeof(struct header);
#define BRK_ERROR           -1
#define MIN_SIZE            8

static header_t *head = NULL;

void *
more_memory (size_t size) 
{

}

void * 
malloc (size_t size) 
{
    /* Sanitize in case of useless size */
    if ((int) size < 0)
        goto err;

    size += HEADER_SIZE;
    head = find_free_block(size);
    if (!head) {
        
    }

    err:
        return NULL;
}

void
free (void *addr)
{
    assert(brk(addr) != BRK_ERROR);
    
    return ;
}