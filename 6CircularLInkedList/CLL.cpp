#include <iostream>
#include <stdexcept>
using namespace std;

class CLL
{
    struct node
    {
        int item;
        node *next;
    };
    node *last;

public:
    CLL();
    ~CLL();
    void insertFirst(int data);
    void insertLast(int data);
    void insertAfter(int value, int data);
    void deleteFirst(void);
    void deleteLast(void);
    void deleteVal(int value);
    void view(void);
    int search(int value);
};

CLL::CLL()
{
    last = NULL;
}
CLL::~CLL()
{
    while (last)
        deleteFirst();
}
void CLL::insertFirst(int data)
{

    node *n = new node;
    n->item = data;
    if (last)
    {
        n->next = last->next;
        // changes in list nodes
        last->next = n;
    }
    else
    {
        n->next = n;
        last = n;
    }
}
void CLL::insertLast(int data)
{
    node *n = new node;
    n->item = data;
    if (last)
    {
        n->next = last->next;
        // changes in list node
        last->next = n;
    }
    else
    {
        n->next = n;
    }
    last = n;
}
void CLL::insertAfter(int value, int data)
{
    if (!last)
        throw runtime_error("Operation failed, list underflow!");

    node *p = last;
    do
    {
        if (p->item == value)
            break;
        p = p->next;
    } while (p != last);

    if (p->item == value)
    {
        node *n = new node;
        n->item = data;
        n->next = p->next;
        // changes in list node
        p->next = n;
        if (p == last)
            last = n;
    }
    else
    {
        throw runtime_error("Operation failed, value not found!");
    }
}
void CLL::deleteFirst(void)
{
    if (!last)
        throw runtime_error("Operation failed, list underflow!");
    if (last->next == last)
    {
        delete last;
        last = NULL;
    }
    else
    {
        node *p = last->next;
        // changes in list node
        last->next = p->next;

        delete p;
    }
}
void CLL::deleteLast(void)
{
    if (!last)
        throw runtime_error("Operation failed, list underflow!");
    if (last->next == last)
    {
        delete last;
        last = NULL;
    }
    else
    {
        node *p = last;

        while (p->next != last)
            p = p->next;

        p->next = last->next;
        delete last;
        last = p;
    }
}
void CLL::deleteVal(int value)
{
    if (!last)
        throw runtime_error("Operation failed, list underflow!");
    node *p = last, *q = NULL;
    do
    {
        if (p->item == value)
            break;
        q = p;
        p = p->next;

    } while (p != last);

    if (p->item == value)
    {
        if (q)
        {
            q->next = p->next;
            if (q->next == last)
                last = q;
            delete p;
        }
        else // first time in iteration got the value
        {
            // only node in list
            if (p->next == p)
            {
                delete last;
                last = NULL;
            }
            // more than one node
            else
            {
                do
                {
                    q = p;
                    p = p->next;

                } while (p != last);
                q->next = p->next;
                delete p;
            }
        }
    }
    else
    {
        throw runtime_error("Operation failed, value not found!");
    }
}
void CLL::view(void)
{
    if (!last)
        throw runtime_error("Operation failed, list underflow!");
    node *p = last->next;
    do
    {
        cout << p->item << " ";
        p = p->next;
    } while (p != last->next);
    cout << endl;
}
int CLL::search(int value)
{
    if (!last)
        throw runtime_error("Operation failed, list underflow!");

    node *p = last;
    do
    {
        if (p->item == value)
            return 1;
        p = p->next;
    } while (p != last);
    return 0;
}

int main(void)
{
    try
    {
        CLL s;
        s.insertFirst(1);
        s.view();
        s.insertLast(2);
        s.insertAfter(2, 3);
        s.insertLast(4);
        s.insertLast(5);
        s.insertLast(6);
        s.deleteFirst();
        s.deleteLast();
        s.deleteVal(2);
        s.view();
        cout << "Item found or not ? " << s.search(4) << endl;

        s.view();
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}