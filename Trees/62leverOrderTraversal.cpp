#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class node
{
public:
    node *left;
    int data;
    node *right;

    node(int data) : left(NULL), data(data), right(NULL) {}
};

node *buildTree(node *root)
{

    int data;
    cout << "Enter the data : ";
    cin >> data;
    if (data == -1)
        return NULL;

    root = new node(data);

    cout << "Enter the data to the left of : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to the right of : " << data << endl;
    root->right = buildTree(root->right);

    return root;
};

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

void rlevelOrderTraversal(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);
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

    s.pop();
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();

        if (temp == NULL)
            cout << endl;
        else
        {
            cout << temp->data << " ";
        }
    }
}

int main(void)
{

    node *root;
    root = buildTree(root);
    cout << endl;
    levelOrderTraversal(root);
    rlevelOrderTraversal(root);
    return 0;
}

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1