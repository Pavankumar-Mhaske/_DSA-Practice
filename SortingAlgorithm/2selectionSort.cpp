#include <iostream>
using namespace std;

void selectionSort(int a[], int size);
int minval(int a[], int, int);
int main(void)
{
    int a[] = {1, 5, 3, 4, 6, 2, 8, 7, 9, 0};
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    selectionSort(a, sizeof(a) / sizeof(a[0]));
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    return 0;
}

int minval(int a[], int i, int size)
{
    int loc = i;
    for (int j = i + 1; j < size; ++j)
    {
        if (a[loc] > a[j])
            loc = j;
    }
    return loc;
}
void selectionSort(int a[], int size)
{

    for (int i = 0; i < size - 1; ++i)
    {
        // get minimum value index
        int loc = minval(a, i, size);
        // swap it to the index i
        // i<>loc
        if (loc != i)
            swap(a[i], a[loc]);
    }
}