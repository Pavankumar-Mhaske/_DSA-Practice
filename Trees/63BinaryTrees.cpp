#include <iostream>
#include <queue>

using namespace std;
// TreeNode - node
class node
{
public:
    node *left;
    int data;
    node *right;

    node(int data) : left(NULL), data(data), right(NULL){};
};

void buildTreeFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter root data : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        root = nullptr;
        return;
    }

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data left of the : " << temp->data << " : ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data right of the : " << temp->right << " : ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrder(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
                q.push(nullptr);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int height(node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int diameter1(node *root) // O(n^2), O(height of T)
{
    if (root == NULL)
        return 0;

    int dia1 = diameter1(root->left);
    int dia2 = diameter1(root->right);
    int dia3 = height(root->left) + 1 + height(root->right);

    return max(max(dia1, dia2), dia3);
}

pair<int, int> diameter(node *root) // O(n), O(height of T)
{
    if (root == NULL)
        return make_pair(0, 0);

    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    int dia1 = left.first;
    int dia2 = right.first;
    int dia3 = left.second + right.second + 1;

    pair<int, int> info;
    info.first = max(max(dia1, dia2), dia3);
    info.second = max(left.second, right.second) + 1;
    return info;
}

int findDiameter(node *root)
{
    return diameter(root).first;
}

bool checkBalanced1(node *root)
{
    if (root == NULL)
        return true;

    bool isLeft = checkBalanced1(root->left);
    bool isRight = checkBalanced1(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (isLeft && isRight && diff)
        return true;
    else
        return false;
}

pair<bool, int> checkBalanced(node *root)
{
    if (root == NULL)
        return make_pair(true, 0);

    pair<bool, int> leftTree = checkBalanced(root->left);
    pair<bool, int> rightTree = checkBalanced(root->right);

    bool isLeft = leftTree.first;
    bool isRight = rightTree.first;
    bool diff = abs(leftTree.second - rightTree.second) <= 1;

    pair<bool, int> result;
    result.second = max(leftTree.second, rightTree.second) + 1;
    if (isLeft && isRight && diff)
        result.first = true;
    else
        result.first = false;

    return result;
}

bool isBalanced(node *root)
{
    return checkBalanced(root).first;
}

bool isIdentical(node *root1, node *root2)
{

    // base cases
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL && root2 != NULL)
        return false;
    if (root1 != NULL && root2 == NULL)
        return false;

    // both the nodes are not null
    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool currentVal = root1->data == root2->data;

    if (left && right && currentVal)
    {
        return true;
    }
    else
        return false;
}

// sum tree

pair<bool, int> sumTree(node *root)
{
    // null
    if (root == NULL)
        return make_pair(true, 0);

    // leaf node
    if (root->left == NULL && root->right == NULL)
        return make_pair(true, root->data);

    // now it's normal node in tree
    pair<bool, int> leftSumTree = sumTree(root->left);
    pair<bool, int> rightSumTree = sumTree(root->right);

    bool isLeftSumTreeOkay = leftSumTree.first;
    bool isRightSumTreeOkay = rightSumTree.first;

    bool isSumOkay = root->data == (leftSumTree.second + rightSumTree.second);

    pair<bool, int> result;
    if (isLeftSumTreeOkay && isRightSumTreeOkay && isSumOkay)
    {
        result.first = true;
        result.second = 2 * root->data;
    }
    else
    {
        result.first = false;
    }

    return result;
}

bool isSumTree(node *root)
{
    return sumTree(root).first;
}

// 1 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
// 14 3 4 1 2 2 2 -1 -1 -1 -1 -1 -1 -1 -1
int main(void)
{
    node *root, *root2;
    buildTreeFromLevelOrder(root);
    cout << endl;
    buildTreeFromLevelOrder(root2);

    cout << endl;
    levelOrder(root);
    cout << endl;
    cout << "height of the tree is : " << height(root);
    cout << endl;
    // pair<int, int> info = diameter(root);
    // cout << "Diameter of the tree is : " << info.first;
    cout << "Diameter of the tree is : " << findDiameter(root);
    cout << endl;
    // cout << "is balanced tree : " << checkBalanced1(root);
    cout << "is balanced tree : " << isBalanced(root);
    cout << endl;
    cout << "Is identical ? " << isIdentical(root, root2);
    cout << endl;
    cout << "Is Sum tree : " << isSumTree(root);

    return 0;
}
