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

int main(void)
{
    Node *root;
    buildLevelOrder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    cout << "Sum of all nodes in bloodline is : " << sumOfLongRootToLeafPath(root);
}