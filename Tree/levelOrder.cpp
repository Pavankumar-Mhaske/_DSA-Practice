#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int item;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : item(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
    vector<int> nodes;
    int idx;

public:
    BinaryTree(vector<int> nodes) : nodes(nodes), idx(-1) {}

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

void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        cout << temp->item << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

int main(void)
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    BinaryTree tree(nodes);
    TreeNode *root = tree.buildTree();

    levelOrder(root);
    return 0;
}