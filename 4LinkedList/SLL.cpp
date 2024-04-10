#include <iostream>
#include <stdexcept>
using namespace std;

class SLL
{
    struct node
    {
        int data;
        node *next;
    };
    node *start;

public:
    SLL();
    ~SLL();
    void insertFirst(int data);
    void insertLast(int data);
    void insertAfter(int value, int data);
    void deleteFirst(void);
    void deleteLast(void);
    void deleteVal(int data);
    void view(void);
    int search(int data);
};

SLL::SLL()
{
    start = NULL;
}
SLL::~SLL()
{
    while (start)
        deleteFirst();
}
void SLL::insertFirst(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = start;
    start = temp;
}
void SLL::insertLast(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->next = NULL;

    if (start)
    {
        node *p = start;
        while (p->next)
            p = p->next;
        p->next = temp;
    }
    else
    {
        start = temp;
    }
}
void SLL::insertAfter(int value, int data)
{
    if (start)
    {
        node *p = start;
        while (p)
        {
            if (p->data == value)
                break;
            p = p->next;
        }
        if (p)
        {
            node *temp = new node;
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
        }
        else
            throw runtime_error("Operation Failed, Value Not Found!");
    }
    else
        throw runtime_error("Operation Failed, empty List!");
}
void SLL::deleteFirst(void)
{
    if (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
    else
        throw runtime_error("Operation Failed, empty List!");
}
void SLL::deleteLast(void)
{
    if (start)
    {
        node *p = start, *q = NULL;
        while (p->next)
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
            start = NULL;
        else
            q->next = NULL;
        delete p;
    }
    else
        throw runtime_error("Operation Failed, empty List!");
}
void SLL::deleteVal(int data)
{
    if (start)
    {
        node *p = start, *q = NULL;
        while (p)
        {
            if (p->data == data)
                break;
            q = p;
            p = p->next;
        }
        if (p)
        {
            if (q == NULL)
                start = start->next;
            else
                q->next = p->next;
            delete p;
        }
        else
            throw runtime_error("Operation failed, data not found!");
    }
    else
        throw runtime_error("Operation Failed, empty List!");
}
void SLL::view(void)
{
    if (start)
    {
        node *p = start;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
        throw runtime_error("Operation Failed, empty List!");
}

int SLL::search(int data)
{
    if (start)
    {
        node *p = start;
        while (p)
        {
            if (p->data == data)
                return 1;
            p = p->next;
        }
        return 0;
    }
    else
        throw runtime_error("Operation Failed, empty List!");
}

int main(void)
{
    try
    {
        SLL s;
        s.insertFirst(1);
        s.insertLast(2);
        s.insertAfter(2, 3);
        s.insertLast(4);
        s.insertLast(5);
        s.insertLast(6);
        s.view();
        // s.deleteFirst();
        // s.deleteLast();f
        // s.deleteVal(2);
        cout << "Item found or not ? " << s.search(55) << endl;
        

        s.view();
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }
    return 0;
}