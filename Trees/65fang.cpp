#include <iostream>
#include <queue>
#include <limits.h>
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

// bloodline problme
void solve(Node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node *root)
{

    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, sum, maxSum, len, maxLen);

    return maxSum;
}

// lowest common ancestor (LCA)
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
        return root;
    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;
    else
        return NULL;
}

// k sum paths

void solve(Node *root, int k, int &count, vector<int> path)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, k, count, path);
    solve(root->right, k, count, path);

    int sum = 0;
    int size = path.size();
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}

int sumk(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main(void)
{
    Node *root;
    buildLevelOrder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    cout << "Sum of all nodes in bloodline is : " << sumOfLongRootToLeafPath(root);
    cout << endl;
    int n1 = 7, n2 = 8;
    cout << "LCA is : " << lca(root, n1, n2)->data;
    cout << endl;
    int k = 5;
    cout << "K sum paths are : " << sumk(root, k);
}

// 1 3 -1 2 1 4 5 -2 -2 1 -2 1 2 -2 6 -2 -2 -2 -2 -2 -2 -2 -2