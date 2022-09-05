#include "infa.h"

using namespace std;

//数组只有一种数为奇数次，其他数为偶数次
int printOddTimesNmu1(int *arr, int size)
{
    int eor = 0;
    for (auto i = 0; i < size; i++)
    {
        eor ^= arr[i];
    }
    return eor;
}

//数组只有2种数为奇数次，其他为偶数次
vector<int> printOddTimesNmu2(int *arr, int size)
{
    //数组有2种数为奇数次
    int eor = 0;
    for (auto i = 0; i < size; i++)
    {
        eor ^= arr[i];
    }
    // eor = a ^ b;
    // eor != 0;
    // eor必然有一位不为1
    int rightValue = eor & (~eor + 1); //提取出最右的1
    cout<< "rightValue=" << rightValue <<endl;
    int onlyOne = 0;
    for (auto i = 0; i < size; i++) 
    {
        if ((arr[i] & rightValue) == 0)
        {
            onlyOne ^= arr[i];
        }
    }
    int a = onlyOne;
    int b = eor ^ onlyOne;

    vector<int> vec;
    vec.push_back(a);
    vec.push_back(b);
    return vec;
}

int main(int argc, char const **argv)
{
    //数组
    int arr[] = {100, 9, 9, 5, 6, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int eor1 = printOddTimesNmu1(arr, size);
    cout << "eor1 = " << eor1 << endl;

    int arr2[] = {10, 33, 5, 6, 6, 5, 50,10 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> vec = printOddTimesNmu2(arr2, size2);
    cout << "a = " << vec[0] << endl;
    cout << "b = " << vec[1] << endl;

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
