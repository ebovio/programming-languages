#include <iostream>

using namespace std;

int
main(void) {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8};

  int *pA = &a[0];

  cout << *pA << endl;

  cout << *(pA + 1) << endl;

  cout << a[1] << endl;

  cout << sizeof(a[0]) << endl;
  cout << sizeof(a) << endl;

  cout << *pA++ << endl;

  for (int i = 1000000; i >= 0; --i) {
    cout << *(pA - i) << endl;
  }
}
