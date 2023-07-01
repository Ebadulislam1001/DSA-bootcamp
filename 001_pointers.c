// 001_Pointers
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // variable of type int
    int a = 11;
    // pointing to a variable of type int
    int *p = &a;
    // pointer pointing to a pointer pointing to a variable of type int
    int **q = &p;

    // printing the value stored in the variable
    printf("\n   a = %d", a);
    printf("\n  *p = %d", *p);
    printf("\n **q = %d", **q);
    printf("\n");
    // printing the address of the variable
    printf("\n &a = %d, &a = %p, &a = %x", &a, &a, &a);
    printf("\n  p = %d,  p = %p,  p = %x", p, p, p);
    printf("\n *q = %d, *q = %p, *q = %x", *q, *q, *q);
    printf("\n");
    // printing the address of the pointer
    printf("\n &p = %d, &p = %p, &p = %x", &p, &p, &p);
    printf("\n  q = %d,  q = %p,  q = %x", q, q, q);
    printf("\n");
    return 0;
}