#include "infa.h"

using namespace std;

int bubbleSort(int *arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        if (arr == nullptr)
            cout << "&arr address is Null" << endl;
        if (size < 2)
            cout << "siez < 2, size=" << size << endl;
        return false;
    }

    for (auto i = size - 1; i > 0; i--)
    {
        for (auto j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return true;
}

int bubbleSort(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        cout << "siez < 2, vec.size()=" << vec.size() << endl;
        return false;
    }
    for (auto i = vec.size() - 1; i > 0; i--)
    {
        for (auto j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    return true;
}

int main(int argc, char const **argv)
{
    //生成随机数组
    int MaxSize = 5;
    int MaxValue = 10000;
    vector<int> vecTmp = generataRandomArray(MaxSize, MaxValue);
    myprint(vecTmp);
    vector<int> vec1 = copyArray(vecTmp);
    vector<int> vec2 = copyArray(vecTmp);

    //系统排序算法
    cout << "math sort algorithm start" << endl;
    sort(vec1.begin(), vec1.end(),
         [](int a, int b)
         {
             return a <= b ? true : false;
         });
    myprint(vec1);
    cout << "math sort algorithm end" << endl;

    //冒泡排序实现
    bubbleSort(vec2);
    myprint(vec2);

    int tmp = isEqual(vec1, vec2);
    if (tmp)
    {
        cout << "bubbleSort is Success" << endl;
    }
    else
    {
        cout << "bubbleSort is Fail" << endl;
    }

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
