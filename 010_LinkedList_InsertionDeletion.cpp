// 010 Linked Lists Insertion and Deletion
#include <iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    ListNode *next;
} ListNode;
// Using typedef to make the code more C friendly

ListNode *createNode(int data = 0, ListNode *next = NULL) // Creates/Allocates a new node
{
    // Using malloc to create/allocate a node in C/C++
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode *));

    // Using new to create/allocate a node in C++
    // ListNode *newnode = new ListNode;

    newnode->data = data;
    newnode->next = next;
    // Note: the next part of the newnode is set as NULL by default.

    return newnode;
}

int sizeOf(ListNode *head) // Returns the size of the list i.e. the number of nodes
{
    int size = 0;
    ListNode *temp = head;
    // For every node in the list increment the size by 1 & then point to the next node
    while (temp != NULL)
    {
        temp = temp->next;
        size = size + 1;
    }
    // Hence, size = no. of nodes in the list
    return size;
}

void showList(ListNode *head) // print using List Traversal
{
    printf("\nList:");
    ListNode *temp = head;
    // For every node in the list print its data value & then point to the next node
    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
}

ListNode *insertAtBeg(ListNode *head, int value) // Insert at Beginning
{
    // Allocate a node dynamically
    ListNode *newnode = createNode(value);
    // Newnode points current first node
    newnode->next = head;
    // Newnode is the new first node
    head = newnode;
    // Newnode added at beginning
    return head;
}

ListNode *insertAtEnd(ListNode *head, int value) // Insert at End
{
    // Allocate a node dynamically
    ListNode *newnode = createNode(value);
    // If the list is empty
    if (head == NULL)
    {
        // Newnode is the new first node
        head = newnode;
        // Newnode added at beginning
        return head;
    }
    // The list is not empty and has atleast one node
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Make the last node point to newnode
    temp->next = newnode;
    // Newnode is the new last node
    return head;
}

ListNode *insertAtIndex(ListNode *head, int value, int index) // Insert at given Index
{
    // We made sure that the index is valid
    if (index == 0)
    {
        return insertAtBeg(head, value);
    }

    // Index is more than zero, and since the index is valid the list has atleast one node
    ListNode *newnode = createNode(value);
    ListNode *temp = head;
    // Traverse the list till the given index
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    // Make the new node point to the prev ith node
    newnode->next = temp->next;
    // Make the (i-1)th node point to newnode
    temp->next = newnode;
    // Newnode is the new ith node
    return head;
}

ListNode *deleteAtBeg(ListNode *head) // Delete at Beginning
{

    if (head == NULL)
    {
        // The list is empty
        return head;
    }
    // The list has atleast one node
    // Mark the first node dead;
    ListNode *dead = head;
    // Make the head point to the second node
    head = dead->next;
    // Second node is the new first node
    // Prev first node is freed (memory deallocated)
    free(dead);
    // Node deleted from beginning
    return head;
}

ListNode *deleteAtEnd(ListNode *head) // Delete at End
{
    if (head == NULL)
    {
        // The list is empty
        return head;
    }
    // If the list has only one node
    if (head->next == NULL)
    {
        // Delete the first node
        return deleteAtBeg(head);
    }
    // The list has atleast two nodes
    ListNode *temp = head;
    // Traverse the list till the second last node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // Delete the last node
    free(temp->next);
    // Second last node is the new last node
    temp->next = NULL;
    // Node deleted from end
    return head;
}

ListNode *deleteAtIndex(ListNode *head, int index) // Delete at given Index
{
    // We made sure that the index is valid
    if (index == 0)
    {
        // If index = 0: delete the newnode from beginning
        return deleteAtBeg(head);
    }
    ListNode *temp = head;
    // Traverse the list till the given index
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    // Mark the node at the given index as dead
    ListNode *dead = temp->next;
    temp->next = dead->next;
    free(dead);
    // Node deleted from the given index
    return head;
}

// size of the list is calculated by a dedicated function that takes extra O(N) time

int main()
{
    ListNode *head = NULL;
    while (1)
    {
        int choice, index, value;
        printf("\n\n=============MENU=============\n");
        printf("\nInsert at:");
        printf("\n\t01.beginning\n\t02.end\n\t03.given index");
        printf("\nDelete at:");
        printf("\n\t04.beginning\n\t05.end\n\t06.given index");
        printf("\n0.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Insert at beg
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            head = insertAtBeg(head, value);
            showList(head);
            break;
        }
        case 2: // Insert at end
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            showList(head);
            break;
        }
        case 3: // Insert at index
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            printf("Enter index: ");
            scanf("%d", &index);
            int size = sizeOf(head);
            if (index < 0 || size < index)
            {
                printf("Invalid index\n");
                break;
            }
            head = insertAtIndex(head, value, index);
            showList(head);
            break;
        }
        case 4: // Delete at beg
        {
            int size = sizeOf(head);
            if (size == 0)
            {
                printf("Underflow\n");
                break;
            }
            head = deleteAtBeg(head);
            showList(head);
            break;
        }
        case 5: // Delete at end
        {
            int size = sizeOf(head);
            if (size == 0)
            {
                printf("Underflow\n");
                break;
            }
            head = deleteAtEnd(head);
            showList(head);
            break;
        }
        case 6: // Delete at index
        {
            int size = sizeOf(head);
            if (size == 0)
            {
                printf("Underflow\n");
                break;
            }
            printf("Enter index: ");
            scanf("%d", &index);
            if (index < 0 || size <= index)
            {
                printf("Invalid index\n");
                break;
            }
            head = deleteAtIndex(head, index);
            showList(head);
            break;
        }
        case 0:
        {
            printf("\n===========THE END===========\n ");
            return 0;
        }
        default:
        {
            printf("\nInvalid choice (choose 0-6)");
        }
        }
    }
}

// Time Complexities of these functions

// ListNode *createNode(int value = 0)                      O(1)
// int sizeOf(ListNode *&head)                              O(N) can be optimised to O(1)
// void showList(ListNode *head)                            O(N)

// int insAtBeg(ListNode *&head, int value)                 O(1)
// int insAtEnd(ListNode *&head, int value)                 O(N) can be optimised to O(1)
// int insAtIndex(ListNode *&head, int value, int index)    O(N)

// int delAtBeg(ListNode *&head)                            O(1)
// int delAtEnd(ListNode *&head)                            O(N)
// int delAtIndex(ListNode *&head, int index)               O(N)
