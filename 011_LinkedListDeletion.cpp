// 011 Linked Lists Deletion
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

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
void delAtBeg(ListNode *&head) // Delete at Beginning
{
    if (head == NULL)
        return;

    ListNode *waste = head;
    head = head->next;
    delete waste;
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
    ListNode *waste = temp->next;
    temp->next = NULL;
    delete waste;
}
void delAtIndex(ListNode *&head, int index) // Delete at given Index
{
    if (index < 0 || sizeOf(head) < index - 1)
    {
        // Invalid Index
        return;
    }
    else if (index == 0)
    {
        delAtBeg(head);
    }
    else
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            ListNode *temp = head;
            while (index > 1)
            {
                temp = temp->next;
                index -= 1;
            }
            ListNode *waste = temp->next;
            temp->next = NULL;
            delete waste;
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
    int choice, index;
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
            case 1: // delete at beg
            {
                delAtBeg(head);
                display(head);
                break;
            }
            case 2: // delete at end
            {
                delAtEnd(head);
                display(head);
                break;
            }
            case 3: // delete at index
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
                printf("Invalid choice (choose 0-3)");
            }
            }
        }
    }
}