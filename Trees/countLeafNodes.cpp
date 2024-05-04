#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;

    node(int data) : left(NULL), data(data), right(NULL) {}
};

void buildFromLevelOrder(node *&root)
{
    cout << "Enter the root data : ";
    int data;
    cin >> data;
    if (data == -1)
    {
        root = nullptr;
        return;
    }
    queue<node *> q;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter data left of - " << temp->data << " : ";
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter data right of - " << temp->data << " : ";
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void levelOrder(node *root, int &count)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

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
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            if (!temp->left && !temp->right)
                count++;
        }
    }
}

int main(void)
{
    node *root;
    buildFromLevelOrder(root);
    cout << endl;

    int count = 0;
    levelOrder(root, count);
    cout << "count of the leaf nodes are : " << count;

    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1 