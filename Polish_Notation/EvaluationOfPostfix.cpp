#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char);
double operation(double, double, char);
int getValue(char);
double evaluatePostfix(const string &);

int main(void)
{
    try
    {

        // string s = "123+2*2*+3+";
        string s = "123+34+5*+6/+";
        cout << evaluatePostfix(s);
    }
    catch (const std::runtime_error &e)
    {
        cerr << "Error : " << e.what() << endl;
    }
    return 0;
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
double operation(double x, double y, char token)
{
    if (token == '+')
        return y + x;
    else if (token == '-')
        return y - x;
    else if (token == '*')
        return y * x;
    else if (token == '/')
        return y / x;
    else
        throw invalid_argument("Invalid operator for the operation!");
}
int getValue(char ch)
{
    return ch - '0';
}

double evaluatePostfix(const std::string &postfix)
{

    stack<double> s;
    // postfix = postfix + ')'

    for (auto token : postfix)
    {

        if (isdigit(token))
        {

            // push to the stack;
            double v = getValue(token);
            s.push(v);
        }
        else if (isOperator(token))
        {
            // let's say the operator encountered is #
            // pop two values from the stack: such that first pop - x , second pop - y;
            // evaluate y # x;
            // push the result back to the stack
            double x, y, result;
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            result = operation(x, y, token);
            s.push(result);
        }
    }

    return s.top();
}