#include <iostream>
using namespace std;
int main()
{
    int a,b,swap;
    cout << "enter 2 integers:";
    cin >> a >> b;
    if (a>b)
    {
        swap = a;
        a = b;
        b = swap;
    }
    if (a == b)
        cout << a << "=" << b << '\n';
    else
        cout << b << ">" << a << '\n';
    return 0;
}
