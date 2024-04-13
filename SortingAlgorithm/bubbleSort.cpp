#include <iostream>
using namespace std;

void bubbleSort(int[], int);

int main(void)
{

    int a[] = {1, 5, 3, 4, 6, 2, 8, 7, 9, 0};
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    bubbleSort(a, sizeof(a) / sizeof(a[0]));
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    return 0;
}

void bubbleSort(int a[], int size)
{
    for (int round = 0; round < size - 1; ++round)
    {
        for (int i = 0; i < size - 1 - round; ++i)
        {
            if (a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        }
    }
}