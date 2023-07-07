// 002 Data Types and Pointers
#include <iostream>
using namespace std;

int main()
{
    printf("\n");
    printf("\tbool          => \t %2d Bytes \t %2d Bytes\t\n", sizeof(bool), sizeof(bool *));
    printf("\tchar          => \t %2d Bytes \t %2d Bytes\n", sizeof(char), sizeof(char *));
    printf("\tint           => \t %2d Bytes \t %2d Bytes\n", sizeof(int), sizeof(int *));
    printf("\tfloat         => \t %2d Bytes \t %2d Bytes\n", sizeof(float), sizeof(float *));
    printf("\tlong          => \t %2d Bytes \t %2d Bytes\n", sizeof(long), sizeof(long *));
    printf("\tlong long     => \t %2d Bytes \t %2d Bytes\n", sizeof(long long), sizeof(long long *));
    printf("\tlong int      => \t %2d Bytes \t %2d Bytes\n", sizeof(long int), sizeof(long int *));
    printf("\tlong long int => \t %2d Bytes \t %2d Bytes\n", sizeof(long long int), sizeof(long long int *));
    printf("\tdouble        => \t %2d Bytes \t %2d Bytes\n", sizeof(double), sizeof(double *));
    printf("\tlong double   => \t %2d Bytes \t %2d Bytes\n", sizeof(long double), sizeof(long double *));
    // printf("\tlong long double   => \t %2d Bytes \t %2d Bytes\n", sizeof(long long double), sizeof(long long double *));
    printf("\n\n");

    // `long` is same as `long int` by default
    // `long long` is same as `long long int` by default
    // `long long double` isnt a valid type

    return 0;
}