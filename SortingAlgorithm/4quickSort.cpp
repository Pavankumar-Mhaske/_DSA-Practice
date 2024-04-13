#include <iostream>
using namespace std;
void quickSort(int a[], int low, int high);

int main(void)
{
    int a[] = {6, 3, 9, 5, 2, 8};
    int size = sizeof(a) / sizeof(a[0]);
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    quickSort(a, 0, size - 1);
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    return 0;
}
int partition(int a[], int low, int high)
{
    int pivot = high;
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (a[j] < a[pivot])
        {
            i++;
            swap(a[j], a[i]);
        }
    }
    i++;
    swap(a[i], a[pivot]);
    return i;
}
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);

        quickSort(a, low, pivot - 1);
        quickSort(a, pivot + 1, high);
    }
}