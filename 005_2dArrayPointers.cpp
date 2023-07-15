// 005 2D Array Pointers and Pointer Arithematics
#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *prr;
    // prr is integer pointer i.e. it points to integer element.
    // Doing prr = arr is wrong because 'arr' contains address of its first element
    // i.e. the first subarray arr[0] / the first row / an integer array of size 3.
    // But prr can only store the address of an int variable and not an int array.
    // However this syntax is correct in 1-D array, because their first element is an int variable
    // some correct syntaxes to store the address of first int element of a 2-D array are as follows

    // these are some valid assignments to prr, and all of these have the same meaning.
    prr = *arr;
    prr = arr[0];
    prr = &arr[0][0];

    // printing addresses of the array / a 2D array
    printf("\nAddress of the 2D array");
    printf("\n&arr         = %d", &arr);
    printf("\nAddress of the 2-D array + 1");
    printf("\n&arr+1       = %d", &arr + 1);
    printf("\n");
    // printing addresses of the subarray / a 1D array
    printf("\nAddress of the first subarray");
    printf("\n&arr[0]      = %d", &arr[0]);
    printf("\nAddress of the first subarray + 1");
    printf("\n&arr[0]+1    = %d", &arr[0] + 1);
    printf("\n");
    // printing addresses of the element / an int element
    printf("\nAddress of the first int element");
    printf("\n&arr[0][0]   = %d", &arr[0][0]);
    printf("\nAddress of the first element + 1");
    printf("\n&arr[0][0]+1 = %d", &arr[0][0] + 1);
    printf("\n");

    //  diferent ways to print the address of elements
    printf("\nPrinting the addresses of subarrays using &arr[i] \n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %d ", &arr[i]);
        printf("\n");
    }
    printf("\nPrinting the addresses of subarrays using arr+i \n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %d ", arr + i);
        printf("\n");
    }

    //  diferent ways to print the address of elements
    printf("\nPrinting the addresses of elements using &arr[i][j] \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", &arr[i][j]);
        }
        printf("\n");
    }
    printf("\nPrinting the addresses of elements using arr[i]+j \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", arr[i] + j);
        }
        printf("\n");
    }
    printf("\nPrinting the addresses of elements using *(arr+i)+j \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(arr + i) + j);
        }
        printf("\n");
    }
    printf("\nPrinting the addresses of elements using B+((i*C)+j) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *arr + ((i * 3) + j));
        }
        printf("\n");
    }

    //  different ways to print the values of elements
    printf("\nPrinting the values of elements using arr[i][j] \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\nPrinting the values of elements using *(arr[i]+j) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(arr[i] + j));
        }
        printf("\n");
    }
    printf("\nPrinting the values of elements using *(*(arr+i)+j) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\nPrinting the values of elements using *(B+((i*C)+j)) \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %d ", *(*arr + ((i * 3) + j)));
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}