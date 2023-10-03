// 012 Linked Lists Object
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    // constructor for struct in C++ (doesnt work in C)
    ListNode(int data, ListNode *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

class LinkedList
{
    ListNode *head; // Supposed to point the first node in the list
    ListNode *tail; // Supposed to point the last node in the list
    int size;       // Supposed to hold the size of the list

public:
    LinkedList() // Constructor
    {
        this->head = NULL; // Initially no first node
        this->tail = NULL; // Initially no last node
        this->size = 0;    // Initially no nodes at all
    };
    int getSize();                         // returns the size of list
    int insertAtBeg(int value);            // Insert node at Beginning
    int insertAtEnd(int value);            // Insert node at End
    int insertAtInd(int value, int index); // Insert node at given Index
    int deleteAtBeg();                     // Delete node at Beginning
    int deleteAtEnd();                     // Delete node at End
    int deleteAtInd(int index);            // Delete node at given Index
    void display();                        // Display the List
};

int main()
{
    int choice, index, value;
    LinkedList marks;
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
            index = marks.insertAtBeg(value);
            marks.display();
            break;
        }
        case 2: // Insert at end
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            index = marks.insertAtEnd(value);
            marks.display();
            break;
        }
        case 3: // Insert at index
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            printf("Enter index: ");
            scanf("%d", &index);
            index = marks.insertAtInd(value, index);
            marks.display();
            break;
        }
        case 4: // Delete at beg
        {
            index = marks.deleteAtBeg();
            marks.display();
            break;
        }
        case 5: // Delete at end
        {
            index = marks.deleteAtEnd();
            marks.display();
            break;
        }
        case 6: // Delete at index
        {
            printf("Enter index: ");
            scanf("%d", &index);
            index = marks.deleteAtInd(index);
            marks.display();
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

ListNode *createNode(int value = 0) // create node
{
    ListNode *newnode = new ListNode(value);
    return newnode;
}
int LinkedList::getSize()
{
    return this->size;
}
int LinkedList::insertAtBeg(int value) // Insert at Beginning
{
    ListNode *newnode = createNode(value);
    newnode->next = this->head;
    this->head = newnode;
    if (this->size == 0)
    {
        this->tail = newnode;
    }
    this->size += 1;
    return 0;
}
int LinkedList::insertAtEnd(int value) // Insert at End
{
    if (this->size == 0)
    {
        return this->insertAtBeg(value);
    }
    ListNode *newnode = createNode(value);
    this->tail->next = newnode;
    this->tail = newnode;
    this->size += 1;
    return this->size - 1;
}
int LinkedList::insertAtInd(int value, int index) // Insert at given Index
{
    if (index < 0 || this->size < index)
    {
        return -1;
    }
    if (index == 0)
    {
        return this->insertAtBeg(value);
    }
    ListNode *newnode = createNode(value);
    ListNode *temp = this->head;
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    if (index == this->size)
    {
        this->tail = newnode;
    }
    this->size += 1;
    return index;
}
int LinkedList::deleteAtBeg() // Delete at Beginning
{
    if (this->size == 0)
    {
        return -1;
    }
    ListNode *dead = this->head;
    this->head = dead->next;
    delete dead;
    this->size -= 1;
    if (this->size == 0)
    {
        this->tail = NULL;
    }
    return 0;
}
int LinkedList::deleteAtEnd() // Delete at End
{
    if (this->head == NULL)
    {
        return -1;
    }
    if (this->size == 1)
    {
        return this->deleteAtBeg();
    }
    ListNode *temp = this->head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    this->size -= 1;
    return this->size;
}
int LinkedList::deleteAtInd(int index) // Delete at given Index
{
    if (index < 0 || this->size <= index)
    {
        return -1;
    }
    if (index == 0)
    {
        return this->deleteAtBeg();
    }
    ListNode *temp = this->head;
    for (int t = 1; t < index; t++)
    {
        temp = temp->next;
    }
    ListNode *dead = temp->next;
    temp->next = dead->next;
    delete dead;
    this->size -= 1;
    return index;
}
void LinkedList::display() // Display the List
{
    printf("\nList ");
    ListNode *temp = this->head;
    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
    printf("\nSize = %2d", this->size);
}