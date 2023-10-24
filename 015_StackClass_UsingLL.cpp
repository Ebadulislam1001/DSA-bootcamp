// 015 Stack Class
#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;

    // constructor for struct in C++ (doesnt work in C)
    StackNode(int data, StackNode *next = NULL)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    StackNode *head; // Supposed to point the first node (top) in the list

public:
    Stack() // Constructor
    {
        this->head = NULL; // Initially no first node
    };
    void push(int value); // Push element into the stack        // Insert at begin
    int pop();            // Pop element out of the stack       // Delete at begin
    int top();            // Return the top most element        // head -> data
    bool isEmpty();       // Returns if stack is empty
    void display();       // Display the content of the stack
};

int main()
{
    int choice, value;
    Stack stack;
    while (1)
    {
        printf("\n\n=============MENU=============\n");
        printf("\n1.Push\n2.Pop\n3.Top");
        printf("\n0.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // Push
        {
            printf("Enter data value: ");
            scanf("%d", &value);
            stack.push(value);
            printf("\n>> %d pushed into the stack", value);
            stack.display();
            break;
        }
        case 2: // Pop
        {
            if (!stack.isEmpty())
            {
                value = stack.pop();
                printf("\n>> %d popped out of the stack", value);
                stack.display();
            }
            else
            {
                printf("\n>> Stack is empty");
            }
            break;
        }
        case 3: // Top
        {
            if (!stack.isEmpty())
            {
                value = stack.top();
                printf("\n>> Top of the stack = %d", value);
                stack.display();
            }
            else
            {
                printf("\n>> Stack is empty");
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
            printf("\nInvalid choice (choose 0-3)");
        }
        }
    }
}

StackNode *createNode(int value = 0) // create node
{
    StackNode *newnode = new StackNode(value);
    return newnode;
}
bool Stack::isEmpty()
{
    return (this->head == NULL);
}
void Stack::push(int value) // Push element into the stack
{
    StackNode *newnode = createNode(value);
    newnode->next = this->head;
    this->head = newnode;
}
int Stack::pop() // Pop element out of the stack
{
    int value = head->data;
    if (this->isEmpty())
    {
        return -1;
    }
    StackNode *dead = this->head;
    this->head = dead->next;
    delete dead;
    return value;
}
int Stack::top() // Return the top most element
{
    if (this->isEmpty())
    {
        return -1;
    }
    return head->data;
}
void Stack::display() // Display the List
{
    printf("\nStack ");
    StackNode *temp = this->head;
    while (temp != NULL)
    {
        printf("-> %d ", temp->data);
        temp = temp->next;
    }
}
