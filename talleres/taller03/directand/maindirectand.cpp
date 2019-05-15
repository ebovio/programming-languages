#include <iostream>
#include "directand.cpp"

using namespace std;
int main(void)
{
    int a = 10000;
    int b = 20000;
    int c;
    int d;
    int e;
    cin >> c >> d >> e;

    a = c - d;
    b = d - e;
    if (directand(a, b))
    {
        cout << "a y b son mayores que cero" << endl;
    }
    cout << "a : " << a << " b : " << b
         << endl;
    return 0;
}