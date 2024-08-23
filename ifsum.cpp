#include <iostream>
using namespace std;
int main()
{
    char op;
    int a,b,sum,diff;
    cout << "Enter an operator:";
    cin >> op;
    cout << "Enter two integers:";
    cin >> a >> b;
    if (op == '+')
    {
        sum = a + b;
        cout << a << op << b << "=" << sum << '\n';
    }
    else if (op == '-')
    {

        diff = a - b;
        cout << a << op << b << "=" << diff << '\n';
    }
    else
    {
        cout << "unrecongised operator";
    }
    return 0;
}
