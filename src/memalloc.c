#include <memalloc.h>

void *
malloc (size_t size) 
{
    /* Sanitize in case of useless size */
    if ((int) size < 0)
        goto err;

    void *actual = sbrk(0);
    void *request = sbrk(size);
    if (request == (void *) -1)
        goto err;
    assert(actual == request); /* Test only */

    return request;

    err:
        return NULL;
}

void
free (void *p)
{
    brk(p);
    
    return ;
}