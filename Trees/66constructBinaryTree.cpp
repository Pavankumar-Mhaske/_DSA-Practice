#include <iostream>
using namespace std;
#include <map>
#include <queue>

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int data) : left(nullptr), data(data), right(nullptr) {}
};

void postOrder(Node *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void inOrder(Node *root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
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
            cout << temp->data << ' ';
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// construct tree from InOrder and PreOrder
int findPosition(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node *solve1(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    if (preOrderIndex >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    };

    int element = pre[preOrderIndex++];
    Node *root = new Node(element);
    // int position = findPosition(in, element, n);
    int position = nodeToIndex[element];

    //
    root->left = solve1(in, pre, preOrderIndex, inOrderStart, position - 1, n, nodeToIndex);
    root->right = solve1(in, pre, preOrderIndex, position + 1, inOrderEnd, n, nodeToIndex);

    return root;
}

Node *buildTree1(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node *root = solve1(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return root;
}

// construct tree from InOrder and PostOrder

Node *solve(int in[], int post[], int &postOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int element = post[postOrderIndex--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // recursive calls....
    // for postOrder first build right sub-tree.
    root->right = solve(in, post, postOrderIndex, position + 1, inOrderEnd, n, nodeToIndex);
    root->left = solve(in, post, postOrderIndex, inOrderStart, position - 1, n, nodeToIndex);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    int postOrderIndex = n - 1;
    return solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
}

int main(void)
{
    // int in[] = {3, 1, 4, 0, 5, 2};
    // int pre[] = {0, 1, 3, 4, 2, 5};
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    // Node *root = buildTree1(in, pre, n);
    Node *root = buildTree(in, post, n);
    // postOrder(root);
    // cout << endl;
    // inOrder(root);
    preOrder(root);
    // cout << endl;
    // levelOrderTraversal(root);
    return 0;
}