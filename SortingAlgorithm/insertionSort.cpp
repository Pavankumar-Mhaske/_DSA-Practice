#include <iostream>
using namespace std;

void insertionSort(int a[], int size);

int main(void)
{
    int a[] = {1, 5, 3, 4, 6, 2, 8, 7, 9, 0};
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    insertionSort(a, sizeof(a) / sizeof(a[0]));
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    return 0;
}

void insertionSort(int a[], int size)
{
    for (int i = 1; i < size; ++i)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            --j;
        }

        a[j + 1] = temp;
    }
}