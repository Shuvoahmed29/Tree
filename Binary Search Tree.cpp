#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
struct Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// insert Node.............
struct Node *insertNode(Node *ptr, int data)
{
    if (ptr == NULL)
        ptr = createNode(data);
    else if (data <= ptr->data)
        ptr->left = insertNode(ptr->left, data);
    else
        ptr->right = insertNode(ptr->right, data);
    return ptr;
}
// Pre-Order traversal in binary tree.......
void pre_order(Node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        pre_order(ptr->left);
        pre_order(ptr->right);
    }
}

// In-Order traversal in binary tree.......
void in_order(Node *ptr)
{
    if (ptr != NULL)
    {
        in_order(ptr->left);
        cout << ptr->data << " ";
        in_order(ptr->right);
    }
}

// Post-Order traversal in binary tree.......
void post_order(Node *ptr)
{
    if (ptr != NULL)
    {
        post_order(ptr->left);
        post_order(ptr->right);
        cout << ptr->data << " ";
    }
}

void display(Node *root)
{
    cout << "Currtent list!!" << endl;
    cout << "Pre-Order: ";
    pre_order(root);
    cout << endl;

    cout << "In-Order: ";
    in_order(root);
    cout << endl;

    cout << "Post-Order: ";
    post_order(root);
    cout << endl;
}
int main()
{
    Node *root = NULL;
    while (1)
    {
        system("CLS");
        display(root);

        cout << "\nEnter I for insert element.\n";
        cout << "Enter any for exit.\n";
        cout << "Enter your choice: ";
        char ch;
        cin >> ch;
        if (ch == 'I' || ch == 'i')
        {
            system("CLS");
            display(root);
            cout << "Enter an element for insert: ";
            int element;
            cin >> element;
            root = insertNode(root, element);
        }
        else
            break;
    }
}