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
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int main(void)
{
    node *root;
    buildTreeFromLevelOrder(root);
    cout << endl;
    levelOrder(root);

    return 0;
}