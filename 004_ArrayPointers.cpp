// 004 Array Pointers and Pointer Arithematics
#include <iostream>
using namespace std;

int main()
{
    int nums[4] = {5, 2, 1, 4};
    int *ptr = nums;
    // The name of the Array returns the address of its first element
    printf("\n`ptr = nums`   is same as   `ptr = &nums[0]`");
    printf("\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\n\nDifferent ways to get the address of nums[%d] ", i);
        printf("\n&nums[%d] = %d", i, &nums[i]);
        printf("\t(nums+%d) = %d", i, (nums + i));
        printf("\t(ptr+%d)  = %d", i, (ptr + i));
    }
    printf("\n\n");
    for (int i = 0; i < 4; i++)
    {
        printf("\n\nDifferent ways to get the value of nums[%d] ", i);
        printf("\n  nums[%d] = %d", i, nums[i]);
        printf("\t\t*(nums+%d) = %d", i, *(nums + i));
        printf("\t\t*(ptr+%d)  = %d", i, *(ptr + i));
    }
    printf("\n\n\n");
    // To get the address of the array itself, use `&nums`
    printf("\nAddress of the Array        (&nums)   = %d \t (type = int **)", &nums);
    // Address of the array is same as the address of its first element only their types are not the same
    printf("\nAddress of the 1st element (&nums[0]) = %d \t (type = int *)", &nums[0]);
    // In this example : address of the int array nums is of the type `int**`
    //                 : address of the its first element is of the type `int*`

    // Order of precedence
    printf("\n\n");
    printf("\n*(nums+1) = %d \t\t!=\t *nums + 1 = %d \t\t==\t (*nums)+1 = %d", *(nums + 1), *nums + 1, (*nums) + 1);
    // &(address of) and *(value at) operators are unary operators and have a greater priority than {*, /, +, -} operators
    printf("\n\n");

    // Using %d specifier to print the address in base10 int for easy understanding
    return 0;
}
