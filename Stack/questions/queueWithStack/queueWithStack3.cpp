/**
 * @file queueWithStack3.cpp
 * @author Arpan Das
 * @brief
 * @version 0.1
 * @date 2022-08-17
 *
 *
 */

/**
 * @brief This program is using stack and one function call stack
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct queueWithStack
{
    stack<int> s;

    void enqueue(int x)
    {
        s.push(x);
    }

    int dequeue()
    {
        if (s.empty())
        {
            return -1;
        }
        int x = s.top();
        s.pop();
        if (s.empty())
        {
            return x;
        }
        int item = dequeue();
        s.push(x);
        return item;
    }
};


int main()
{
    queueWithStack q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}