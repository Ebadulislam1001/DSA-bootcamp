// 008 Dynamic Memory Allocation
#include <iostream>
using namespace std;

int main()
{
    // In C, we use "malloc()", "calloc()", "realloc()", and "free()"
    // In C++, we can use all these as well as "new" and "delete"

    // These are the examples of static memory allocation
    printf("\n\nExamples of statically allocated memory/variable.\n");
    int var = 12;
    int *ptr = &var;

    // Lets see the use of "malloc()", "calloc()", "realloc()", and "free()".

    // MALLOC
    // malloc() function takes the size (in bytes) as an argument and returns a void pointer pointing to a memory block of the requested size.
    // If a memory block of requested size cannont be allocated, it returns a NULL pointer.
    // Before using, you need to typecast the returned void pointer to the required type.
    // Suitable for allocating memory for primitive types and structures.

    printf("\n\nUsing malloc() to allocate memory for an integer variable.");
    // This allocates a memory block equal to the size of int.
    ptr = (int *)malloc(sizeof(int));

    *ptr = 23;
    printf("\n\t*ptr = %d", *ptr);

    printf("\n\nUsing malloc() to allocate memory for an integer array.");
    // This allocates a memory blocks equal to thrice the size of int, i.e. an integer array of 3 elements.
    ptr = (int *)malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = ptr[i] = 2 * i + 1;
        printf("\n\t*(ptr+i) = %d\t\tptr[i] = %d", *(ptr + i), ptr[i]);
    }

    // CALLOC
    // calloc() function takes two arguments, an integer 'n' and a size (in bytes).
    // It allocates 'n' consecutive memory blocks of the requested size and returns a void pointer pointing to the first block.
    // Subsequent blocks can be accessed by incrementing the pointer.
    // If 'n' memory blocks of requested size cannont be allocated, it returns a NULL pointer.
    // Before using, you need to typecast the returned void pointer to the required type.
    // Suitable for allocating memory for arrays.

    printf("\n\nUsing calloc() to allocate memory for an integer variable.");
    // This allocates a memory block equal to the size of int.
    ptr = (int *)calloc(1, sizeof(int));

    *ptr = 23;
    printf("\n\t*ptr = %d", *ptr);

    printf("\n\nUsing calloc() to allocate memory for an integer array.");
    // This allocates 3 memory blocks each equal to the size of int, i.e. an integer array of 3 elements.
    ptr = (int *)calloc(3, sizeof(int));

    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = ptr[i] = 2 * i + 1;
        printf("\n\t*(ptr+i) = %d\t\tptr[i] = %d", *(ptr + i), ptr[i]);
    }

    // REALLOC
    // realloc() function takes a pointer to the old allocated memory block, and a new size as arguments
    // and returns a void pointer pointing to a new allocated memory block of the requested new size.
    // The contents of the newly allocated memory block is identical to that of the old allocated memory block prior to reallocation, up to the lesser of the new and old sizes.
    // Any bytes in the new allocated memory block beyond the size of the old allocated memory block have indeterminate values.
    // If a memory block of requested size cannont be allocated, it returns a NULL pointer.
    // Before using, you need to typecast the returned void pointer to the required type.
    // Suitable for scaling the size of dynamically allocated arrays.

    printf("\n\nUsing realloc() to scale the size of the allocated integer array.");

    // Note: that ptr is a pointer to an integer array of 3 elements with values {1, 3, 5}.
    // This allocates 5 memory blocks equal to the size of int, i.e. an integer array of 5 elements.
    ptr = (int *)realloc(ptr, 5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        // Lets see the default values that we get after reallocation.
        printf("\n\t*(ptr+i) = %8d\t\tptr[i] = %8d", *(ptr + i), ptr[i]);
    }

    // FREE
    // free() function is used to free or deallocate the dynamically allocated memory.
    // It is a good practice to free the dynamically allocated memory after using it to prevent memory leakage.

    printf("\n\nUsing free() to deallocate memory we allocated so far.");
    free(ptr);
    printf("\nMemory deallocated successfully.");

    // ***TIP***
    // To allocate an integer array of size 'n' using malloc()
    // int *arr = (int *)malloc(n * sizeof(int));
    // To allocate an integer array of size 'n' using calloc()
    // int *arr = (int *)calloc(n, sizeof(int));

    // Now, Lets see the use of "new" and "delete" (not avaiailable in C).
    // It is preferred to learn these while learning OOP in C++.

    // NEW
    // new keyword allocates memory equal to the size of the provided data type and returns a pointer pointing to that memory
    // pointer = new dataType; // to allocate a single variable
    printf("\n\nUsing new to allocate memory for an integer variable.\n");
    ptr = new int;
    *ptr = 34;
    printf("\n\t*ptr = %d", *ptr);
    // pointer = new dataType[]; // to allocate an array of variables
    printf("\n\nUsing new to allocate memory for an integer array.\n");
    ptr = new int[3];
    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = ptr[i] = 2 * i + 1;
        printf("\n\t*(ptr+i) = %d\t\tptr[i] = %d", *(ptr + i), ptr[i]);
    }

    // DELETE
    // delete keyword is used to deallocate dynamically allocated memory.
    // delete pointer; // to delete a single variable
    printf("\n\nUsing delete to deallocate memory allocated for integer array.\n");
    delete ptr;
    printf("\n\t*ptr = %d", *ptr);
    // delete[] pointer; // to delete an array of variables
    printf("\n\nUsing delete to deallocate memory allocated for integer array.\n");
    delete ptr;
    for (int i = 0; i < 3; i++)
    {
        *(ptr + i) = ptr[i] = 2 * i + 1;
        printf("\n\t*(ptr+i) = %d\t\tptr[i] = %d", *(ptr + i), ptr[i]);
    }

    // ***NOTE***
    // reallocate function can only be used to reallocate the memory which was allocated dynamically.
    // free function can only be used to deallocate the memory which was allocated dynamically.
    // delete keyword can only be used to deallocate the memory which was allocated dynamically.
    // If the memory is not dynamically allocated, then behavior is undefined.

    printf("\n\n");
    return 0;
}
