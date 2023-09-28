// 011 Linked Lists Functions
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;
};

void addNode(ListNode *&head, int value) // Add node to the list
{
    ListNode *newnode = new ListNode;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}
void delNode(ListNode *&head) // Delete node from the list
{
    if (head != NULL)
    {
        ListNode *dead = head;
        head = dead->next;
        delete dead;
    }
}
int readValue(ListNode *head, int size, int index) // Read data value at a given index
{
    if (0 <= index && index < size)
    {
        ListNode *temp = head;
        for (int i = 0; i < size; i++)
        {
            if (i == index)
            {
                return temp->data;
            }
            temp = temp->next;
        }
    }
    return -1;
}
int writeValue(ListNode *head, int size, int index, int value) // Write data value at a given index
{
    if (0 <= index && index < size)
    {
        ListNode *temp = head;
        for (int i = 0; i < size; i++)
        {
            if (i == index)
            {
                temp->data = value;
                return 0;
            }
            temp = temp->next;
        }
    }
    return -1;
}
int searchValue(ListNode *head, int value) // Search a given data value in the list
{
    ListNode *temp = head;
    for (int i = 0; temp != NULL; i++)
    {
        if (temp->data == value)
        {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}
void rotateLeft(ListNode *&head) // Rotate the nodes left by one index
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head = head->next;
    temp->next->next = NULL;
}
void rotateRight(ListNode *&head) // Rotate the nodes right by one index
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next->next = head;
    head = temp->next;
    temp->next = NULL;
}
void fwdDisplayRec(ListNode *head) // Display the list using recursion
{
    if (head != NULL)
    {
        printf(" -> %d", head->data);
        fwdDisplayRec(head->next);
    }
}
void revDisplayRec(ListNode *head) // Display the list in reverse using recursion
{
    if (head != NULL)
    {
        revDisplayRec(head->next);
        printf(" %d <-", head->data);
    }
}
int display(ListNode *head) // Display the list using iterative traversal
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
    int choice, index, value, size = 0;
    ListNode *head = NULL;
    while (1)
    {
        printf("\n\n=============MENU=============\n");

        printf("\n00.Exit\n01.Add node\n02.Del node\n03.Read data\n04.Write data");
        printf("\n05.Search data\n06.Rotate Left\n07.Rotate Right");
        printf("\n08.FWD Display List (rec.)\n08.REV Display (rec.)\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Add node
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            addNode(head, value);
            break;
        }
        case 2: // Del node
        {
            printf("Deleting the first node\n");
            delNode(head);
            break;
        }
        case 3: // Read data
        {
            printf("Enter index: ");
            scanf("%d", &index);
            value = readValue(head, size, index);
            if (value >= 0)
                printf("\nData value at index %d is %d", index, value);
            else
                printf("\nInvalid index");
            break;
        }
        case 4: // Write data
        {
            printf("Enter index: ");
            scanf("%d", &index);
            printf("Enter data value: ");
            scanf("%d", &value);
            value = writeValue(head, size, index, value);
            if (value >= 0)
                printf("\nData value at index %d is updated to %d", index, value);
            else
                printf("\nInvalid index");
            break;
        }
        case 5: // Search data
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = searchValue(head, value);
            if (index >= 0)
                printf("\nData value %d is at index %d", value, index);
            else
                printf("\nData value %d is not in the list", value);
            break;
        }
        case 6: // Rotate left
        {
            printf("Rotating list left by 1\n");
            rotateLeft(head);
            break;
        }
        case 7: // Rotate right
        {
            printf("Rotating list right by 1\n");
            rotateRight(head);
            break;
        }
        case 8: // Forward Display (rec.)
        {
            printf("Printing list using recursion\n\n\t");
            fwdDisplayRec(head);
            break;
        }
        case 9: // Reverse Display (rec.)
        {
            printf("Reverse printing list using recursion\n\n\t");
            revDisplayRec(head);
            break;
        }
        case 0: // Exit
        {
            printf("\n===========THE END===========\n ");
            return 0;
        }
        default: // Invalid choice
        {
            printf("\nInvalid choice (choose 0-9)");
        }
        }
        size = display(head);
    }
}

// Time Complexities of these functions

// int readValue(ListNode *head, int size, int index)                   O(N)
// int writeValue(ListNode *head, int size, int index, int value)      O(N)
// int searchValue(ListNode *head, int value)                          O(N)

// void rotateLeft(ListNode *head)                                     O(N) can be optimised to O(1)
// void rotateRight(ListNode *head)                                    O(N)

// ListNode *reverseListItr(ListNode *head)                            O(N)
// ListNode *reverseListRec(ListNode *head)                            O(N)
// void fwdDisplayRec(ListNode *head)                                  O(N)
// void revDisplayRec(ListNode *head)                                  O(N)
