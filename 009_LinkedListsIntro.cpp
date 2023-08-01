// 009 Linked Lists Introduction
#include <iostream>
using namespace std;

// Each node in a linked list has two parts:
// 1. Data part - to store the required data (can have one or more data variables)
// 2. Link part - to store the link of the next node (and the link of prev node)
// We achieve this by defining a struct as follows
struct node
{
    char data;  // data part
    node *next; // link part
    // struct node *next; (syntax for C)
};

int main()
{
    // Declaring three node to form a linked list
    node n1, n2, n3, n4, n5;

    // Setting data values
    n1.data = 'H';
    n2.data = 'E';
    n3.data = 'L';
    n4.data = 'L';
    n5.data = 'O';
    // Setting next values
    n1.next = &n2;  // First node next  part points to Second node
    n2.next = &n3;  // Second node next part points to Third node
    n3.next = &n4;  // Third node next part points to Fourth node
    n4.next = &n5;  // Fourth node next part points to Fifth node
    n5.next = NULL; // Fifth node next part points to NULL (marks the end of the list)

    node *temp = &n1;
    printf("\n\nList Elements ");
    while (temp != NULL)
    {
        printf("-> %c ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    return 0;
}