#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int item);
void divide(vector<int> &v, int si, int ei);
void conquer(vector<int> &v, int si, int mid, int ei);

int main(void)
{
    vector<int> v = {16, 13, 9, 8, 4, 2, 3};

    cout << "item found at index : " << binarySearch(v, 3) << endl;
    for (auto val : v)
        cout << val << " ";
    cout << endl;

    return 0;
}

void conquer(vector<int> &v, int si, int mid, int ei)
{
    int *merged = new int[ei - si + 1];
    int id1 = si;
    int id2 = mid + 1;
    int x = 0;

    while (id1 <= mid && id2 <= ei)
    {
        // Scan from the both the sub list and sort them into new list
        if (v[id1] <= v[id2])
        {
            merged[x++] = v[id1++]; // push element of fist sublist into the merged list
        }
        else
        {
            merged[x++] = v[id2++]; // push element of second sublist into the merged list
        }
    }

    while (id1 <= mid)
    {
        // push remaning elements of first sublist into the merged
        merged[x++] = v[id1++]; // push element of fist sublist into the merged list
    }

    while (id2 <= ei)
    {
        // push remaning elements of second sublist into the merged
        merged[x++] = v[id2++]; // push element of second sublist into the merged list
    }

    // now x will became the length of the merged list
    // so copy all the data of the sorted data of merged into original list
    for (int i = 0, j = si; i < x; ++i, ++j)
    {
        v[j] = merged[i];
    }
    delete[] merged;
}

void divide(vector<int> &v, int si, int ei)
{
    if (si >= ei)
        return;
    // Divide
    int mid = si + (ei - si) / 2;
    divide(v, si, mid);
    divide(v, mid + 1, ei);
    // Conquer
    conquer(v, si, mid, ei);
}

int binarySearch(vector<int> &v, int item)
{
    int low = 0;
    int high = v.size() - 1;

    divide(v, low, high);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (item == v[mid])
            return mid;
        else if (item < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}