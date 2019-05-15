#include <iostream>
#include "tresMayor.h"
using namespace std;

int tresMayor(int a, int b, int c)
{
  if (a > b)
  {
    if (a > c)
    {
      return a;
    }
    else
    {
      return c;
    }
  }
  else if (b > a)
  {
    if (b > c)
    {
      return b;
    }
    else
    {
      return c;
    }
  }
  else
  {
    return c;
  }
}
