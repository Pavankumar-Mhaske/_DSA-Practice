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

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// // approch 1
// int diameter1(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;
//     int dia1 = diameter1(root->left);
//     int dia2 = diameter1(root->right);
//     int dia3 = height(root->left) + height(root->right) + 1;

//     return max(dia3, max(dia1, dia2));
// }

class TreeInfo
{
public:
    int height;
    int diameter;
    TreeInfo(int height, int diameter)
    {
        this->height = height;
        this->diameter = diameter;
    }
};

// to calculate both height and diameter at the same time
class TreeInfo diameter(TreeNode *root)
{
    if (root == NULL)
        return TreeInfo(0, 0);

    TreeInfo leftT1 = diameter(root->left);
    TreeInfo rightT1 = diameter(root->right);

    int myHeight = max(leftT1.height, rightT1.height) + 1;

    int dia1 = leftT1.height + rightT1.height + 1;
    int dia2 = leftT1.diameter;
    int dia3 = rightT1.diameter;

    int myDiameter = max(max(dia1, dia2), dia3);

    return TreeInfo(myHeight, myDiameter);
}

// don't use this - just remember this ...
// Function to calculate the height of a binary tree and update the diameter
int calculateHeightAndDiameter(TreeNode *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0; // Base case: empty tree has height 0
    }

    // Recursively calculate the height of left and right subtrees
    int leftHeight = calculateHeightAndDiameter(root->left, diameter);
    int rightHeight = calculateHeightAndDiameter(root->right, diameter);

    // Update the diameter if the current path is the longest so far
    diameter = std::max(diameter, leftHeight + rightHeight);

    // Return the actual height of the subtree rooted at the current node
    return 1 + std::max(leftHeight, rightHeight);
}

// Function to calculate the diameter of a binary tree
int calculateDiameter(TreeNode *root)
{
    int diameter = 0; // Initialize diameter to 0
    calculateHeightAndDiameter(root, diameter);
    return diameter + 1;
}

int main(void)
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree tree(nodes);
    TreeNode *root = tree.buildTree();
    cout << "Diameter : " << diameter(root).diameter << " | Height : " << diameter(root).height << endl;
    cout << "Diameter = " << calculateDiameter(root);
    return 0;
}