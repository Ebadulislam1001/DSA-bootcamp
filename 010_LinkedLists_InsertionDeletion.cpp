// 010 Linked Lists Insertion
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createNode(int value = 0) // create node
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
int sizeOf(ListNode *&head)
{
    int size = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        size = size + 1;
    }
    return size;
}
void insAtBeg(ListNode *&head, int value) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
}
void delAtBeg(ListNode *&head) // Delete at Beginning
{
    if (head == NULL)
        return;

    ListNode *dead = head;
    head = dead->next;
    delete dead;
}
void insAtEnd(ListNode *&head, int value) // Insert at End
{
    ListNode *newnode = createNode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void delAtEnd(ListNode *&head) // Delete at End
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delAtBeg(head);
    }
    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void insAtIndex(ListNode *&head, int value, int index) // Insert at given Index
{
    if (index < 0 || sizeOf(head) < index)
    {
        // Invalid Index
        return;
    }
    else if (index == 0)
    {
        insAtBeg(head, value);
    }
    else
    {
        ListNode *newnode = createNode(value);
        ListNode *temp = head;
        while (index > 1)
        {
            temp = temp->next;
            index -= 1;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void delAtIndex(ListNode *&head, int index) // Delete at given Index
{
    if (index < 0 || sizeOf(head) - 1 < index)
    {
        // Checks for invalid Index
        // Also checks for if list is empty or not
        return;
    }
    else if (index == 0)
    {
        delAtBeg(head);
    }
    else
    {
        ListNode *temp = head;
        while (index > 1)
        {
            temp = temp->next;
            index -= 1;
        }
        ListNode *dead = temp->next;
        temp->next = dead->next;
        delete dead;
    }
}
void display(ListNode *head) // Display using List Traversal
{
    printf("\nList:");
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

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
        printf("\n");
        switch (choice)
        {
        case 1: // insert at beg
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            insAtBeg(head, value);
            display(head);
            break;
        }
        case 2: // insert at end
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            insAtEnd(head, value);
            display(head);
            break;
        }
        case 3: // insert at index
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            printf("Enter index: ");
            scanf("%d", &index);
            insAtIndex(head, value, index);
            display(head);
            break;
        }
        case 4: // delete at beg
        {
            delAtBeg(head);
            display(head);
            break;
        }
        case 5: // delete at end
        {
            delAtEnd(head);
            display(head);
            break;
        }
        case 6: // delete at index
        {
            printf("Enter index: ");
            scanf("%d", &index);
            delAtIndex(head, index);
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
            printf("Invalid choice (choose 0-6)");
        }
        }
    }
}