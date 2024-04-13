#include <iostream>
using namespace std;

void quick(int a[], int beg, int end, int &loc);
void quickSort(int a[], int n);
int main(void)
{
    int a[] = {6, 3, 9, 5, 2, 8};
    int size = sizeof(a) / sizeof(a[0]);
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    quickSort(a, size);
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    return 0;
}

void quick(int a[], int beg, int end, int &loc)
{
    // 1
    int left = beg, right = end;
    loc = beg;

    while (1)
    {
        // 2
        while (a[loc] <= a[right] && loc != right)
        {
            right--;
        }
        if (loc == right)
            return;
        if (a[loc] > a[right])
        {
            swap(a[loc], a[right]);
            loc = right;
        }
        // 3
        while (a[left] <= a[loc] && left != loc)
        {
            left++;
        }
        if (left == loc)
            return;
        if (a[left] > a[loc])
        {
            swap(a[left], a[loc]);
            loc = left;
        }
    }
}
void quickSort(int a[], int n)
{

    int top = -1;
    int lower[10], upper[10];
    top++;
    lower[top] = 0;
    upper[top] = n - 1;
    int loc;
    while (top != -1)
    {
        int beg = lower[top], end = upper[top];
        top--;
        quick(a, beg, end, loc);
        if (beg < loc - 1)
        {
            top++;
            lower[top] = beg;
            upper[top] = loc - 1;
        }
        if (loc + 1 < end)
        {
            top++;
            lower[top] = loc + 1;
            upper[top] = end;
        }
    }
}