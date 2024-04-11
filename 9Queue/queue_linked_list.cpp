#include <iostream>
#include <stdexcept>
using namespace std;

class queue
{
    struct node
    {
        int item;
        node *next;
    };
    node *Front, *Rear;

public:
    queue();
    ~queue();
    void push(int data);
    void pop(void);
    int front(void);
    int rear(void);
};
queue::queue()
{
    Front = Rear = NULL;
}
queue::~queue()
{
    while (Front)
        pop();
}
void queue::push(int data)
{
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if (Front == NULL)
        Front = n;
    else
        Rear->next = n;
    Rear = n;
}
void queue::pop(void)
{
    if (Front)
    {
        node *p = Front;
        Front = Front->next;
        if (Front == Rear)
            Rear = NULL;
        delete p;
    }
    else
        throw runtime_error("Operation Failed, Queue UnderFlow!");
}
int queue::front(void)
{
    if (Front)
    {
        return Front->item;
    }
    else
        throw runtime_error("Operation Failed, Queue UnderFlow!");
}
int queue::rear(void)
{
    if (Front)
    {
        return Rear->item;
    }
    else
        throw runtime_error("Operation Failed, Queue UnderFlow!");
}

int main(void)
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Rear : " << q.rear() << " | "
         << "Front : " << q.front() << endl;
    q.pop();
    q.pop();
    q.push(6);
    cout << "Rear : " << q.rear() << " | "
         << "Front : " << q.front() << endl;

    return 0;
}