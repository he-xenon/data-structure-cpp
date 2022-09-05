#include "infa.h"

using namespace std;

int main(int argc, char const **argv)
{
    int a = 1;
    int b = 3;
    int c = a + b;
    printf("a+b =%d \n", c);

    int var1 = 10;
    int var2 = 20;
    int arr[]={20,30,60,10};
    cout << "Before swap" << endl;
    cout << "var1 =" << var1 << endl;
    cout << "var2 =" << var2 << endl;
    swap(var1, var2);
    cout << "After swap" << endl;
    cout << "var1 =" << var1 << endl;
    cout << "var2 =" << var2 << endl;

    swap(arr[0],arr[3]);
    myprint(arr,4);

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
