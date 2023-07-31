// 009 Linked Lists Introduction
#include <iostream>
using namespace std;

// Each node in a linked list has two parts:
// 1. Data part - to store the required data (can have one or more data variables)
// 2. Link part - to store the link of the next node (and the link of prev node)
// We achieve this by defining a struct as follows
struct node
{
    int data;   // data part
    node *next; // link part
    // struct node *next; (syntax for C)
};

int main()
{
    // Declaring three node to form a linked list
    node n1, n2, n3;

    // Setting data values
    n1.data = 11;
    n2.data = 22;
    n3.data = 33;
    // Setting next values
    n1.next = &n2;  // First node next  part points to Second node
    n2.next = &n3;  // Second node next part points to Third node
    n3.next = NULL; // Third node next part points to NULL (marks the end of the list)

    node *temp = &n1;
    printf("\n\nList Elements ");
    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
    return 0;
}