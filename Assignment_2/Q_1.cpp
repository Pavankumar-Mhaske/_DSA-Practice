#include <iostream>
#include <stdexcept>
using namespace std;

class ArrayADT
{
    int capacity;
    int lastIndex;
    int *ptr;

public:
    ArrayADT();
    ~ArrayADT();
    void createArray(int);
    void append(int);
    void insert(int, int);
    int count(void);
    int getItem(int);
    int deleteItem(int);
    void edit(int, int);
    int search(int);
    void viewAll(void);
};

ArrayADT::ArrayADT() : capacity(0), lastIndex(-1)
{
    ptr = NULL;
}
ArrayADT::~ArrayADT()
{
    if (ptr)
        delete[] ptr;
}

void ArrayADT::createArray(int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
        lastIndex = -1;
        ptr = new int[capacity];
        return;
    }
    throw runtime_error("Invalid capacity!, Capacity should be greater than 0");
}
void ArrayADT::append(int data)
{
    if (lastIndex == capacity - 1)
        throw runtime_error("Operation Failed, Array OverFlow!");

    lastIndex++;
    ptr[lastIndex] = data;
}
void ArrayADT::insert(int index, int data)
{
    if (index < 0 || index > lastIndex + 1)
        throw runtime_error("Operation Failed, Invalid Index!");
    else if (lastIndex == capacity - 1)
        throw runtime_error("Operation Failed, Array OverFlow!");
    else
    {
        // for (int i = lastIndex; i >= index; --i)
        //     ptr[i + 1] = ptr[i];
        int i = lastIndex;
        while (i >= index)
        {
            ptr[i + 1] = ptr[i];
            --i;
        }
        ptr[index] = data;
        lastIndex++;
    }
}
int ArrayADT::count(void)
{
    return (lastIndex + 1);
}
int ArrayADT::getItem(int index)
{
    if (index < 0 || index > lastIndex)
        throw runtime_error("Operation Failed, Invalid Index!");

    return ptr[index];
}
int ArrayADT::deleteItem(int index)
{
    if (index < 0 || index > lastIndex)
        throw runtime_error("Operation Failed, Invalid Index!");
    int i = index;
    while (i < lastIndex)
    {
        ptr[i] = ptr[i + 1];
        i++;
    }
    lastIndex--;
}
void ArrayADT::edit(int index, int data)
{
    if (index < 0 || index > lastIndex)
        throw runtime_error("Operation Failed, Invalid Index!");
    ptr[index] = data;
}
int ArrayADT::search(int data)
{

    for (int i = 0; i < lastIndex + 1; ++i)
        if (ptr[i] == data)
            return i;

    return -1;
}
void ArrayADT::viewAll(void)
{
    for (int i = 0; i < lastIndex + 1; ++i)
        cout << ptr[i] << " ";
    cout << endl;
}

int main(void)
{
    ArrayADT a;
    try
    {

        a.createArray(10);
        a.append(0);
        a.append(1);
        a.append(2);
        a.append(3);
        a.append(4);
        a.append(5);
        a.append(6);
        a.append(7);
        a.insert(8, 8);
        a.viewAll();
        cout << "count : " << a.count() << endl;
        cout << "item at index : " << a.getItem(8) << endl;
        a.deleteItem(8);
        a.viewAll();
        a.edit(0, 8);
        cout << "Item is at index : " << a.search(1) << endl;
        a.viewAll();
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}