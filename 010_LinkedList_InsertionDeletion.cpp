// 010 Linked Lists Insertion and Deletion
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    // next pointer declaration syntax for C
    // struct ListNode *next;
};

ListNode *createNode(int value = 0) // Creates/Allocates a new node
{
    // Using malloc to create/allocate a node in C
    // struct ListNode* newnode = (struct ListNode *)malloc(sizeof(struct ListNode *));

    // Using malloc to create/allocate a node in C++
    // ListNode* newnode = (ListNode *)malloc(sizeof(ListNode *));

    // Using new to create/allocate a node in C++
    ListNode *newnode = new ListNode;

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

int sizeOf(ListNode *&head) // Returns the size of the list i.e. the number of nodes
{
    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        // For every node in the list increment the size by 1 & then point to the next node
        temp = temp->next;
        size = size + 1;
    }
    // Hence, size = no. of nodes in the list
    return size;
}
void display(ListNode *head) // Display using List Traversal
{
    printf("\nList:");
    ListNode *temp = head;
    while (temp != NULL)
    {
        // For every node in the list print its data value & then point to the next node
        printf(" %d", temp->data);
        temp = temp->next;
    }
}
int insertAtBeg(ListNode *&head, int value) // Insert at Beginning
{
    // Allocate a node dynamically
    ListNode *newnode = createNode(value);
    // Newnode points current first node
    newnode->next = head;
    // Newnode is the new first node
    head = newnode;
    // Newnode added at beginning
    return 0;
}
int insertAtEnd(ListNode *&head, int value) // Insert at End
{
    // Allocate a node dynamically
    ListNode *newnode = createNode(value);
    // If the list is empty
    if (head == NULL)
    {
        // Newnode is the new first node
        head = newnode;
        // Newnode added at beginning
        return 0;
    }
    int index = 1;
    ListNode *temp = head;
    // Traverse the list till the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
        index += 1;
    }
    // Make the last node point to newnode
    // Newnode is the new last node
    temp->next = newnode;
    // Newnode added at end
    return index;
}
int insertAtIndex(ListNode *&head, int value, int index) // Insert at given Index
{
    if (index < 0 || sizeOf(head) < index)
    {
        // Invalid Index
        // No node is added
        return -1;
    }
    if (index == 0)
    {
        // If index = 0: insert the newnode at beginning
        return insertAtBeg(head, value);
    }
    // Allocate a node dynamically
    ListNode *newnode = createNode(value);
    ListNode *temp = head;
    // Traverse the list till the given index
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    // Make the (i-1)th node point to newnode
    // Newnode is the new ith node
    newnode->next = temp->next;
    temp->next = newnode;
    // Newnode added at the given index
    return index;
}
int deleteAtBeg(ListNode *&head) // Delete at Beginning
{

    if (head == NULL)
    {
        // The list is empty
        // No node is deleted
        return -1;
    }
    // Mark the first node dead;
    ListNode *dead = head;
    // Make the head point to the second node
    // Second node is the new first node
    head = dead->next;
    // Prev first node is deleted (memory deallocated)
    delete dead;
    // Node deleted from beginning
    return 0;
}
int deleteAtEnd(ListNode *&head) // Delete at End
{
    if (head == NULL)
    {
        // The list is empty
        // No node is deleted
        return -1;
    }
    // If the list has only one node
    if (head->next == NULL)
    {
        // Delete the first node
        return deleteAtBeg(head);
    }
    int index = 1;
    ListNode *temp = head;
    // Traverse the list till the second last node
    while (temp->next->next != NULL)
    {
        temp = temp->next;
        index += 1;
    }
    // Delete the last node
    delete temp->next;
    // Second last node is the new last node
    temp->next = NULL;
    // Node deleted from end
    return index;
}
int deleteAtIndex(ListNode *&head, int index) // Delete at given Index
{
    if (index < 0 || sizeOf(head) - 1 < index)
    {
        // Checks for invalid Index
        // Also checks for if list is empty or not
        // No node is deleted
        return -1;
    }
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
    delete dead;
    // Node deleted from the given index
    return index;
}

// size of the list is calculated by a dedicated function that takes extra O(N) time

int main()
{
    int choice, index, value;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");
        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index");
        printf("\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given index");
        printf("\n0.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Insert at beg
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insertAtBeg(head, value);
            display(head);
            break;
        }
        case 2: // Insert at end
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insertAtEnd(head, value);
            display(head);
            break;
        }
        case 3: // Insert at index
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            printf("Enter index: ");
            scanf("%d", &index);
            index = insertAtIndex(head, value, index);
            display(head);
            break;
        }
        case 4: // Delete at beg
        {
            index = deleteAtBeg(head);
            display(head);
            break;
        }
        case 5: // Delete at end
        {
            index = deleteAtEnd(head);
            display(head);
            break;
        }
        case 6: // Delete at index
        {
            printf("Enter index: ");
            scanf("%d", &index);
            index = deleteAtIndex(head, index);
            display(head);
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
        if (1 <= choice && choice <= 3)
        {
            if (index == -1)
                printf("\nFailed to insert node");
            else
                printf("\nNode inserted at index %d", index);
        }
        if (4 <= choice && choice <= 6)
        {
            if (index == -1)
                printf("\nFailed to delete node");
            else
                printf("\nNode deleted at index %d", index);
        }
    }
}

// Time Complexities of these functions

// ListNode *createNode(int value = 0)                      O(1)
// int sizeOf(ListNode *&head)                              O(N) can be optimised to O(1)
// void display(ListNode *head)                             O(N)

// int insAtBeg(ListNode *&head, int value)                 O(1)
// int insAtEnd(ListNode *&head, int value)                 O(N) can be optimised to O(1)
// int insAtIndex(ListNode *&head, int value, int index)    O(N)

// int delAtBeg(ListNode *&head)                            O(1)
// int delAtEnd(ListNode *&head)                            O(N)
// int delAtIndex(ListNode *&head, int index)               O(N)
