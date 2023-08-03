// 010 Linked Lists (Insertion & Deletion)
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
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            ListNode *temp = head;
            while (temp->next != NULL && index > 1)
            {
                temp = temp->next;
                index -= 1;
            }
            if (temp != NULL)
            {
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
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

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index\n0.Exit\n\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
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
            case 0:
            {
                printf("\n===========THE END===========\n ");
                return 0;
            }
            default:
            {
                printf("Invalid choice (choose 0-3)");
            }
            }
        }
    }
}