// 012 Linked Lists Functions Optimised
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

ListNode *createNode(int value = 0) // allocate memory for a new node
{
    ListNode *newnode = new ListNode;
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
int insertAtBeg(ListNode *&head, ListNode *&tail, int &size, int value) // In O(1) time
{
    ListNode *newnode = createNode(value);
    if (size == 0)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    size += 1;
    return 0;
}
int insertAtEnd(ListNode *&head, ListNode *&tail, int &size, int value) // In O(1) time
{
    ListNode *newnode = createNode(value);
    if (size == 0)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = tail->next;
    }
    size += 1;
    return size - 1;
}
int insertAtIndex(ListNode *&head, ListNode *&tail, int &size, int value, int index) // In O(N) time
{
    if (index < 0 || size < index)
    {
        return -1;
    }
    if (index == 0)
    {
        return insertAtBeg(head, tail, size, value);
    }
    if (index == size)
    {
        return insertAtEnd(head, tail, size, value);
    }
    ListNode *newnode = createNode(value);
    ListNode *temp = head;
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    size += 1;
    return index;
}
int deleteAtBeg(ListNode *&head, ListNode *&tail, int &size) // In O(1) time
{
    if (size == 0)
    {
        return -1;
    }
    ListNode *dead = head;
    head = dead->next;
    if (tail == dead)
    {
        tail = NULL;
    }
    delete dead;
    size -= 1;
    return 0;
}
int deleteAtEnd(ListNode *&head, ListNode *&tail, int &size) // In O(N) time
{
    if (size == 0)
    {
        return -1;
    }
    if (size == 1)
    {
        return deleteAtBeg(head, tail, size);
    }
    tail = head;
    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }
    delete tail->next;
    tail->next = NULL;
    size -= 1;
    return size;
}
int deleteAtIndex(ListNode *&head, ListNode *&tail, int &size, int index) // In O(N) time
{
    if (index < 0 || size <= index)
    {
        return -1;
    }
    if (index == 0)
    {
        return deleteAtBeg(head, tail, size);
    }
    if (index == size - 1)
    {
        return deleteAtEnd(head, tail, size);
    }
    ListNode *temp = head;
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    ListNode *dead = temp->next;
    temp->next = dead->next;
    delete dead;
    size -= 1;
    return index;
}
// NOTE: tail pointer reduced the time complexity of insertAtEnd function from O(N) to O(1)
// But it didnt reduce the time taken by deleteAtEnd function
void leftRotate(ListNode *&head, ListNode *&tail, int size) // In O(1) time
{
    if (size > 1)
    {
        tail->next = head;
        head = head->next;
        tail = tail->next;
        tail->next = NULL;
    }
}
void rightRotate(ListNode *&head, ListNode *&tail, int size) // In O(n) time
{
    if (size > 1)
    {
        tail->next = head;
        head = tail;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = NULL;
    }
}
// NOTE: tail pointer reduced the time complexity of leftRotate function from O(N) to O(1)
// But it didnt reduce the time taken by rightRotate function
int display(ListNode *head) // Display using List Traversal
{
    int size = 0;
    printf("\nList:\t");
    ListNode *temp = head;
    while (temp != NULL)
    {
        printf(" -> %d", temp->data);
        temp = temp->next;
        size += 1;
    }
    return size;
}

int main()
{
    int choice, index, value;
    int size = 0;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.Beginning\n\t02.End\n\t03.Given Index");
        printf("\nDelete at:\n\t04.Beginning\n\t05.End\n\t06.Given Index");
        printf("\nRotate:\n\t07.Left\n\t08.Right");
        printf("\n0.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // insert at beg
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insertAtBeg(head, tail, size, value);
            break;
        }
        case 2: // insert at end
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = insertAtEnd(head, tail, size, value);
            break;
        }
        case 3: // insert at index
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            printf("Enter index: ");
            scanf("%d", &index);
            index = insertAtIndex(head, tail, size, value, index);
            break;
        }
        case 4: // delete at beg
        {
            index = deleteAtBeg(head, tail, size);
            break;
        }
        case 5: // delete at end
        {
            index = deleteAtEnd(head, tail, size);
            break;
        }
        case 6: // delete at index
        {
            printf("Enter index: ");
            scanf("%d", &index);
            index = deleteAtIndex(head, tail, size, index);
            break;
        }
        case 7: // Rotate left
        {
            printf("Rotating list left by 1\n");
            leftRotate(head, tail, size);
            break;
        }
        case 8: // Rotate right
        {
            printf("Rotating list right by 1\n");
            rightRotate(head, tail, size);
            break;
        }
        case 0:
        {
            printf("\n===========THE END===========\n ");
            return 0;
        }
        default:
        {
            printf("\nInvalid choice (choose 0-8)");
        }
        }
        size = display(head);
    }
}