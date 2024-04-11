#include <iostream>
#include <stdexcept>
using namespace std;
class PriorityQueue
{
    int capacity;
    int Front1, Rear1;
    int Front2, Rear2;
    int Front3, Rear3;
    int Front4, Rear4;
    int Front5, Rear5;
    int *ptr;

protected:
    bool isFull(int, int);
    bool isEmpty(void);
    int getPriority(int);
    int getHighestPriority(void);
    int getLowestPriority(void);
    void popItem(int &Front, int &Rear);
    int getRear(void);
    int getFront(void);

public:
    PriorityQueue();
    ~PriorityQueue();
    void createQueue(int capacity);
    void push(int data);
    void pop(void);
    int front(void);
    int rear(void);
    void showVal(void);
};

void PriorityQueue::showVal(void)
{
    cout << endl;
    cout << "Capacity : " << capacity << endl;
    cout << "Front1 : " << Front1 << " | Rear1 : " << Rear1 << endl;
    cout << "Front2 : " << Front2 << " | Rear2 : " << Rear2 << endl;
    cout << "Front3 : " << Front3 << " | Rear3 : " << Rear3 << endl;
    cout << "Front4 : " << Front4 << " | Rear4 : " << Rear4 << endl;
    cout << "Front5 : " << Front5 << " | Rear5 : " << Rear5 << endl;
    cout << endl;
}

bool PriorityQueue::isFull(int Front, int Rear)
{
    return (Front == 0 && Rear == capacity - 1 || Rear + 1 == Front);
}

bool PriorityQueue::isEmpty(void)
{
    int highestPriority = getHighestPriority();

    // if (highestPriority == 5 || highestPriority == 4 || highestPriority == 3 || highestPriority == 2 || highestPriority == 1)
    if (highestPriority > 0 && highestPriority < 6)
        return false;
    return true;
}

int PriorityQueue::getPriority(int val)
{
    if (val > 50)
        return 5;
    else if (val > 40)
        return 4;
    else if (val > 30)
        return 3;
    else if (val > 20)
        return 2;
    else
        return 1;
}

int PriorityQueue::getHighestPriority(void)
{
    if (Front5 > -1)
        return 5;
    else if (Front4 > -1)
        return 4;
    else if (Front3 > -1)
        return 3;
    else if (Front2 > -1)
        return 2;
    else if (Front1 > -1)
        return 1;
    return 0;
}

int PriorityQueue::getLowestPriority(void)
{
    if (Front1 > -1)
        return 1;
    else if (Front3 > -1)
        return 2;
    else if (Front3 > -1)
        return 3;
    else if (Front4 > -1)
        return 4;
    else if (Front5 > -1)
        return 5;
    return 0;
}

void PriorityQueue::popItem(int &Front, int &Rear)
{
    if (Front == Rear)
        Front = Rear = -1;
    else if (Front == capacity - 1)
        Front = 0;
    else
        Front++;
}

int PriorityQueue::getRear(void)
{
    int highestPriority = getLowestPriority();

    // Smallest will delete last
    if (highestPriority == 1)
        return Rear1;
    else if (highestPriority == 2)
        return Rear2;
    else if (highestPriority == 3)
        return Rear3;
    else if (highestPriority == 4)
        return Rear4;
    else if (highestPriority == 5)
        return Rear5;
}

int PriorityQueue::getFront(void)
{
    int highestPriority = getHighestPriority();

    //  Largest will delete first
    if (highestPriority == 5)
        return Front5;
    else if (highestPriority == 4)
        return Front4;
    else if (highestPriority == 3)
        return Front3;
    else if (highestPriority == 2)
        return Front2;
    else if (highestPriority == 1)
        return Front1;
}

PriorityQueue::PriorityQueue()
{
    capacity = 0;
    Front1 = Rear1 = -1;
    Front2 = Rear2 = -1;
    Front3 = Rear3 = -1;
    Front4 = Rear4 = -1;
    Front5 = Rear5 = -1;
    ptr = NULL;
}

PriorityQueue::~PriorityQueue()
{
    if (ptr)
        delete[] ptr;
}

void PriorityQueue::createQueue(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
        ptr = new int[capacity * 5];
    }
    else
        throw runtime_error("Operation failed, invalid capacity!");
}

void PriorityQueue::push(int data)
{
    if (ptr)
    {
        int priority = getPriority(data);
        if (priority == 5)
        {
            if (isFull(Front5, Rear5))
                throw runtime_error("Operation failed, Queue OverFlow!");

            // First time push
            if (Front5 == -1)
                Front5++;

            // push after reaching to the end (again travel to the start for pushing)
            if (Rear5 == capacity - 1)
                Rear5 = -1;

            // add element
            ptr[capacity * (priority - 1) + (++Rear5)] = data;
            cout << "Rear : " << Rear5 << endl;
        }
        else if (priority == 4)
        {
            if (isFull(Front4, Rear4))
                throw runtime_error("Operation failed, Queue OverFlow!");

            // First time push
            if (Front4 == -1)
                Front4++;

            // push after reaching to the end (again travel to the start for pushing)
            if (Rear4 == capacity - 1)
                Rear4 = -1;

            // add element
            ptr[capacity * (priority - 1) + (++Rear4)] = data;
        }
        else if (priority == 3)
        {
            if (isFull(Front3, Rear3))
                throw runtime_error("Operation failed, Queue OverFlow!");

            // First time push
            if (Front3 == -1)
                Front3++;

            // push after reaching to the end (again travel to the start for pushing)
            if (Rear3 == capacity - 1)
                Rear3 = -1;

            // add element
            ptr[capacity * (priority - 1) + (++Rear3)] = data;
        }
        else if (priority == 2)
        {
            if (isFull(Front2, Rear2))
                throw runtime_error("Operation failed, Queue OverFlow!");

            // First time push
            if (Front2 == -1)
                Front2++;

            // push after reaching to the end (again travel to the start for pushing)
            if (Rear2 == capacity - 1)
                Rear2 = -1;

            // add element
            ptr[capacity * (priority - 1) + (++Rear2)] = data;
        }
        else
        {
            if (isFull(Front1, Rear1))
                throw runtime_error("Operation failed, Queue OverFlow!");

            // First time push
            if (Front1 == -1)
                Front1++;

            // push after reaching to the end (again travel to the start for pushing)
            if (Rear1 == capacity - 1)
                Rear1 = -1;

            // add element
            ptr[capacity * (priority - 1) + (++Rear1)] = data;
        }
    }
    else
        throw runtime_error("Operation failed, Queue doesn't exist!");
}

void PriorityQueue::pop(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Queue UnderFlow!");

        int highestPriority = getHighestPriority();

        if (highestPriority == 5)
            popItem(Front5, Rear5);
        else if (highestPriority == 4)
            popItem(Front4, Rear4);
        else if (highestPriority == 3)
            popItem(Front3, Rear3);
        else if (highestPriority == 2)
            popItem(Front2, Rear2);
        else if (highestPriority == 1)
            popItem(Front1, Rear1);
    }
    else
        throw runtime_error("Operation failed, Queue doesn't exist!");
}

int PriorityQueue::front(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Queue UnderFlow!");

        int highestPriority = getHighestPriority();
        int Front = getFront();

        return ptr[capacity * (highestPriority - 1) + Front];
    }
    else
        throw runtime_error("Operation failed, Queue doesn't exist!");
}

int PriorityQueue::rear(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Queue UnderFlow!");

        int lowestPriority = getLowestPriority();
        int Rear = getRear();

        return ptr[capacity * (lowestPriority - 1) + Rear];
    }
    else
        throw runtime_error("Operation failed, Queue doesn't exist!");
}

int main(void)
{

    try
    {
        PriorityQueue pq;
        pq.createQueue(3);
        pq.push(10);
        pq.push(20);
        pq.push(60);
        pq.push(70);
        pq.push(80);
        pq.push(30);
        pq.push(40);
        pq.push(50);
        cout << "Rear : " << pq.rear() << " | "
             << "Front : " << pq.front() << endl;
        pq.showVal();
        pq.pop();
        pq.pop();
        pq.push(70);

        pq.pop();
        pq.pop();
        // pq.pop();
        // pq.pop();
        // pq.pop();
        // pq.pop();
        // // pq.push(6);
        cout << "Rear : " << pq.rear() << " | "
             << "Front : " << pq.front() << endl;
        pq.showVal();
        // pq.push(60);
        // pq.push(70);
        // cout << "Rear : " << pq.rear() << " | "
        //      << "Front : " << pq.front() << endl;
        // pq.push(80);
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }
    return 0;
}