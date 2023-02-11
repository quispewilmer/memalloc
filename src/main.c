#include <stdio.h>
#include <stdlib.h>
#include <memalloc.h>

int main() {
    printf("PID is: %d\n", getppid());
    void *p1 = malloc(8);
    printf("The program brk is on: %p\n", sbrk(0));
    void *p2 = malloc(10);
    printf("The program brk is on: %p\n", sbrk(0));
    void *p3 = malloc(10);
    printf("The program brk is on: %p\n", sbrk(0));
    
    return EXIT_SUCCESS;
}