#include <iostream>
using namespace std;

class DoublyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node()
        {
            data = 0;
            prev = NULL;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    };
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }
    // append function for the doublyLinkedList
    void append(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *current_Node = head;
        while (current_Node->next)
        {
            current_Node = current_Node->next;
        }
        current_Node->next = newNode;
        newNode->prev = current_Node;
    }
    // prepend function for the doublyLinkedList
    void prepend(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    // insert function for the doublyLinkedList which takes value and the position where the insertion takes place
    void insert(int data, int position)
    {
        Node *newNode = new Node(data);
        if (position == 1)
        {
            prepend(data);
            return;
        }
        int listLength = 0;
        Node *current_Node = head;
        Node *prev_Node;
        while (current_Node)
        {
            current_Node = current_Node->next;
            listLength++;
        }
        if (position == listLength + 1)
        {
            append(data);
            return;
        }
        current_Node = head;
        if (position > listLength)
        {
            cout << "List out of range" << endl;
            return;
        }

        while (position > 1)
        {
            prev_Node = current_Node;
            current_Node = current_Node->next;
            position--;
        }
        prev_Node->next = newNode;
        newNode->prev = prev_Node;
        newNode->next = current_Node;
        current_Node->prev = prev_Node;
    }
    // remove function for the doublyLinkedList
    void remove(int value)
    {
        Node *current_Node = head;
        Node *prev;
        if (head->data == value)
        {
            head = head->next;
            delete current_Node;
            return;
        }
        while (current_Node)
        {
            if (current_Node->data != value)
            {
                prev = current_Node;
                current_Node = current_Node->next;
            }
            else
            {
                prev->next = current_Node->next;
                current_Node->next->prev = prev;
                delete current_Node;
                return;
            }
        }
        cout << "No match value exit" << endl;
    }

    // display function for the doublyLinkeList
    void display()
    {
        if (!head)
        {
            cout << "The List is empty" << endl;
            return;
        }
        Node *current_Node = head;
        while (current_Node)
        {
            cout << current_Node->data << " ";
            current_Node = current_Node->next;
        }
    }
};
int main(int argc, char const *argv[])
{
    DoublyLinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);
    list.insert(4, 5);
    list.remove(2);
    list.display();
    return 0;

    return 0;
}
