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

Node *solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
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
    root->left = solve(in, pre, preOrderIndex, inOrderStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, preOrderIndex, position + 1, inOrderEnd, n, nodeToIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node *root = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return root;
}

int main(void)
{
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = 6;
    Node *root = buildTree(in, pre, n);
    postOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    // levelOrderTraversal(root);
    return 0;
}