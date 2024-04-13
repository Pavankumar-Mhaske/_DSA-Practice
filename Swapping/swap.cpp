#include <iostream>
using namespace std;
// Internal implementaion of the swap function of c++
template <class T>
void swapping(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main(void)
{

    int a[] = {1, 2, 3, 4, 5};
    for (int val : a)
        cout << val << " ";
    cout << endl;

    swapping(a[0], a[1]);

    for (int val : a)
        cout << val << " ";
    cout << endl;
    return 0;
}
