#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class stack
{
public:
    Node *front;
    Node *rear;
    stack()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty();
    int enqueue(int item);
    int dequeue();
};

bool stack::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
};

int stack::enqueue(int item)
{
    Node *newNode = new Node(item);
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    rear->next = newNode;
    rear = rear->next;
    cout << "enqueued: " << item << endl;
}

int stack::dequeue()
{
    if (isEmpty())
    {
        cout << "The stack is empty"<<endl;
        return -1;
    }
    int tempData = front->data;
    Node* tempPtr = front;
    front = front->next;
    if (front == nullptr)
    {
        rear = nullptr;
    }
     delete tempPtr;
    cout << "Dequeued: " << tempData << endl;
    return tempData;
}
int main(int argc, char const *argv[])
{
    stack list;
    list.enqueue(1);
    list.enqueue(2);
    list.enqueue(3);
    list.dequeue();
    list.dequeue();
    list.enqueue(4);
    list.dequeue();
    list.dequeue();
    list.dequeue();
    list.dequeue();
    list.dequeue();
    list.dequeue();

    return 0;
}
