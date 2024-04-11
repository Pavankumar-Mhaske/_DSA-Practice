#include <iostream>
#include <stdexcept>
using namespace std;

class stack
{
    int top;
    int capacity;
    int *ptr;

public:
    stack(int);
    ~stack();
    void createStack(int);
    void push(int);
    void pop(void);
    int peek();
    int getCapacity(void);
};
stack::stack(int capacity = 0)
{
    this->capacity = capacity;
    top = -1;
    ptr = NULL;
}
stack::~stack()
{
    if (ptr)
        delete[] ptr;
}
void stack::createStack(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
        if (ptr)
            delete[] ptr;
        ptr = new int[capacity];
    }
    else
    {
        throw runtime_error("Operation failed, invalid capacity !");
    }
}
void stack::push(int data)
{
    if (capacity > 0)
    {
        if (top == capacity - 1)
            throw runtime_error("Operation failed, StackOverFlow!");
        top++;
        ptr[top] = data;
    }
    else
    {
        throw runtime_error("Operation failed, stack doesn't exist !");
    }
}
void stack::pop(void)
{
    if (capacity > 0)
    {
        if (top < 0)
            throw runtime_error("Operation failed, Stack UnderFlow!");
        top--;
    }
    else
    {
        throw runtime_error("Operation failed, stack doesn't exist !");
    }
}
int stack::getCapacity(void)
{
    return capacity;
}
int stack::peek()
{
    if (capacity > 0)
    {
        if (top < 0)
            throw runtime_error("Operation failed, Stack UnderFlow!");
        return ptr[top];
    }
    else
    {
        throw runtime_error("Operation failed, stack doesn't exist !");
    }
}

int main(void)
{
    try
    {
        stack s;
        s.createStack(4);
        s.push(0);
        s.push(1);
        s.push(2);
        s.push(3);
        // s.push(4);
        cout << "Top is : " << s.peek() << endl;
        cout << "capacity : " << s.getCapacity() << endl;
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}