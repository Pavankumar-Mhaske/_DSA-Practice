#include <iostream>
#include <stdexcept>
using namespace std;

class Deque
{
    int capacity;
    int Head, Tail;
    // Haid = Front
    // Tail = Rear
    int *ptr;

protected:
    bool isFull(void);
    bool isEmpty(void);

public:
    Deque(int = 0);
    ~Deque();
    void show(void)
    {
        // cout << "Capacity : " << capacity << " | ";
        cout << "Head : " << Head << " | "
             << "Tail : " << Tail << " -" << endl;
    }
    void createDeque(int capacity);
    void pushFront(int data); // Haid
    void pushRear(int data);  // Tail
    void popFront(void);      // Haid
    void popRear(void);       // Tail
    int head(void);           // Front
    int tail(void);           // Rear
};

bool Deque::isFull(void)
{
    return (Head == 0 && Tail == capacity - 1 || Tail + 1 == Head);
}

bool Deque::isEmpty(void)
{
    return (Head == -1);
}

Deque::Deque(int capacity)
{
    capacity = 0;
    Head = Tail = -1;
    ptr = NULL;
}

Deque::~Deque()
{
    if (ptr)
        delete[] ptr;
}

void Deque::createDeque(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
        if (ptr)
            delete[] ptr;
        ptr = new int[capacity];
    }
    else
        throw runtime_error("Operation failed, invalid capacity!");
}

void Deque::pushFront(int data)
{
    if (ptr)
    {
        if (isFull())
            throw runtime_error("Operation failed, Deque OverFlow!");
        if (Head == -1)
        {
            Tail++;
            Head++;
        }
        else if (Head == 0)
            Head = capacity - 1;
        else
            Head--;
        ptr[Head] = data;
    }
    else
        throw runtime_error("Operation failed, Deque doesn't exist!");
}

void Deque::pushRear(int data)
{
    if (ptr)
    {
        if (isFull())
            throw runtime_error("Operation failed, Deque OverFlow!");
        if (Tail == -1)
        {
            Tail++;
            Head++;
        }
        else if (Tail == capacity - 1)
            Tail = 0;
        else
            Tail++;
        ptr[Tail] = data;
    }
    else
        throw runtime_error("Operation failed, Deque doesn't exist!");
}

void Deque::popFront(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Deque UnderFlow!");
        if (Head == Tail)
            Head = Tail = -1;
        else if (Head == capacity - 1)
            Head = 0;
        else
            Head++;
    }
    else
        throw runtime_error("Operation failed, Deque doesn't exist!");
}

void Deque::popRear(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Deque UnderFlow!");
        if (Head == Tail)
            Head = Tail = -1;
        else if (Tail == 0)
            Tail = capacity - 1;
        else
            Tail--;
    }
    else
        throw runtime_error("Operation failed, Deque doesn't exist!");
}

int Deque::head(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Deque UnderFlow!");
        return ptr[Head];
    }
    else
        throw runtime_error("Operation failed, Deque doesn't exist!");
}

int Deque::tail(void)
{
    if (ptr)
    {
        if (isEmpty())
            throw runtime_error("Operation failed, Deque UnderFlow!");
        return ptr[Tail];
    }
    else
        throw runtime_error("Operation failed, Deque doesn't exist!");
}

int main(void)
{
    try
    {

        Deque d;
        d.createDeque(6);
        // d.pushFront(1);
        // d.pushFront(2);
        // d.pushFront(3);
        // d.pushFront(4);
        // d.pushFront(5);
        // d.pushFront(6);
        d.pushRear(1);
        d.pushRear(2);
        d.pushRear(3);
        d.pushRear(4);
        d.pushRear(5);
        d.pushRear(6);
        // d.pushRear(7);
        d.show();
        cout << "Head : " << d.head() << " | "
             << "Tail : " << d.tail() << endl;
        cout << "---------------------------" << endl
             << endl;
        d.popFront();
        d.popFront();
        d.show();
        cout << "Head : " << d.head() << " | "
             << "Tail : " << d.tail() << endl;
        cout << "---------------------------" << endl
             << endl;

        d.pushRear(7);
        d.pushRear(8);
        // d.pushRear(9);
        // d.pushFront(7);
        // d.pushFront(8);
        // d.pushFront(8);
        d.show();
        cout << "Head : " << d.head() << " | "
             << "Tail : " << d.tail() << endl;
        cout << "---------------------------" << endl
             << endl;
        d.popRear();
        d.popFront();
        d.popFront();
        d.popFront();
        d.popFront();
        // d.popFront();
        d.show();
        cout << "Head : " << d.head() << " | "
             << "Tail : " << d.tail() << endl;
        cout << "---------------------------" << endl
             << endl;
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }
    return 0;
}