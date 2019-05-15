#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int a = 10;
    bool b = true;
    char c = 'c';
    double d = 10.20;
    cout
        << setw(5) << left << a << boolalpha << b
        << setw(2) << right << c << setw(10) << right << d << endl;
    return 0;
}