#include <bits/stdc++.h>
#define max 100
using namespace std;

class Stack
{
    int top;

public:
    int a[max];
    Stack() { top = -1; }
    bool push(int value);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int value)
{
    if (top >= max - 1)
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = value;
        cout << value << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack underflow";
        return -1;
    }
    else
    {
        int value = a[top--];
        return value;
    }
}

int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is empty";
        return -1;
    }
    else
    {
        int value = a[top];
        return value;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    Stack st;
    cout << (st.isEmpty() ? "Stack is empty" : "Stack is not empty");
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.pop() << " Popped from stack\n";
}