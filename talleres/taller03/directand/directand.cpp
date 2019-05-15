#include <iostream>
#include "directand.h"
using namespace std;

bool directand(int leftExpr, int rightExpr)
{
    if (leftExpr > 0 && rightExpr > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}