// 009 Linked Lists Introduction
#include <iostream>
using namespace std;

// Each node in a linked list has two parts:
// 1. Data part - to store the required data
// 2. Link part - to store the link of the next node
// We achieve this by defining a struct as follows
struct node
{
    char data;  // data part - to store the required data
    node *next; // link part - to store the link of the next node
};

int main()
{
    // Declaring five node to form a linked list
    // struct node n1, n2, n3, n4, n5;  // syntax for C
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

    // Let `temp` pointer be pointing to the first node
    // to be used as an iterator, like we use `i` in arrays
    node *temp = &n1;

    printf("\n\nPrinting Linked List Elements: ");
    while (temp != NULL)
    {
        printf("-> %c ", temp->data); // Print the current nodes data value
        temp = temp->next;            // make temp pointer point the next node
    }
    // (temp == NULL) brings us out of the loop
    // We have successfully traversed through all the nodes in the Linked List

    printf("\n\n");
    return 0;
}