#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class binaryTree
{
private:
    Node *root;

public:
    binaryTree()
    {
        Node *test;
        root = nullptr;
    }
    void insert(int item);
    void display();
    void inorderTraversal(Node *node);
    void preorderTraversal(Node *node);
    void postorderTraversal(Node *node);
    void findDeleteNode(int num);
    void handleDeleteNode(Node *node);
    bool searchNode(int num);
};
void binaryTree::insert(int item)
{
    Node *newNode = new Node(item);
    if (root == nullptr)
    {
        root = newNode;
        return;
    }
    Node *current = root;
    while (true)
    {
        if (item < current->data)
        {
            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }
            current = current->left;
        }

        else if (item > current->data)
        {
            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
        else
        {
            return;
        }
    }
}
void binaryTree::inorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}
void binaryTree::preorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void binaryTree::postorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}

bool binaryTree::searchNode(int num)
{
    Node *currNode = root;
    while (currNode)
    {
        if (currNode->data == num)
        {
            cout << "Found" << endl;
            return true;
        }
        else if (num < currNode->data)
        {
            currNode = currNode->left;
        }
        else
        {
            currNode = currNode->right;
        }
    }
    cout << "not found" << endl;
    return false;
}

void binaryTree::findDeleteNode(int num)
{
    Node *currNode = root;
    while (currNode)
    {
        if (currNode->data == num)
        {
            handleDeleteNode(currNode);
            break;
        }
        else if (num < currNode->data)
        {
            currNode = currNode->left;
        }
        else
        {
            currNode = currNode->right;
        }
    }
}

void binaryTree::handleDeleteNode(Node *curr)
{
    Node *parentNode = nullptr;
    Node *replacementNode = nullptr;

    Node *tempNode = root;
    while (tempNode && tempNode != curr)
    {
        parentNode = tempNode;
        if (curr->data < tempNode->data)
            tempNode = tempNode->left;
        else
            tempNode = tempNode->right;
    }
    if (curr->right)
    {

        replacementNode = curr->right;
        while (replacementNode->left)
            replacementNode = replacementNode->left;

        if (parentNode)
        {
            if (curr == parentNode->left)
                parentNode->left = replacementNode;
            else
                parentNode->right = replacementNode;
        }
        else
        {

            root = replacementNode;
        }

        replacementNode->left = curr->left;
        if (replacementNode != curr->right)
            replacementNode->right = curr->right;
    }
    else
    {

        if (parentNode)
        {

            if (curr == parentNode->left)
                parentNode->left = nullptr;
            else
                parentNode->right = nullptr;
        }
        else
        {
            root = nullptr;
        }
    }

    delete curr;
}

void binaryTree::display()
{
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "postorder traversal: ";
    postorderTraversal(root);
    cout << endl;
}

int main(int argc, char const *argv[])
{
    binaryTree tree;
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(7);
    tree.findDeleteNode(7);
    tree.searchNode(7);

    tree.display();
    return 0;
}
