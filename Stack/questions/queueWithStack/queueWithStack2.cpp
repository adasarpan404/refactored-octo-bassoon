/**
 * @file queueWithStack2.cpp
 * @author Arpan Das
 * @brief 
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief This program is with costly dequeue()
 * 
 */

#include<bits/stdc++.h>

using namespace std;

struct queueWithStack{
    stack<int> stack1, stack2;
    void enqueue(int x){
        stack1.push(x);
    }
    int dequeue(){
        if(stack1.empty()&&stack2.empty()){
            return -1;
        }
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int x = stack2.top();
        stack2.pop();
        return x;
    }
};

int main(){
    queueWithStack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
}