#include "infa.h"

using namespace std;

int insertionSort(int *arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        if (arr == nullptr)
            cout << "*arr address is Null" << endl;
        if (size < 2)
            cout << "siez < 2, size=" << size << endl;
        return false;
    }
    for (auto i = 1; i < size; i++)
    {
        for (auto j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    return true;
}

int insertionSort(vector<int> &arr)
{
    if (arr.size() < 2)
    {
        cout << "arr.size() < 2, size=" << arr.size() << endl;
        return false;
    }
    for (auto i = 1; i < arr.size(); i++)
    {
        for (auto j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--)
        {
            swap(arr[j], arr[j + 1]);
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

    //插入排序实现
    insertionSort(vec2);
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
