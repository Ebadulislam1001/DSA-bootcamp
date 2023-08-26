#include <iostream>
using namespace std;

int insertAtBeg(int arr[], int &size, int value)
{
    if (size == 50)
        return -1;

    for (int i = size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
    size++;
    return 0;
}
int insertAtEnd(int arr[], int &size, int value)
{
    if (size == 50)
        return -1;

    arr[size] = value;
    size++;
    return size - 1;
}
int insertAtIndex(int arr[], int &size, int value, int index)
{
    if (size == 50)
        return -1;
    if (index < 0 || size < index)
        return -2;

    for (int i = size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    size++;
    return index;
}
int deleteAtBeg(int arr[], int &size)
{
    if (size == 0)
        return -1;

    for (int i = 0; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return 0;
}
int deleteAtEnd(int arr[], int &size)
{
    if (size == 0)
        return -1;

    size--;
    return size;
}
int deleteAtIndex(int arr[], int &size, int index)
{
    if (size == 0)
        return -1;
    if (index < 0 || size <= index)
        return -2;

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    return index;
}
void display(int arr[], int size)
{
    cout << "\nArray :";
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
}

int main()
{
    int choice, arr[50], size = 0, value, index;
    while (true)
    {
        printf("\n\n=============MENU=============\n");

        printf("\nInsert at:\n\t01.beginning\n\t02.end\n\t03.given index");
        printf("\nDelete at:\n\t04.beginning\n\t05.end\n\t06.given Index");
        printf("\n00.Exit   \n\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            cout << "Enter the value : ";
            cin >> value;
            index = insertAtBeg(arr, size, value);
            if (index == -1)
                cout << "\nArray Overflow -> cant add more elements";
            else
                cout << "\nSuccessfully Inserted at Begin";
            display(arr, size);
            break;
        case 2:
            cout << "Enter the value : ";
            cin >> value;
            index = insertAtEnd(arr, size, value);
            if (index == -1)
                cout << "\nArray Overflow -> cant add more elements";
            else
                cout << "\nSuccessfully Inserted at End";
            display(arr, size);
            break;
        case 3:
            cout << "Enter the value : ";
            cin >> value;
            cout << "Enter the index : ";
            cin >> index;
            index = insertAtIndex(arr, size, value, index);
            if (index == -1)
                cout << "\nArray Overflow -> cant add more elements";
            else if (index == -2)
                cout << "\nInvalid Index -> 0 <= valid index <= " << size;
            else
                cout << "\nSuccessfully Inserted at Index = " << index;
            display(arr, size);
            break;
        case 4:
            index = deleteAtBeg(arr, size);
            if (index == -1)
                cout << "\nArray Underflow -> no elements to delete";
            else
                cout << "\nSuccessfully Deleted at Begin";
            display(arr, size);
            break;
        case 5:
            index = deleteAtEnd(arr, size);
            if (index == -1)
                cout << "\nArray Underflow -> no elements to delete";
            else
                cout << "\nSuccessfully Deleted at End";
            display(arr, size);
            break;
        case 6:
            cout << "Enter the index : ";
            cin >> index;
            index = deleteAtIndex(arr, size, index);
            if (index == -1)
                cout << "\nArray Underflow -> no elements to delete";
            else if (index == -2)
                cout << "\nInvalid Index -> 0 <= valid index < " << size;
            else
                cout << "\nSuccessfully Deleted at Index = " << index;
            display(arr, size);
            break;
        case 0:
            return 0;

        default:
            cout << "Invalid Choice -> pick [0-6] \n";
            break;
        }
    }

    return 0;
}