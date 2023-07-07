// 004 Array Pointers and Pointer Arithematics
#include <iostream>
using namespace std;

int main()
{
    int nums[4] = {5, 2, 1, 4};
    int *ptr = nums;
    // The name of the Array returns the address of its first element
    // `ptr = nums`   is same as   `ptr = &nums[0]`
    // To get the address of the array itself, use `&nums`
    // Address of the array is same as the address of its first element only their types are not the same
    // In this example : address of the int array nums is of the type `int**`
    //                 : address of the its first element is of the type `int*`

    // Using %d specifier to print the address in base10 int for easy understanding

    printf("\n nums[0] = %d, ptr[0] = %d, *(nums+0) = %d, *(ptr+0) = %d", nums[0], ptr[0], *(nums + 0), *(ptr + 0));
    printf("\n nums[1] = %d, ptr[1] = %d, *(nums+1) = %d, *(ptr+0) = %d", nums[1], ptr[1], *(nums + 1), *(ptr + 1));
    printf("\n nums[2] = %d, ptr[2] = %d, *(nums+2) = %d, *(ptr+0) = %d", nums[2], ptr[2], *(nums + 2), *(ptr + 2));
    printf("\n nums[3] = %d, ptr[3] = %d, *(nums+3) = %d, *(ptr+0) = %d", nums[3], ptr[3], *(nums + 3), *(ptr + 3));
    printf("\n");
    printf("\n &nums[0] = %d, (nums+0) = %d, (ptr+0) = %d", &nums[0], (nums + 0), (ptr + 0));
    printf("\n &nums[1] = %d, (nums+1) = %d, (ptr+0) = %d", &nums[1], (nums + 1), (ptr + 1));
    printf("\n &nums[2] = %d, (nums+2) = %d, (ptr+0) = %d", &nums[2], (nums + 2), (ptr + 2));
    printf("\n &nums[3] = %d, (nums+3) = %d, (ptr+0) = %d", &nums[3], (nums + 3), (ptr + 3));
    printf("\n");
    printf("\n *nums = %d,\t\t *nums+1 = %d", *nums, *nums + 1);
    printf("\n nums  = %d,     nums+1  = %d", nums, nums + 1);
    printf("\n &nums = %d,     &nums+1 = %d", &nums, &nums + 1);
    printf("\n");
    printf("\n *nums = %d, *nums+1 =%d, *(nums+1) = %d", *nums, *nums + 1, *(nums + 1));
    printf("\n");

    return 0;
}
