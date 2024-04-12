#include <iostream>
#include <stdexcept>
// #include <stack>
#include <string>
using namespace std;

string infixToPostfix(string);
bool isOperand(char);
bool isOperator(char);
int getPriority(char);

class stack
{

    struct node
    {
        char item;
        node *next;
    };
    node *start;

public:
    stack();
    ~stack();
    void push(char data);
    char pop(void);
    char peek(void);
};

stack::stack()
{
    start = NULL;
}
stack::~stack()
{
    while (start)
        pop();
}
void stack::push(char data)
{
    node *n = new node;
    n->item = data;
    n->next = start;
    // changes in the list variable
    start = n;
}
char stack::pop(void)
{
    if (start)
    {
        char ch = start->item;
        node *p = start;
        start = start->next;
        delete p;
        return ch;
    }
    else
        throw runtime_error("Operation failed, Stack doesn't exist!");
}
char stack::peek(void)
{
    if (start)
    {
        return start->item;
    }
    else
        throw runtime_error("Operation failed, Stack doesn't exist!");
}

int main(void)
{
    try
    {
        string q = "A+((B+C)+(D+E)*F)/G";
        cout << "Q : " << q << endl;
        string p = infixToPostfix(q);
        cout << "P : " << p << endl;
        // int a = 'A', b = 'Z';
        // int c = 'a', d = 'z';
        // int e = '0', f = '9';
        // cout << a << " | " << b;
        // cout << endl;
        // cout << c << " | " << d;
        // cout << endl;
        // cout << e << " | " << f;
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }

    return 0;
}

bool isOperand(char ch)
{
    /*
        A = 65 | Z = 90
        a = 97 | z = 122
        0 = 48 | 9 = 57
    */
    return (ch > 47 && ch < 58 || ch > 64 && ch < 91 || ch > 96 && ch < 123);
}

bool isOperator(char ch)
{
    return (ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-');
}

int getPriority(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string q)
{

    stack s;
    string p;
    // step-1
    q = q + ")";
    s.push('(');
    int lengthOfExp = q.length();

    int i = -1;
    // step-2 - repeat the steps 3, 4, 5, 6 until reached to end of expresion;
    while (++i < lengthOfExp)
    {
        char ch = q[i];
        // step-3
        if (isOperand(ch))
        {
            // add to p;
            p = p + ch;
        }
        // step-4
        else if (isOperator(ch))
        {
            // pop all operators stack which have high or equal priority than ch;
            int priority = getPriority(ch);

            while (priority <= getPriority(s.peek()))
            {
                p = p + s.pop();
            }
            // push ch to the stack at last;
            s.push(ch);
        }
        // step-5
        else if (ch == '(')
        {
            // push to stack
            s.push(ch);
        }
        // step-6
        else if (ch == ')')
        {
            // pop things from stack until '(' is occured and add to the p;
            while (s.peek() != '(')
            {
                p = p + s.pop();
            }
            // remove the '(' from the stack at last;
            s.pop();
        }
    }
    return p;
}
