//Raise integer to a positive integer power
#include <iostream>
#include <cstdlib>
using namespace std;
// int ipower(const int num, const int exp);

int main(int argc,char **argv)
{
    int num, exp;
    num = atoi(argv[1]);
    exp = atoi(argv[2]);
    cout << num << " to the power of " << exp << " is TBD\n";
    return 0;
}
