// start writing program
#include <iostream>


// first defining the max value for program

#define max 100
// first defining the class stack
using namespace std;
class stack
{
    int top;

public:
    int a[max];
    stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();

};



// push function for the stack would be here. This function would be used for pushing the element to the stack
bool stack::push(int x)
{
    if (top >= max - 1)
    {
        cout << "Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
    
}



// pop function for the stack would be here. this function would be used for deleting the element from the stack

int stack::pop(){
    if(top== -1){
        cout<<"Stack Underflow";
        return 0;
    }else{
        int x=a[top--];
        return x;
    }
}

// empty function for the stack would be here. this function would be used for checking the function is empty or not.

bool stack::isEmpty(){
    return (top<0);
}

// peek function (this function would be used for getting the element at the top of the stack )

int stack::peek(){
    if(top<0){
        cout<<"Stack is empty";
        return -1;
    }else{
        int x = a[top];
        return x;
    }
}

// main function would be here

int main(){
    stack s;

    cout<<(s.isEmpty()?"Stack is empty": "Stack is not empty");
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";

    return 0;
}