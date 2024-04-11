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
    bool isHalf(void);
    void doubleQueue(void);
    void halfQueue(void);

public:
    queue(int = 0);
    ~queue();
    int getCapacity(void);
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

bool queue::isHalf(void)
{
    return ((Rear + 1 - Front == capacity / 2) || (capacity - Front) + (Rear + 1) == capacity / 2);
}

void queue::doubleQueue(void)
{
    int prevCap = capacity;
    capacity = capacity * 2;
    int *newq = new int[capacity];
    int i = -1;
    while (Front != Rear)
    {
        newq[++i] = start[Front];
        if (Front == prevCap - 1)
            Front = -1;
        Front++;
    }
    newq[++i] = start[Front];
    Front = 0;
    Rear = i;
    delete[] start;
    start = newq;
}
void queue::halfQueue(void)
{
    int prevCap = capacity;
    capacity = capacity / 2;
    int *newq = new int[capacity];
    int i = -1;
    while (Front != Rear)
    {
        newq[++i] = start[Front];
        if (Front == prevCap - 1)
            Front = -1;
        Front++;
    }
    newq[++i] = start[Front];
    Front = 0;
    Rear = i;
    delete[] start;
    start = newq;
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
int queue::getCapacity(void)
{
    return capacity;
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
            // throw runtime_error("Opearation failed, Queue OverFlow!");
            doubleQueue();

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
        if (isHalf())
            halfQueue();
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
        q.createQueue(3);
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        cout << "Rear : " << q.rear() << " | "
             << "Front : " << q.front() << endl;
        cout << "capacity : " << q.getCapacity() << endl;
        q.pop();
        q.pop();
        q.push(6);
        cout << "Rear : " << q.rear() << " | "
             << "Front : " << q.front() << endl;
        cout << "capacity : " << q.getCapacity() << endl;

        q.push(7);
        q.push(8);
        q.push(9);
        cout << "Rear : " << q.rear() << " | "
             << "Front : " << q.front() << endl;
        cout << "capacity : " << q.getCapacity() << endl;

        q.push(10);
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }
    return 0;
}