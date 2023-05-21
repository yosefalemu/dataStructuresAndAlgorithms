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
private:
    Node *topPtr;

public:
    stack()
    {
        topPtr = nullptr;
    }
    bool isEmpty();
    void push(int data);
    void top();
    int pop();
    void display();
};
bool stack::isEmpty()
{
    if (topPtr == nullptr)
    {
        return true;
    }
    return false;
}

void stack::push(int data)
{
    Node *newNode = new Node(data);
    newNode->next = topPtr;
    topPtr = newNode;
}

int stack::pop()
{
    if (!topPtr)
    {
        cout << "The stack is empty" << endl;
        return -1;
    }
    else
    {
        cout << topPtr->data << endl;
        Node *temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
    }
}
void stack::top()
{
    if (!topPtr)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << topPtr->data<<endl;
    }
}

void stack::display()
{
    if (topPtr == nullptr)
    {
        cout << "The stack is empty";
    }
    else
    {
        Node *currentPtr = topPtr;
        while (currentPtr)
        {
            cout << currentPtr->data << " ";
            currentPtr = currentPtr->next;
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    stack list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.display();
    list.top();
    list.pop();
    list.display();
    list.pop();
    list.pop();
    list.display();
   
}
