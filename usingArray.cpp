#include <iostream>
#include <chrono>
using namespace std;

class Stack
{
private:
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x)
    {
        if (top == capacity -1)
        {
            // cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            // cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            // cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1){
            cout << "True";
            return top == -1;
        }
        else{
            cout << "False";
            return top == -1;
        }
    }

    bool isFull()
    {
        if (top == capacity - 1){
            cout << "True";
            return top == capacity - 1;
        }
        else{
            cout << "False";
            return top == capacity - 1;
        }
    }

    void display()
    {
        if (top == -1)
        {
            // cout << "Stack is empty\n";
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    auto start_time = chrono::steady_clock::now();

    // implementing stack and methods
    Stack myStack(10);
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
