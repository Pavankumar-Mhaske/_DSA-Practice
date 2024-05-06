#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;
    Node(int data) : left(nullptr), data(data), right(nullptr){};
};

void buildLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter the root data : ";
    int data;
    cin >> data;

    if (data == -1)
    {
        root = NULL;
        return;
    }

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        cout << "Enter data to the left of : " << frontNode->data << " : ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            frontNode->left = new Node(leftData);
            q.push(frontNode->left);
        }

        cout << "Enter data to the right of : " << frontNode->data << " : ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            frontNode->right = new Node(rightData);
            q.push(frontNode->right);
        }
    }
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
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

// zigzag Traversal
vector<int> zigzag(Node *root)
{
    vector<int> result;
    queue<Node *> q;
    q.push(root);
    bool rightToLeft = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> v(size);

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            int index = rightToLeft ? i : size - i - 1;
            v[index] = temp->data;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        rightToLeft = !rightToLeft;
        for (auto i : v)
        {
            result.push_back(i);
        }
    }
    return result;
}

// Boundry Traversal
bool isLeafNode(Node *node)
{
    return (node->left == NULL && node->right == NULL);
}
void traverseLeft(Node *root, vector<int> &result)
{
    if (root == NULL || isLeafNode(root))
        return;

    result.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, result);
    else
        traverseLeft(root->right, result);
}

void traverseLeaf(Node *root, vector<int> &result)
{
    if (root == NULL)
        return;
    if (isLeafNode(root))
    {

        result.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, result);
    traverseLeaf(root->right, result);
}

void traverseRight(Node *root, vector<int> &result)
{
    if (root == NULL || isLeafNode(root))
        return;

    if (root->right)
        traverseRight(root->right, result);
    else
        traverseRight(root->left, result);

    result.push_back(root->data);
}

vector<int> boundry(Node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;
    // inserting the root node
    result.push_back(root->data);

    // inserting all left nodes -{ leaf nodes }
    traverseLeft(root->left, result);

    // inserting all leaf nodes
    traverseLeaf(root, result);

    // inserting all right nodes - { leaf nodes }
    traverseRight(root->right, result);
}

// top view of the binary tree
vector<int> topView(Node *root)
{
    vector<int> result;
    queue<pair<Node *, int>> q;
    map<int, int> topNodes;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int index = temp.second;

        // if already present then, do nothing...
        if (topNodes.find(index) == topNodes.end())
            topNodes[index] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, index - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, index + 1));
    }

    for (auto val : topNodes)
        result.push_back(val.second);
    return result;
}

// bottom view of the binary tree
vector<int> bottomView(Node *root)
{
    vector<int> result;
    // for storing current node and it's index
    queue<pair<Node *, int>> q;
    // for storing all bottom viewed nodes
    map<int, int> bottomNodes;
    // pushging first node and it's index value
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *currentNode = temp.first;
        int index = temp.second;

        bottomNodes[index] = currentNode->data;

        if (currentNode->left)
            q.push(make_pair(currentNode->left, index - 1));
        if (currentNode->right)
            q.push(make_pair(currentNode->right, index + 1));
    }
    for (auto val : bottomNodes)
        result.push_back(val.second);
    return result;
}

// left view of the binary tree
void solve1(Node *root, vector<int> &result, int level)
{
    if (root == NULL)
        return;

    if (level == result.size())
        result.push_back(root->data);

    solve1(root->left, result, level + 1);
    solve1(root->right, result, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> result;
    solve1(root, result, 0);
    return result;
}

// right view of the binary tree
void solve2(Node *root, vector<int> &result, int level)
{
    if (root == NULL)
        return;

    if (level == result.size())
        result.push_back(root->data);

    solve2(root->right, result, level + 1);
    solve2(root->left, result, level + 1);
}

vector<int> rightView(Node *root)
{
    vector<int> result;
    solve2(root, result, 0);
    return result;
}

// 1 2 3 4 5 -1 10 6 -1 9 8 12 11 -1 7 -1 -1 -1 -1 12 -1 -1 -1 14 -1 -1 -1

int main(void)
{
    Node *root;
    buildLevelOrder(root);
    cout << endl;
    levelOrder(root);
    vector<int> v = zigzag(root);
    for (auto val : v)
        cout << val << " ";

    cout << endl;
    cout << endl;
    vector<int> v1 = boundry(root);
    for (auto val : v1)
        cout << val << " ";

    cout << endl;
    cout << "Top view of the tree is : ";
    v1 = topView(root);
    for (auto val : v1)
        cout << val << " ";

    cout << endl;
    cout << "Bottom view of the tree is : ";
    v1 = bottomView(root);
    for (auto val : v1)
        cout << val << " ";

    cout << endl;
    cout << "left view of the tree is : ";
    v1 = leftView(root);
    for (auto val : v1)
        cout << val << " ";

    cout << endl;
    cout << "right view of the tree is : ";
    v1 = rightView(root);
    for (auto val : v1)
        cout << val << " ";

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1