#include "infa.h"

using namespace std;

int selectionSort(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        cout << "vector.size() < 2, vector.size()=" << vec.size() << endl;
        return false;
    }

    for (auto i = 0; i < vec.size(); i++)
    {
        int minIdx = i;
        for (auto j = i + 1; j < vec.size(); j++)
        {
            if (vec[minIdx] > vec[j])
            {
                minIdx = j;
            }
            //minIdx = vec[minIdx] > vec[j] ? j : minIdx;
        }
        swap(vec[i],vec[minIdx]);
    }
    return true;
}

int selectionSort(int *arr, int size)
{
    if (arr == nullptr || size < 2)
    {
        if (arr == nullptr)
            cout << "&arr address is Null" << endl;
        if (size < 2)
            cout << "siez < 2, size=" << size << endl;
        return false;
    }
   
    for (auto i = 0; i < size; i++)
    {
        int minIdx = i;
        for (auto j = i + 1; j < size; j++)
        {
            minIdx = arr[minIdx] > arr[j] ? j : minIdx;
        }
         swap(arr[i], arr[minIdx]);
         //myprint(arr, size);
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

    //选择排序实现
    selectionSort(vec2);
    myprint(vec2);
    
    //测试
    int tmp = isEqual(vec1, vec2);
    if (tmp)
    {
        cout << "selectionSort is Success" << endl;
    }
    else
    {
        cout << "selectionSort is Fail" << endl;
    }

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}