#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertNode(int);
    void deleteNode(int);
    void displayList();
};

void LinkedList::insertNode(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::displayList()
{
    if (head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void LinkedList::deleteNode(int tobeDeleted)
{
    if (head == NULL)
    {
        cout << "Empty List" <<endl;
        return;
    }
    Node *temp = head;
    int listLen = 0;
    while (temp)
    {
        temp = temp->next;
        listLen++;
    }
    if (listLen < tobeDeleted)
    {
        cout << "index out of range"<< endl;
        return;
    }
    temp = head;
    if (tobeDeleted == 1)
    {
        head = head->next;
        delete temp;
        return;
    }
    temp = head;
    Node *prev = NULL;

    while (tobeDeleted > 1)
    {
        prev = temp;
        temp = temp->next;
        tobeDeleted--;
    }
    prev->next = temp->next;
    delete temp;
}
int main(int argc, char const *argv[])
{
    LinkedList list;
    list.insertNode(1);
    list.insertNode(2);
    list.deleteNode(1);
    list.displayList();
    return 0;
}
