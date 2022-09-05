#pragma

#include <iostream>

using namespace std;

int swap(int &a, int &b)
{
    if( a == b)
    {
        return true;
    }
    // int temp = a;
    // a = b;
    // b = temp;
    
    //异或，两种定理：结合律，交换律
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return true;
}
