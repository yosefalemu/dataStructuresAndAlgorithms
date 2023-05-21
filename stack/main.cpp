#include <iostream>
using namespace std;

class stack
{
private:
    int topNum;
    int maxTop;
    double *values;

public:
    stack();
    bool isEmpty();
    bool isFull();
    double top();
    double pop();
    void push(double data);
    void displayStack();
};
stack::stack()
{
    int size = 10;
    maxTop = size - 1;
    topNum = -1;
    values = new double[size];
    cout << values << endl;
}
bool stack::isEmpty()
{
    if (topNum == -1)
    {
        return true;
    }
    return false;
}
bool stack::isFull()
{
    if (topNum == maxTop)
    {
        return true;
    }
    return false;
}
double stack::top()
{
    if (isEmpty())
    {
        cout << "The stack is empty" << endl;
        return -1;
    }
    return values[topNum];
}
void stack::push(double data)
{
    if (isFull())
    {
        cout << "The stack is full" << endl;
    }
    else
    {
        values[++topNum] = data;
    }
}
double stack::pop(){
    if(isEmpty()){
        cout<<"The stack is empty"<<endl;
        return -1;
    }
    return values[topNum--];
}
void stack::displayStack()
{
    if (isEmpty())
    {
        cout << "the stack is empty";
    }
    else
    {
        while (!isEmpty())
        {
            cout << values[topNum--] << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    stack list;

    list.push(50);
    list.push(2.0);
    list.push(3.0);
    list.pop();
    list.displayStack();
    list.isEmpty();
    return 0;
}
