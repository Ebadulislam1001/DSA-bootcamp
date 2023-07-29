// 007 Structure Padding
#include <iostream>
using namespace std;

// Creating a struct is basically creating a user defined data type, that is composed of the fundamental data types.
struct type1
{
    char x;
    char y;
    int i;
    double d;
};
struct type2
{
    char x;
    double d;
    char y;
    int i;
};
struct type3
{
    char x;
    int i;
    char y;
    double d;
};

int main()
{
    // Declaring variables of these struct types
    type1 var1;
    type2 var2;
    type3 var3;

    // Finding the sizes of these struct
    printf("\nsizeof type1 struct    = %d", sizeof(type1));
    printf("\nsizeof type2 struct    = %d", sizeof(type2));
    printf("\nsizeof type3 struct    = %d", sizeof(type3));

    // The size of a struct is not always equal to the sum of the sizes of its members. This is because the compiler may add padding to the struct to ensure that its members are aligned on a word boundary. Word boundaries are important for performance, as they allow the CPU to access data more efficiently. The amount of padding added to a struct is implementation-defined. This means that the amount of padding may vary depending on the compiler and the platform.
    // In easier words padding makes sure that every int variable has an address that is a multiple of 4, and every double variable has an address that is a multiple of 8, to ensure that variables of same data type are aligned with each other.

    // Lets see why these structures take different memory despite having same type of variable members (just in different order)
    printf("\n\n\nAddress of type1 variable var 1 = &var1 = %d", &var1);
    printf("\n\taddress of var1.x = %d", &var1.x);
    printf("\n\taddress of var1.y = %d", &var1.y);
    printf("\n\taddress of var1.i = %d", &var1.i);
    printf("\n\taddress of var1.d = %d", &var1.d);
    printf("\nNext address after var1     = &var1 + 1 = %d", &var1 + 1);
    printf("\n\n\nAddress of type2 variable var 2 = &var2 = %d", &var2);
    printf("\n\taddress of var2.x = %d", &var2.x);
    printf("\n\taddress of var2.d = %d", &var2.d);
    printf("\n\taddress of var2.y = %d", &var2.y);
    printf("\n\taddress of var2.i = %d", &var2.i);
    printf("\nNext address after var2     = &var2 + 1 = %d", &var2 + 1);
    printf("\n\n\nAddress of type3 variable var 3 = &var3 = %d", &var3);
    printf("\n\taddress of var3.x = %d", &var3.x);
    printf("\n\taddress of var3.i = %d", &var3.i);
    printf("\n\taddress of var3.y = %d", &var3.y);
    printf("\n\taddress of var3.d = %d", &var3.d);
    printf("\nNext address after var3     = &var3 + 1 = %d", &var3 + 1);

    // Lets Visualise how these different members of these structures are spread among the allocated memory
    printf("\n\n");
    printf("\nMEMORY       : |0 1 2 3 4 5 6 7|8 9 A B C D E F|0 1 2 3 4 5 6 7|8 9 A B C D E F|\n");
    printf("\ntype1 (16 B) : |x y - - i i i i|d d d d d d d d|");
    printf("\ntype2 (24 B) : |x - - - - - - -|d d d d d d d d|y - - - i i i i|");
    printf("\ntype3 (24 B) : |x - - - i i i i|y - - - - - - -|d d d d d d d d|");

    printf("\n\n");
    // Using %d specifier to print the address in base-10 int for easy understanding
    return 0;
}
