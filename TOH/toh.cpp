#include <iostream>
#include <string>
using namespace std;
void toh(int, char = 'A', char = 'C');
int main(void)
{
    toh(3);
    return 0;
}
void toh(int n, char S, char D)
{
    if (n == 0 || S == D)
        return;
    char target;
    if (S + D == 'A' + 'B')
        target = 'C';
    else if (S + D == 'B' + 'C')
        target = 'A';
    else if (S + D == 'A' + 'C')
        target = 'B';
    /*  In C++, when you pass an argument like D = target in a function call such as toh(n - 1, S, D = target);,
        it indeed changes the value of D for the current call and all subsequent calls within the same expression.
        -    This is because C++ evaluates function arguments before making the actual function call.
             So, the assignment D = target is evaluated first, setting the value of D to target, and then
             the function toh is called with this modified value of D.
*/
    // toh(n - 1, S, D = target);
    toh(n - 1, S, target);
    cout << S << "->" << D << endl;
    // toh(n - 1, S = target, D);
    toh(n - 1, target, D);
}

void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from_peg << " to " << to_peg << endl;
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    cout << "Move disk " << n << " from " << from_peg << " to " << to_peg << endl;
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}
