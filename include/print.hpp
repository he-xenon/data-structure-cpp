#pragma

#include <iostream>
#include <stdlib.h>

using namespace std;

void myprint(int *arr, int size)
{
    if (arr == nullptr)
    {
        cout << "&arr address is Null" << endl;
        return;
    }

    cout << "current array size=" << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "]=" << arr[i] << endl;
        // printf("arr[%d]=%d\n", i , arr[i]);
    }
}

void myprint(vector<int> vec)
{
    if (vec.size() < 2)
    {
        cout << "vec.size() < 2, vec.size=" << vec.size() << endl;
        return;
    }
    cout << "current vector size=" << vec.size() << endl;
    //方式一
    /*for (int i = 0; i < vec.size(); i++)
    {
        cout << "vector[" << i << "]=" << vec[i] << endl;
        // printf("arr[%d]=%d\n", i , arr[i]);
    }*/

    //方式二
    int num = 0;
    for (auto it : vec)
    {
        cout << "vector[" << num << "]=" << it << endl;
        num++;
    }
}