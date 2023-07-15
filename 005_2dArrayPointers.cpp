// 005 2D Array Pointers and Pointer Arithematics
#include <iostream>
using namespace std;

int main()
{
    int nums[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *ptr;
    // ptr is integer pointer i.e. it points to integer element.
    // Doing ptr = nums is wrong because 'nums' contains address of its first element
    // i.e. the first subarray nums[0] / the first row / an integer array of size 3.
    // But ptr can only store the address of an int variable and not an int array.
    // However this syntax is correct in 1-D array, because their first element is an int variable
    // some correct syntaxes to store the address of first int element of a 2-D array are as follows

    // these are some valid assignments to ptr, and all of these have the same meaning.
    ptr = *nums;
    ptr = nums[0];
    ptr = &nums[0][0];
    // we will use ptr

    // printing addresses of the array / a 2D array
    printf("\nAddress of the 2D array");
    printf("\n&arr         = %d", &nums);
    printf("\nAddress of the 2-D array + 1");
    printf("\n&arr+1       = %d", &nums + 1);
    printf("\n");
    // printing addresses of the subarray / a 1D array
    printf("\nAddress of the first subarray");
    printf("\n&arr[0]      = %d", &nums[0]);
    printf("\nAddress of the first subarray + 1");
    printf("\n&arr[0]+1    = %d", &nums[0] + 1);
    printf("\n");
    // printing addresses of the element / an int element
    printf("\nAddress of the first int element");
    printf("\n&arr[0][0]   = %d", &nums[0][0]);
    printf("\nAddress of the first element + 1");
    printf("\n&arr[0][0]+1 = %d", &nums[0][0] + 1);
    printf("\n");

    //  diferent ways to print the address of elements
    printf("\nPrinting the addresses of subarrays using &nums[i] \n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %d ", &nums[i]);
        printf("\n");
    }
    printf("\nPrinting the addresses of subarrays using nums+i \n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %d ", nums + i);
        printf("\n");
    }

    //  diferent ways to print the address of elements
    printf("\nPrinting the addresses of elements using &nums[i][j] \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", &nums[i][j]);
        }
        printf("\n");
    }
    printf("\nPrinting the addresses of elements using nums[i]+j \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", nums[i] + j);
        }
        printf("\n");
    }
    printf("\nPrinting the addresses of elements using *(nums+i)+j \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(nums + i) + j);
        }
        printf("\n");
    }
    printf("\nPrinting the addresses of elements using B+((i*C)+j) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", ptr + ((i * 3) + j));
        }
        printf("\n");
    }

    //  different ways to print the values of elements
    printf("\nPrinting the values of elements using nums[i][j] \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", nums[i][j]);
        }
        printf("\n");
    }
    printf("\nPrinting the values of elements using *(nums[i]+j) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(nums[i] + j));
        }
        printf("\n");
    }
    printf("\nPrinting the values of elements using *(*(nums+i)+j) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(*(nums + i) + j));
        }
        printf("\n");
    }
    printf("\nPrinting the values of elements using *(B+((i*C)+j)) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(ptr + ((i * 3) + j)));
        }
        printf("\n");
    }
    printf("\n");

    // In lines 83 & 121, B stands for the 'base-address' i.e., the address of the first integer element.
    // Using %d specifier to print the address in base-10 int for easy understanding
    return 0;
}