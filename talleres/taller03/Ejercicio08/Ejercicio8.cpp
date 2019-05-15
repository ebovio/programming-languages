#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2, c = 3, d = 4;
    int f, g, h, i, j, k;
    f = b << a + b >> a;
    cout << "F: " << f << endl;
    g = (b << a) + b >> a;
    cout << "G: " << g << endl;
    h = b & d + a & c;
    cout << "H: " << h << endl;
    i = (b & d) + (a & c);
    cout << "I: " << i << endl;
    j = b | d + a | c;
    cout << "J: " << j << endl;
    k = (b | d) + (a | c);
    cout << "K: " << k << endl;

    return 0;
}