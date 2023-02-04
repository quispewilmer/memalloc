#include <memalloc.h>
#include <stdio.h>

int main() {
    printf("PID is: %d\n", getppid());
    void *p = malloc(2);
    printf("The program brk is on: %p\n", sbrk(0));
    free(p);
    printf("The program brk is on: %p\n", sbrk(0));
    
    return EXIT_SUCCESS;
}