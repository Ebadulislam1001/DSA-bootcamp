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
    // Declaring five node to form a linked list
    node n1, n2, n3, n4, n5;

    // Setting data values
    n1.data = 'H';
    n2.data = 'E';
    n3.data = 'L';
    n4.data = 'L';
    n5.data = 'O';

    // Setting next values
    n1.next = &n2;  // First node's next part points to Second node
    n2.next = &n3;  // Second node's next part points to Third node
    n3.next = &n4;  // Third node's next part points to Fourth node
    n4.next = &n5;  // Fourth node's next part points to Fifth node
    n5.next = NULL; // Fifth node's next part points to NULL (marks the end of the list)

    printf("\n\nList Elements ");

    node *temp = &n1; // temp pointer pointing to the first node
    while (temp != NULL)
    {
        // Let temp pointer be pointing the ith node
        printf("-> %c ", temp->data); // Print the ith character
        temp = temp->next;            // make temp pointer point the (i+1)th node
    }
    // (temp == NULL) brings us out of the loop
    // We have traversed through all the nodes in the Linked List

    printf("\n\n");
    return 0;
}