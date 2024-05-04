#include <iostream>
using namespace std;
#include <vector>

class node
{
public:
    node *left;
    int data;
    node *right;

    node(int data) : left(nullptr), data(data), right(nullptr){};
};

class BinaryTree
{
    vector<int> nodes;
    int idx;

public:
    BinaryTree(vector<int> &nodes) : nodes(nodes), idx(-1){};

    node *buildTree()
    {
        idx++;
        if (nodes[idx] == -1)
        {
            return nullptr;
        }

        node *newNode = new node(nodes[idx]);
        newNode->left = buildTree();
        newNode->right = buildTree();

        return newNode;
    }
    node *getRoot()
    {
        return buildTree();
    }
};

void preOrder(node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(void)
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree(nodes);

    node *root = tree.getRoot();
    // preOrder(root);
    // inOrder(root);
    postOrder(root);
    // cout << root->data;

    return 0;
}