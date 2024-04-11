#include <iostream>
#include <stdexcept>
using namespace std;

class stack
{
    struct node
    {
        int item;
        node *next;
    };
    node *start;

public:
    stack();
    ~stack();
    void push(int data);
    void pop(void);
    int peek(void);
};
stack::stack()
{
    start = NULL;
}
stack::~stack()
{
    while (start)
        pop();
}
void stack::push(int data)
{
    node *n = new node;
    n->item = data;
    n->next = start;
    // adding into the first position
    start = n;
}
void stack::pop(void)
{
    if (start)
    {
        node *p = start;
        start = start->next;
        delete p;
    }
}
int stack::peek(void)
{
    if (start)
        return start->item;
    
}

int main(void)
{

    try
    {
        stack s;
        s.push(0);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        cout << "Top is : " << s.peek() << endl;
        s.pop();
        cout << "Top is : " << s.peek() << endl;
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}