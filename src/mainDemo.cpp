#include "infa.h"

using namespace std;

int main(int argc, char const **argv)
{
    int MaxSize = 5;
    int MaxValue = 10000;
    vector<int> arrTmp = generataRandomArray(MaxSize, MaxValue);
    myprint(arrTmp);

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
