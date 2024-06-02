// 001 Pointers
#include <iostream>
using namespace std;

int main()
{
    // Like other variables, pointers are also variables
    // int variables store numbers
    // char variables store characters
    // pointer variables store addresses of other variables

    // NOTE: pointer is not a data type though.
    // data type of a pointer variable depends upon the type of the variable whose address it stores
    // eg: a pointer pointing to an `char` type variable is of the type `char*`
    // eg: a pointer pointing to an `int` type variable is of the type `int*`
    // eg: a pointer pointing to an `int*` type variable is of the type `int**`
    
    // A variable of type int
    int a = 24;
    // A pointer pointing to a variable of type int
    int *p = &a;
    // A pointer pointing to a pointer pointing to a variable of type int
    int **q = &p;

    // Read `&` as `address of`. It is used to get the address of a variable (of any type incl pointers).
    // Read `*` as `value at`.   It is used to get the value at the address pointed by a pointer.

    printf("\nprinting the value stored in the variable\n\n");
    printf("\t  a = %d\n", a);
    printf("\t *p = %d\n", *p);
    printf("\t**q = %d\n", **q);

    printf("\nprinting the address of the variable\n\n");
    printf("\t &a = %d, &a = %x\n", &a, &a);
    printf("\t  p = %d,  p = %x\n", p, p);
    printf("\t *q = %d, *q = %x\n", *q, *q);
    
    printf("\nprinting the address of the pointer\n\n");
    printf("\t &p = %d, &p = %x\n", &p, &p);
    printf("\t  q = %d,  q = %x\n", q, q);
    printf("\n\n");
    
    // %d is used to print the address in decimal format (base-10)
    // %x is used to print the address in hexadec format (base-16)
    // follow up: what is default format if you use `cout` to print the address, decimal or hexadec ?
    return 0;
}