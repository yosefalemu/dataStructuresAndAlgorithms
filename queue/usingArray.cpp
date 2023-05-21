#include <iostream>
using namespace std;

const int maxSize = 10;
class queue
{
private:
    int front;
    int rare;
    int values[maxSize];

public:
    queue()
    {
        front = -1;
        rare = -1;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    int dequeue();
};

bool queue::isEmpty()
{
    if (front == -1 && rare == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue::isFull()
{
    if ((rare + 1) % maxSize == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void queue::enqueue(int data)
{
    if (isFull())
    {
        cout << "The queue is full" << endl;
        return;
    }
    if (isEmpty())
    {
        front = 0;
    }

    rare = (rare + 1) % maxSize;
    values[rare] = data;
    cout << "Enqueued: " << data <<endl;
}
int queue::dequeue()
{
    if (isEmpty())
    {
        cout << "The stack is empty" <<endl;
        return -1;
    }
    int data = values[front];
    if (front == rare)
    {
        front = -1;
        rare = -1;
    }
    else
    {
        front = (front + 1) % maxSize;
    }
    cout << "Dequeued: " << data <<endl;
    return data;
}

int main(int argc, char const *argv[])
{
    queue list;
    list.enqueue(1);
    list.enqueue(2);
    list.enqueue(3);
    list.dequeue();
    list.dequeue();
    list.enqueue(4);
    list.dequeue();
    list.dequeue();

    return 0;
}
