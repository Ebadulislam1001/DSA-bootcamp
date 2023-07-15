// 003 Pointer Arithematics
#include <iostream>
using namespace std;

int main()
{
    char c_var;
    char *c_ptr = &c_var;

    int i_var;
    int *i_ptr = &i_var;

    double d_var;
    double *d_ptr = &d_var;

    // printing values of c_ptr
    for (int i = 0; i < 5; i++)
    {
        printf("\nvalue of c_ptr => %d", c_ptr);
        c_ptr = c_ptr + 1;
    }
    printf("\n");
    // printing values of i_ptr
    for (int i = 0; i < 5; i++)
    {
        printf("\nvalue of i_ptr => %d", i_ptr);
        i_ptr = i_ptr + 1;
    }
    printf("\n");
    // printing values of i_ptr
    for (int i = 0; i < 5; i++)
    {
        printf("\nvalue of d_ptr => %d", d_ptr);
        d_ptr = d_ptr + 1;
    }
    printf("\n\n");

    // Using %d specifier to print the address in base-10 int for easy understanding
    return 0;
}
