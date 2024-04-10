#include <iostream>
using namespace std;

class DynamicArray
{
    int capacity;
    int lastIndex;
    int *ptr;

protected:
    void doubleArray(void);
    void halfArray(void);

public:
    DynamicArray();
    ~DynamicArray();
    int getCapacity(void);
    bool createArray(int capaciy);
    void append(int data);
    void insert(int index, int data);
    int count(void);
    int getItem(int index);
    int deleteItem(int index);
    void edit(int index, int data);
    int search(int data);
    void viewAll(void);
};

DynamicArray::DynamicArray()
{
    capacity = 0;
    lastIndex = -1;
    ptr = NULL;
}
DynamicArray::~DynamicArray()
{
    delete[] ptr;
}
int DynamicArray::getCapacity(void)
{
    return capacity;
}

void DynamicArray::doubleArray(void)
{
    capacity = capacity * 2;
    int *temp = new int[capacity];
    for (int i = 0; i < lastIndex + 1; ++i)
        temp[i] = ptr[i];

    delete[] ptr;
    ptr = temp;
}
void DynamicArray::halfArray(void)
{
    capacity = capacity / 2;
    int *temp = new int[capacity];
    for (int i = 0; i < lastIndex + 1; ++i)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}
bool DynamicArray::createArray(int capacity)
{
    this->capacity = capacity;
    if (ptr)
        delete[] ptr;
    ptr = new int[capacity];
}
void DynamicArray::append(int data)
{
    if (capacity == 0)
        throw runtime_error("Operation Failed, Array UnderFlow!");
    if (lastIndex == capacity - 1)
        // throw runtime_error("Operation Failed, Array OverFlow");
        doubleArray();

    lastIndex++;
    ptr[lastIndex] = data;
}
void DynamicArray::insert(int index, int data)
{
    if (capacity == 0)
        throw runtime_error("Operation Failed, Array UnderFlow!");
    if (index < 0 || index > lastIndex + 1)
        throw runtime_error("Operation Failed, Invalid Index!");
    if (lastIndex == capacity - 1)
        // throw runtime_error("Operation Failed, Array OverFlow");
        doubleArray();

    int i = lastIndex;
    while (i >= index)
    {
        ptr[i + 1] = ptr[i];
        --i;
    }
    ptr[index] = data;
    lastIndex++;
}
int DynamicArray::count(void)
{
    return (lastIndex + 1);
}
int DynamicArray::getItem(int index)
{
    if (index < 0 || index > lastIndex + 1)
        throw runtime_error("Operation Failed, Invalid Index!");
    return ptr[index];
}
int DynamicArray::deleteItem(int index)
{
    if (index < 0 || index > lastIndex + 1)
        throw runtime_error("Operation Failed, Invalid Index!");
    int i = index;
    while (i < lastIndex)
    {
        ptr[i] = ptr[i + 1];
        i++;
    }
    lastIndex--;
    if (lastIndex == (capacity / 2) - 1)
        halfArray();
}
void DynamicArray::edit(int index, int data)
{
    if (index < 0 || index > lastIndex)
        throw runtime_error("Operation Failed, Invalid Index!");
    ptr[index] = data;
}
int DynamicArray::search(int data)
{
    for (int i = 0; i < lastIndex + 1; ++i)
        if (ptr[i] == data)
            return i;
    return -1;
}
void DynamicArray::viewAll(void)
{
    for (int i = 0; i < lastIndex + 1; ++i)
        cout << ptr[i] << " ";
    cout << endl;
}

int main(void)
{
    try
    {

        DynamicArray d;
        d.createArray(6);

        d.append(0);
        d.append(1);
        d.append(2);
        d.append(3);
        d.append(5);
        d.viewAll();
        d.insert(4, 4);
        d.viewAll();

        cout << "Capacity is : " << d.getCapacity() << endl;
        // d.append(6);
        d.insert(6, 6);
        d.viewAll();

        cout << "Capacity is : " << d.getCapacity() << endl;
        d.append(7);
        d.append(8);
        d.append(9);
        d.viewAll();
        cout << "Capacity is : " << d.getCapacity() << endl;
        cout << endl;
        cout << "Count is : " << d.count() << endl;
        cout << "Item at index 2 : " << d.getItem(2) << endl;
        d.edit(9, 10);
        d.viewAll();
        cout << "element 7 is at index : " << d.search(7) << endl;
        }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}