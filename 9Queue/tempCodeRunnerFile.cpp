#include <iostream>
#include <stdexcept>
using namespace std;

class queue
{
    int capacity;
    int Front, Rear;
    int *start;

protected:
    bool isFull(void);
    bool isEmpty(void);

public:
    queue(int = 0);
    ~queue();
    void createQueue(int capacity);
    void push(int data);
    void pop(void);
    int front(void);
    int rear(void);
};
bool queue::isFull(void)
{
    if (Front == 0 && Rear == capacity - 1 || Rear + 1 == Front)
        return true;
    return false;
}
bool queue::isEmpty(void)
{
    if (Front == -1)
        return true;
    return false;
}

queue::queue(int capacity)
{
    this->capacity = capacity;
    Front = -1;
    Rear = -1;
    start = NULL;
}

queue::~queue()
{
    if (start)
        delete[] start;
}

void queue::createQueue(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
        if (start)
            delete[] start;
        start = new int[capacity];
    }
    else
        throw runtime_error("Operation failed, invalid capacity!");
}

void queue::push(int data)
{
    if (start)
    {
        if (isFull())
        {
            throw runtime_error("Opearation failed, Queue OverFlow!");
        }
        // First time push
        if (Front == -1)
            Front++;

        // push after reaching to the end (again travel to the start for pushing)
        if (Rear == capacity - 1)
            Rear = -1;

        // add element
        start[++Rear] = data;
    }
    else
        throw runtime_error("Operation failed, queue doesn't exist!");
}

void queue::pop(void)
{
    if (start)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Queue Underflow!");
        if (Front == Rear)
            Front = Rear = -1;
        else if (Front == capacity - 1)
            Front = 0;
        else
            Front++;
    }
    else
        throw runtime_error("Operation failed, queue doesn't exist!");
}
int queue::front(void)
{
    if (start)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Queue Underflow!");
        return start[Front];
    }
    else
        throw runtime_error("Operation failed, queue doesn't exist!");
}
int queue::rear(void)
{
    if (start)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Queue Underflow!");
        return start[Rear];
    }
    else
        throw runtime_error("Operation failed, queue doesn't exist!");
}

int main(void)
{
    try
    {
        queue q;
        q.createQueue(5);
        q.push(1);
        q.push(2);
        cout << "Rear : " << q.rear() << " | "
             << "Front : " << q.front() << endl;
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }
    return 0;
}