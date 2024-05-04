#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;

    node(int data) : data(data), left(NULL), right(NULL){};
};

node *buildBinaryTree(node *root)
{
    cout << "Enter a data : ";
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter the data for left of : " << data << endl;
    root->left = buildBinaryTree(root->left);

    cout << "Enter the data for right of : " << data << endl;
    root->right = buildBinaryTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter the root data : ";
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

        cout << "Enter the left of : " << temp->data << "  ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter the right of : " << temp->data << "  ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main(void)
{
    node *root = NULL;
    // root = buildBinaryTree(root);
    buildFromLevelOrder(root);
    cout << endl;
    cout << root->data << endl
         << endl;
    levelOrderTraversal(root);
    return 0;
}

// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1