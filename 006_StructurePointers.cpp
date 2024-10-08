// 006 Structure Pointers
#include <iostream>
using namespace std;

// Creating a struct is basically creating a user defined data type, that is composed of the fundamental data types.
struct student
{
    int std;
    char sec;
    double num;
};

int main()
{
    struct student str_var1; // This is how you declare in C, also works fine in cpp
    student str_var;         // This declaration wont work in C, but works fine in cpp

    // Different ways of finding the size of your struct
    printf("\nsizeof(student)    = %d", sizeof(student));
    printf("\nsizeof(str_var)    = %d", sizeof(str_var));

    // Finding the size of your struct using pointer arithematic
    student *str_ptr = &str_var;
    printf("\n\nsize of struct     = %d", (long long)(str_ptr + 1) - (long long)(str_ptr));
    printf("\n\tstr_ptr    = %d", str_ptr);
    printf("\n\tstr_ptr+1  = %d\n", str_ptr + 1);

    // The size of a struct is not always equal to the sum of the sizes of its members. This is because the compiler may add padding to the struct to ensure that its members are aligned on a word boundary. Word boundaries are important for performance, as they allow the CPU to access data more efficiently. The amount of padding added to a struct is implementation-defined. This means that the amount of padding may vary depending on the compiler and the platform.

    // Initializing the members of the struct using variable name and . dot operator
    str_var.std = 11;
    str_var.sec = 'A';
    str_var.num = 2.71;

    // Accessing the members of the struct using variable name and . dot operator
    printf("\nAccessing the members of the struct using variable name and . dot operator");
    printf("\nstd\t\tsec\t\tnum");
    printf("\n%d\t\t%c\t\t%.2f", str_var.std, str_var.sec, str_var.num);

    // Initializing the members of the struct using a pointer and -> arrow operator
    str_ptr->std = 12;
    str_ptr->sec = 'B';
    str_ptr->num = 3.14;

    // Accessing the members of the struct using a pointer and -> arrow operator
    printf("\nAccessing the members of the struct using a pointer and -> arrow operator");
    printf("\nstd\t\tsec\t\tnum");
    printf("\n%d\t\t%c\t\t%.2f", str_ptr->std, str_ptr->sec, str_ptr->num);

    printf("\n");
    // Getting the address of members of the struct
    printf("\nGetting the address of the members of the struct");
    printf("\n&str_var.std (int)    = %d = %d", &(str_var.std), &(str_ptr->std));
    printf("\n&str_var.sec (char)   = %d = %d", &(str_var.sec), &(str_ptr->sec));
    printf("\n&str_var.num (double) = %d = %d", &(str_var.num), &(str_ptr->num));

    printf("\n\n");
    // Using %d specifier to print the address in base-10 int for easy understanding
    return 0;
}
