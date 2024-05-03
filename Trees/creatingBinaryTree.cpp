#include <iostream>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;

    node(int data) : data(data), left(NULL), right(NULL){};
};

node *buildBinaryTree(node *root)
{
    cout << "Enter a data : ";
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for left of : " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter the data for right of : " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

int main(void)
{
    node *root = NULL;
    root = buildBinaryTree(root);
    return 0;
}