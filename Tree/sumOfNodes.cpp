#include <iostream>
#include <vector>
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

int sumOfNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int sumOfLeftNode = sumOfNodes(root->left);
    int sumOfRightNode = sumOfNodes(root->right);

    return root->data + sumOfLeftNode + sumOfRightNode;
}

int main(void)
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    BinaryTree tree(nodes);

    TreeNode *root = tree.buildTree();

    cout << sumOfNodes(root);
    return 0;
}