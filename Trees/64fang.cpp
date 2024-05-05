#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;
    node(int data) : left(nullptr), data(data), right(nullptr){};
};

void buildLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter the root data : ";
    int data;
    cin >> data;

    if (data == -1)
    {
        root = NULL;
        return;
    }

    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *frontNode = q.front();
        q.pop();

        cout << "Enter data to the left of : " << frontNode->data << " : ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            frontNode->left = new node(leftData);
            q.push(frontNode->left);
        }

        cout << "Enter data to the right of : " << frontNode->data << " : ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            frontNode->right = new node(rightData);
            q.push(frontNode->right);
        }
    }
}

void levelOrder(node *root)
{
    queue<node *> q;
    if (root == NULL)
    {
        return;
    }
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
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

vector<int> zigzag(node *root)
{
    vector<int> result;
    queue<node *> q;
    q.push(root);
    bool rightToLeft = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> v(size);

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
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

int main(void)
{
    node *root;
    buildLevelOrder(root);
    cout << endl;
    levelOrder(root);
    vector<int> v = zigzag(root);
    for (auto val : v)
        cout << val << " ";
    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1