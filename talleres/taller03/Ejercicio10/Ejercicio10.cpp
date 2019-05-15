#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    int f = 20, g = 20, i = 10, j = 10, k = 40;
    f <<= b - a;
    cout << "f: " << f << endl;
    g >>= a + b;
    cout << "g: " << f << endl;
    i &= a + b + c + d;
    cout << "i: " << f << endl;
    j |= a * b + c * d;
    cout << "j: " << f << endl;
    k ^= a + b + c + d;
    cout << "k: " << f << endl;
}

