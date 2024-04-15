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

    TreeNode *getRoot()
    {
        return buildTree();
    }
    void showData(TreeNode *root)
    {
        if (!root)
            return;

        cout << root->data << " ";
        showData(root->left);
        showData(root->right);
    }
};

int main(void)
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    BinaryTree tree(nodes);

    TreeNode *root = tree.getRoot();
    cout << "Root data : " << root->data << " " << endl;
    tree.showData(root);
    return 0;
}