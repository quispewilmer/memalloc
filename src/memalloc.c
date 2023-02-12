#include <memalloc.h>

typedef struct header {
    int is_free;
    size_t size;
    struct header *next;
} header_t;

#define HEADER_SIZE sizeof(struct header)
#define BRK_ERROR -1
#define MIN_SIZE 8

static header_t *head = NULL;

header_t *
find_free_block (size_t size) 
{
    header_t *h = head;
    while (h != NULL) {
        if (size <= (h->size + HEADER_SIZE) && h->is_free)
            return h;
        h = h->next;
    }
    return NULL;
}

void *
more_memory (size_t size) 
{
    void *req = sbrk(size);
    if (req == (void *) BRK_ERROR)
        return NULL;
    return req;
}

void * 
malloc (size_t size) 
{
    header_t *h;
    /* Sanitize in case of useless size */
    if ((int) size < 0)
        goto err;
    size += HEADER_SIZE;
    h = find_free_block(size - HEADER_SIZE);
    if (h == NULL) {
        h = (header_t *) more_memory(size);
        if (h == NULL)
            goto err;
        h->is_free = 0;
        h->size = size - HEADER_SIZE;
        h->next = head;
        head = h;
    }
    h->is_free = 0;
    return h;

    err:
        return NULL;
}

void
free (void *ptr) 
{
    if (!ptr)
        return ;
    header_t *h = (header_t *) ptr;
    h->is_free = 1;
    return ;
}

void *
realloc (void *ptr, size_t size) 
{
    header_t *new_ptr, *old_ptr;
    if (!ptr)
        return malloc(size);
    new_ptr = (header_t *) malloc(size);
    old_ptr = (header_t *) ptr;
    size_t old_size = old_ptr->size;
    if (new_ptr) {
        memcpy(new_ptr, old_ptr, size < old_size ? size : old_size);
        new_ptr->is_free = 0;
        new_ptr->size = size;
    }
    if (new_ptr || size == 0)
        free(old_ptr);
    return new_ptr;

    err:
        return NULL;
}