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

// kth ancestor in a tree

/*
void solve(Node *root, int &ancestor, vector<int> path, int val, int kth)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, ancestor, path, val, kth);
    solve(root->right, ancestor, path, val, kth);

    if (path.back() == val)
    {
        int size = path.size();
        int index = size - 1 - kth;
        if (index >= 0)
        {
            ancestor = path[index];
            return;
        }
    }
}

int kthAncestor(Node *root, int val, int kth)
{
    int ancestor = INT_MIN;
    vector<int> path;
    solve(root, ancestor, path, val, kth);
    return ancestor;
}


Node *solve(Node *root, int node, int &k)
{
    if (root == NULL)
        return NULL;

    if (root->data == node)
    {
        k--;
        return root;
    }

    Node *leftAns = solve(root->left, node, k);
    Node *rightAns = solve(root->right, node, k);

    cout << root->data << " | " << k << " | " << endl;
    if (leftAns != NULL)
    {

        if (k > 0)
        {
            k--;
            return leftAns;
        }
        if (k == 0)
        {
            leftAns = root;
            k--;
        }
        return leftAns;
    }
    else if (rightAns != NULL)
    {
        if (k > 0)
        {
            k--;
            return rightAns;
        }
        if (k == 0)
        {
            rightAns = root;
            k--;
        }
        return rightAns;
    }
    else
        return NULL;
}

int kthAncestor(Node *root, int node, int k)
{
    Node *ans = solve(root, node, k);
    cout << "VAlue of the K is : " << k;
    cout << endl;
    if (k > 0 || node == ans->data)
        return -1;
    else
        return ans->data;
}


*/

Node *solve(Node *root, int node, int &k)
{
    if (root == NULL)
        return NULL;
    if (root->data == node)
        return root;

    Node *leftAns = solve(root->left, node, k);
    Node *rightAns = solve(root->right, node, k);

    if (leftAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int node, int k)
{
    Node *result = solve(root, node, k);
    if (result == NULL || result->data == node)
    {
        return -1;
    }
    return result->data;
}

// maximum sum of the non-adjusent nodes
pair<int, int> solve(Node *root)
{
    if (root == NULL)
        return make_pair(0, 0);

    pair<int, int> leftSum = solve(root->left);
    pair<int, int> rightSum = solve(root->right);

    pair<int, int> res;
    // including all the nodes in current level
    res.first = root->data + leftSum.second + rightSum.second;
    // excluding all the nodes in current level
    res.second = max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second);

    return res;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
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
    // cout << "LCA is : " << lca(root, n1, n2)->data;
    cout << endl;
    int k = 5;
    cout << "K sum paths are : " << sumk(root, k);
    cout << endl;
    cout << "1 st ancestor of 8 is : " << kthAncestor(root, 8, 4);
    cout << endl;
    cout << "max sum excluding adjacent nodes is : " << getMaxSum(root);
}

// 1 3 -1 2 1 4 5 -2 -2 1 -2 1 2 -2 6 -2 -2 -2 -2 -2 -2 -2 -2
// 1 2 3 4 5 6 7 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1