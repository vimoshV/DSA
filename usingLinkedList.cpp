#include <iostream>
#include <chrono>
using namespace std;
// Node of a linked list
struct Node
{
    int data;   // Data of the node
    Node *next; // Pointer to the next node
};

// Implementing a stack using a linked list
class Stack
{
    Node *top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = NULL; // Initializing top to NULL as the stack is empty
    }

    // Push operation: Add an element to the top of the stack
    void push(int element)
    {
        Node *newNode = new Node; // Create a new node
        newNode->data = element;  // Set the data of the new node
        newNode->next = top;      // Set the next of the new node to the current top
        top = newNode;            // Update the top to point to the new node
    }

    // Pop operation: Remove and return the element at the top of the stack
    int pop()
    {
        if (isEmpty()) // Check if the stack is empty
        {
            cout << "Stack Underflow" << endl;
            return 0; // Return 0 if stack is empty
        }
        Node *temp = top;     // Store the current top node
        top = top->next;      // Move the top pointer to the next node
        int poppedElement = temp->data; // Get the data of the top node
        delete temp;          // Delete the old top node
        return poppedElement; // Return the popped element
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == NULL; // If top is NULL, stack is empty
    }

    // Find the top element of the stack
    int stackTop()
    {
        if (isEmpty()) // Check if the stack is empty
        {
            cout << "Stack is empty" << endl;
            return 0; // Return 0 if stack is empty
        }
        return top->data; // Return the data of the top node
    }

    // Display the elements of the stack
    void display()
    {
        if (isEmpty()) // Check if the stack is empty
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top; // Start from the top of the stack
        while (temp != NULL) // Iterate through the stack till the end
        {
            cout << temp->data << " "; // Print the data of the current node
            temp = temp->next;         // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    auto start_time = chrono::steady_clock::now();

    // implementing stack and methods
    Stack myStack;
    myStack.push(8);
    myStack.push(10);
    myStack.push(5);
    myStack.push(11);
    myStack.push(15);
    myStack.push(23);
    myStack.push(6);
    myStack.push(18);
    myStack.push(20);
    myStack.push(17);
    myStack.display();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.display();
    myStack.push(4);
    myStack.push(30);
    myStack.push(3);
    myStack.push(1);
    myStack.display();

    auto end_time = chrono::steady_clock::now();
    auto time_taken = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
    cout << "Time taken : " << time_taken << " nanoseconds" << endl;
    return 0;
}
