#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    vector<int> nodes;
    int idx;

public:
    BinaryTree(vector<int> &nodes) : nodes(nodes), idx(-1) {}

    TreeNode *buildTree()
    {
        idx++;
        if (nodes[idx] == -1)
            return nullptr;

        TreeNode *newNode = new TreeNode(nodes[idx]);

        newNode->left = buildTree();
        newNode->right = buildTree();

        return newNode;
    }
};

void preOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode *root)
{
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp != nullptr)
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        else
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
    }
}

int main(void)
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    BinaryTree tree(nodes);

    TreeNode *root = tree.buildTree();

    cout << root->data << endl;

    preOrderTraversal(root);
    cout << endl;
    inOrderTraversal(root);
    cout << endl;
    postOrderTraversal(root);
    cout << endl;
    levelOrder(root);

    return 0;
}