#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int *array, front, rear, capacity, size;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        array = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            std::cout << "Queue is full. Cannot enqueue." << std::endl;
            return;
        }

        rear = (rear + 1) % capacity;
        array[rear] = value;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        front = (front + 1) % capacity;
        size--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1; // Or throw an exception
        }

        return array[front];
    }
};

int main()
{
    Queue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element: " << queue.getFront() << endl;

    queue.dequeue();

    cout << "Front element after dequeue: " << queue.getFront() << endl;

    return 0;
}