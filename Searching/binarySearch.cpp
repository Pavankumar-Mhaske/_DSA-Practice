#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int item);

int main(void)
{
    vector<int> v = {6, 3, 9, 5, 2, 8, 4};
    cout << "item found at index : " << binarySearch(v, 3);

    return 0;
}

int binarySearch(vector<int> &v, int item)
{
    int low = 0;
    int high = v.size() - 1;

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