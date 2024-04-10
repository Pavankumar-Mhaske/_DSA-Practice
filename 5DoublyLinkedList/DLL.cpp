#include <iostream>
#include <stdexcept>
using namespace std;

class DLL
{

    struct node
    {
        node *prev;
        int data;
        node *next;
    };
    node *start;

public:
    DLL();
    ~DLL();
    void insertFirst(int data);
    void insertLast(int data);
    void insertAfter(int value, int data);
    void deleteFirst(void);
    void deleteLast(void);
    void deleteVal(int value);
    void view(void);
    int search(int value);
};
DLL::DLL()
{
    start = NULL;
}
DLL::~DLL()
{
    while (start)
        deleteFirst();
}
void DLL::insertFirst(int data)
{
    node *n = new node;
    n->prev = NULL;
    n->data = data;
    n->next = start;

    if (start)
        start->prev = n;

    start = n;
}
void DLL::insertLast(int data)
{
    node *n = new node;
    n->data = data;
    n->next = NULL;
    //
    if (start)
    {
        node *p = start;
        while (p->next)
            p = p->next;
        n->prev = p;
        // changes in list node
        p->next = n;
    }
    else
    {
        n->prev = NULL;
        start = n;
    }
}
void DLL::insertAfter(int value, int data)
{
    if (!start)
        throw runtime_error("Operation failed, List UnderFlow!");
    node *p = start;
    while (p)
    {
        if (p->data == value)
            break;
        p = p->next;
    }
    if (p)
    {
        // making the node full
        node *n = new node;
        n->prev = p;
        n->data = data;
        n->next = p->next;

        // changes in the list node
        // back node
        p->next = n;
        // next node;
        if (n->next)
            (n->next)->prev = n;
    }
    else
    {
        throw runtime_error("Operation failed, value not found!");
    }
}
void DLL::deleteFirst(void)
{
    if (!start)
        throw runtime_error("Operation failed, List UnderFlow!");
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        node *p = start;
        start = start->next;
        start->prev = NULL; // making prev = NULL of first node
        delete p;
    }
}
void DLL::deleteLast(void)
{
    if (!start)
        throw runtime_error("Operation failed, List UnderFlow!");
    if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        node *p = start;

        while (p->next)
            p = p->next;

        // making next = NULL of last node
        p->prev->next = NULL;
        delete p;
    }
}
void DLL::deleteVal(int value)
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
        if (start == p)
        {
            start = start->next;
            start->prev = NULL;
        }
        else
        {
            // changes in list nodes
            // changes in previous node
            p->prev->next = p->next;

            // changes in next node
            if (p->next)
                p->next->prev = p->prev;
        }
        delete p;
    }
    else
    {
        throw runtime_error("Operation failed, list UnderFlow or value not found!");
    }
}
void DLL::view(void)
{
    node *p = start;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int DLL::search(int value)
{
    node *p = start;
    while (p)
    {
        if (p->data == value)
            return 1;
        p = p->next;
    }
    return 0;
}

int main(void)
{
    try
    {
        DLL s;
        s.insertFirst(1);
        s.insertLast(2);
        s.insertAfter(2, 3);
        s.insertLast(4);
        s.insertLast(5);
        s.insertLast(6);
        s.view();
        s.deleteFirst();
        s.deleteLast();
        s.deleteVal(6);
        s.view();
        cout << "Item found or not ? " << s.search(6) << endl;

        s.view();
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}