#include <memalloc.h>

#define BRK_ERROR (int) -1

void *
malloc (size_t size) 
{
    /* Sanitize in case of useless size */
    if ((int) size < 0)
        goto err;

    void *actual = sbrk(0);
    void *request = sbrk(size);
    if (request == (void *) BRK_ERROR)
        goto err;
    assert(actual == request); /* Test only */

    return request;

    err:
        return NULL;
}

void
free (void *addr)
{
    assert(brk(addr) != BRK_ERROR);
    
    return ;
}