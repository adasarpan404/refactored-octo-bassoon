/**
 * @file queueWithStack.cpp
 * @author Arpan Das
 * @brief This program is for implementation of queue with stack
 * @version 0.1
 * @date 2022-08-16
 *
 * @copyright Copyright (c) 2022
 *
 */

/**
 * @brief implementating this type of solution.
 * we have two types of choices either make the insertion costly or deletion costly
 *
 * when we are making the deletion costly or insertion will be easy.
 * when we are making the insertion easy then deletion will be costly
 *
 */

/**
 * @brief this program has costly deletion solution
 *
 */

#include <bits/stdc++.h>
using namespace std;



struct queueWithStack{
    stack<int> s1, s2;
    void enqueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            return -1;
        }
 
        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

// main code 
int main(){
    queueWithStack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
    cout<<q.deQueue()<<endl;
}
    

