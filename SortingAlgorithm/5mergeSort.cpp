#include <iostream>
using namespace std;

void mergeSort(int a[], int si, int ei);
void merge(int a[], int si, int mid, int ei);
int main(void)
{

    int a[] = {6, 3, 9, 5, 2, 8, 4};
    int size = sizeof(a) / sizeof(a[0]);
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    mergeSort(a, 0, size - 1);
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    return 0;
}

void merge(int a[], int si, int mid, int ei)
{
    int *merged = new int[ei - si + 1];
    int id1 = si;      // index for the first sub array
    int id2 = mid + 1; // index for the second sub array
    int x = 0;         // index for the merged array

    while (id1 <= mid && id2 <= ei)
    {
        if (a[id1] <= a[id2])
        {
            merged[x++] = a[id1++];
        }
        else
        {
            merged[x++] = a[id2++];
        }
    }

    // push all remaning elements of the 1 sub array
    while (id1 <= mid)
    {
        merged[x++] = a[id1++];
    }
    // push all remaning elements of the 2 sub array
    while (id2 <= ei)
    {
        merged[x++] = a[id2++];
    }
    // copy the sorted array into the original one
    int length = x;
    for (int i = 0, j = si; i < length; ++i, ++j)
    {

        a[j] = merged[i];
    }

    // release the DMA memory of the merged array
    delete[] merged;
}
void mergeSort(int a[], int si, int ei)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    // divide
    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, ei);
    // conquer
    merge(a, si, mid, ei);
}
