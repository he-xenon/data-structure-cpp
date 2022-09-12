#include "infa.h"

using namespace std;

int main(int argc, char const **argv)
{
    //随机数测试
    int maxSize = 5;
    int maxValue = 1000;
    int timeSize = 5;
    srand((unsigned int)time(nullptr)); //产生随机种子
    for (auto i = 0; i < timeSize; i++)
    {
        vector<int> vec = generataRandomArray(maxSize, maxValue);
        myprint(vec);
    }

    //生成随机数组
    // int MaxSize = 5;
    // int MaxValue = 10000;
    // vector<int> vecTmp = generataRandomArray(MaxSize, MaxValue);
    // myprint(vecTmp);
    // vector<int> vec1 = copyArray(vecTmp);
    // vector<int> vec2 = copyArray(vecTmp);

    // //系统排序算法
    // cout << "math sort algorithm start" << endl;
    // sort(vec1.begin(), vec1.end(),
    //      [](int a, int b)
    //      {
    //          return a <= b ? true : false;
    //      });
    // myprint(vec1);
    // cout << "math sort algorithm end" << endl;

    /*
    //选择排序实现
    selectionSort(vec2);
    myprint(vec2);
    
    //测试
    int tmp = isEqual(vec1, vec2);
    if (tmp)
    {
        cout << "bubbleSort is Success" << endl;
    }
    else
    {
        cout << "bubbleSort is Fail" << endl;
    }
    */
    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
