// 016 Queue Class
#include <iostream>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;

    // constructor for struct in C++ (doesnt work in C)
    QueueNode(int data, QueueNode *next = NULL)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    QueueNode *head; // Supposed to point the first node (front) in the list
    QueueNode *tail; // Supposed to point the last node (back) in the list

public:
    Queue() // Constructor
    {
        this->head = NULL; // Initially no first node
        this->tail = NULL; // Initially no last node
    };
    void push(int value); // Push element into the queue        // Insert at end
    int pop();            // Pop element out of the queue       // Delete at begin
    int front();          // Return the first element           // head -> data
    int back();           // Return the last element            // tail -> data
    bool isEmpty();       // Returns if queue is empty
    void display();       // Display the content of the queue
};

int main()
{
    int choice, value;
    Queue queue;
    while (1)
    {
        printf("\n\n=============MENU=============\n");
        printf("\n1.Push\n2.Pop\n3.Front\n4.Back");
        printf("\n0.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Push
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            queue.push(value);
            printf("\n>> %d pushed into the queue", value);
            queue.display();
            break;
        }
        case 2: // Pop
        {
            if (!queue.isEmpty())
            {
                value = queue.pop();
                printf("\n>> %d popped out of the queue", value);
                queue.display();
            }
            else
            {
                printf("\n>> Queue is empty");
            }
            break;
        }
        case 3: // Front
        {
            if (!queue.isEmpty())
            {
                value = queue.front();
                printf("\n>> Front of the queue = %d", value);
                queue.display();
            }
            else
            {
                printf("\n>> Queue is empty");
            }
            break;
        }
        case 4: // Back
        {
            if (!queue.isEmpty())
            {
                value = queue.back();
                printf("\n>> Back of the queue = %d", value);
                queue.display();
            }
            else
            {
                printf("\n>> Queue is empty");
            }
            break;
        }
        case 0: // Exit
        {
            printf("\n===========THE END===========\n ");
            return 0;
        }
        default:
        {
            printf("\nInvalid choice (choose 0-4)");
        }
        }
    }
}

QueueNode *createNode(int value = 0) // create node
{
    QueueNode *newnode = new QueueNode(value);
    return newnode;
}
bool Queue::isEmpty()
{
    return (this->head == NULL);
}
void Queue::push(int value) // Push element into the queue
{
    QueueNode *newnode = createNode(value);
    if (this->head == NULL && this->tail == NULL)
    {
        this->head = newnode;
        this->tail = newnode;
    }
    else
    {
        this->tail->next = newnode;
        this->tail = newnode;
    }
}
int Queue::pop() // Pop element out of the queue
{
    if (this->isEmpty())
    {
        return -1;
    }
    int value = head->data;
    QueueNode *dead = this->head;
    this->head = head->next;
    delete dead;
    if (this->head == NULL)
    {
        this->tail = NULL;
    }
    return value;
}
int Queue::front() // Return the front element
{
    if (this->isEmpty())
    {
        return -1;
    }
    return head->data;
}
int Queue::back() // Return the back element
{
    if (this->isEmpty())
    {
        return -1;
    }
    return tail->data;
}
void Queue::display() // Display the List
{
    printf("\nQueue ");
    QueueNode *temp = this->head;
    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
}
