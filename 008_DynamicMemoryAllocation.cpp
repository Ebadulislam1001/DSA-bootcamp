// 008 Dynamic Memory Allocation
#include <iostream>
using namespace std;

int main()
{
    // In C, we use "malloc()", "calloc()", "realloc()", and "free()"
    // In C++, we can use all these as well as "new" and "delete"

    // These are the examples of static memory allocation
    printf("\n\nExamples of statically allocated memory/variable.\n");
    int i_var = 12;
    int *i_ptr = &i_var;
    int *a_ptr = NULL;

    // Lets see the use of "malloc()", "calloc()", "realloc()", and "free()".

    // MALLOC
    // malloc() function takes a size as an argument and returns a void pointer pointing to a memory block of the requested size.
    // Before using, you need to typecast the returned void pointer to the required type.
    // Suitable for allocating memory for primitive types and structures.
    printf("\n\nUsing malloc() to allocate memory for an integer variable.\n");
    // struct student* ptr = (struct student*) malloc (sizeof(struct student)); (syntax for C)
    i_ptr = (int *)malloc(sizeof(int));
    // This allocates a memory block equal to the size of int.
    *i_ptr = 23;
    printf("\n\t*i_ptr = %d", *i_ptr);

    // CALLOC
    // calloc() function takes an integer n, and a size as arguments and returns a void pointer pointing to 'n' consecutive memory blocks of the requested size.
    // Before using, you need to typecast the returned void pointer to the required type.
    // To access each individual block, use pointer arithermatics, where "ptr+1" gives the address of the next block of the requested size.
    // Suitable for allocating memory for arrays.
    printf("\n\nUsing calloc() to allocate memory for an integer array.\n");
    // struct student* ptr = (struct student*) calloc (n, sizeof(struct student)); (syntax for C)
    a_ptr = (int *)calloc(3, sizeof(int));
    // This allocates 3 memory blocks equal to the size of int, i.e. an integer array of 3 elements.
    for (int i = 0; i < 3; i++)
    {
        *(a_ptr + i) = a_ptr[i] = 2 * i + 1;
        printf("\n\t*(a_ptr+i) = %d\t\ta_ptr[i] = %d", *(a_ptr + i), a_ptr[i]);
    }

    // REALLOC
    // realloc() function takes a pointer to the old object, and a new size as arguments and returns a void pointer pointing to a new object of the requested new size.
    // The contents of the new object is identical to that of the old object prior to reallocation, up to the lesser of the new and old sizes.
    // Any bytes in the new object beyond the size of the old object have indeterminate values.
    // Before using, you need to typecast the returned void pointer to the required type.
    // Suitable for scaling the size of dynamically allocated arrays.
    // Suitable for allocating memory for arrays.
    printf("\n\nUsing realloc() to scale the size of the allocated integer array.\n");
    // struct student* new_ptr = (struct student*) reaalloc (old_ptr, sizeof(struct student)); (syntax for C)
    a_ptr = (int *)realloc(a_ptr, 5 * sizeof(int));
    // This allocates 5 memory blocks equal to the size of int, i.e. an integer array of 5 elements.
    for (int i = 0; i < 5; i++)
    {
        *(a_ptr + i) = a_ptr[i] = 2 * i + 1;
        printf("\n\t*(a_ptr+i) = %d\t\ta_ptr[i] = %d", *(a_ptr + i), a_ptr[i]);
    }

    // FREE
    // free() function is used to free or deallocate the dynamically allocated memory.
    // It helps in reducing memory wastage.
    printf("\n\nUsing free() to deallocated memory we allocated so far.\n");
    free(i_ptr);
    printf("\n\t*i_ptr = %d", *i_ptr);
    free(a_ptr);
    for (int i = 0; i < 5; i++)
    {
        *(a_ptr + i) = a_ptr[i] = 2 * i + 1;
        printf("\n\t*(a_ptr+i) = %d\t\ta_ptr[i] = %d", *(a_ptr + i), a_ptr[i]);
    }

    // ***TIP***
    // To allocate an integer array of size 'n' using calloc()
    // int *arr = (int *)calloc(n, sizeof(int));
    // To allocate an integer array of size 'n' using calloc()
    // int *arr = (int *)calloc(n * sizeof(int));

    // Now, Lets see the use of "new" and "delete" (not avaiailable in C).

    // NEW
    // new keyword allocates memory equal to the size of the provided data type and returns a pointer pointing to that memory
    // pointer = new dataType; // to allocate a single variable
    printf("\n\nUsing new to allocate memory for an integer variable.\n");
    i_ptr = new int;
    *i_ptr = 34;
    printf("\n\t*i_ptr = %d", *i_ptr);
    // pointer = new dataType[]; // to allocate an array of variables
    printf("\n\nUsing new to allocate memory for an integer array.\n");
    a_ptr = new int[3];
    for (int i = 0; i < 3; i++)
    {
        *(a_ptr + i) = a_ptr[i] = 2 * i + 1;
        printf("\n\t*(a_ptr+i) = %d\t\ta_ptr[i] = %d", *(a_ptr + i), a_ptr[i]);
    }

    // DELETE
    // delete keyword is used to deallocate dynamically allocated memory.
    // delete pointer; // to delete a single variable
    printf("\n\nUsing delete to deallocate memory allocated for integer array.\n");
    delete i_ptr;
    printf("\n\t*i_ptr = %d", *i_ptr);
    // delete[] pointer; // to delete an array of variables
    printf("\n\nUsing delete to deallocate memory allocated for integer array.\n");
    delete a_ptr;
    for (int i = 0; i < 3; i++)
    {
        *(a_ptr + i) = a_ptr[i] = 2 * i + 1;
        printf("\n\t*(a_ptr+i) = %d\t\ta_ptr[i] = %d", *(a_ptr + i), a_ptr[i]);
    }

    // ***NOTE***
    // reallocate function can only be used to reallocate the memory which was allocated dynamically.
    // free function can only be used to deallocate the memory which was allocated dynamically.
    // delete keyword can only be used to deallocate the memory which was allocated dynamically.
    // If the memory is not dynamically allocated, then behavior is undefined.

    printf("\n\n");
    return 0;
}
