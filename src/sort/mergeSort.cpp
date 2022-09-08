#include "infa.h"

using namespace std;

int merge(vector<int> &arr, int L, int M, int R)
{
    vector<int> tmp(R - L + 1);
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    while (p1 <= M && p2 <= R)
    {
        tmp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= M)
    {
        tmp[i++] = arr[p1++];
    }

    while (p2 <= R)
    {
        tmp[i] = arr[p2++];
    }
    for (int j = 0; j < tmp.size(); j++)
    {
        arr[L + j] = tmp[j];
    }
    return true;
}

int process(vector<int> &arr, int L, int R)
{
    if (L == R)
    {
        cout << "L = R, L=" << L << endl;
        return false;
    }
    int M = L + ((R - L) >> 1);
    process(arr, L, M);
    process(arr, M + 1, R);
    merge(arr, L, M, R);
    return true;
}

//归并排序
int mergeSort(vector<int> &arr)
{
    if ( 2 > arr.size())
    {
        cout << "arr.size < 2, size=" << arr.size() << endl;
        return false;
    }
    process(arr, 0, arr.size() - 1);
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

    //归并排序实现
    mergeSort(vec2);
    myprint(vec2);
    
    //测试
    int tmp = isEqual(vec1, vec2);
    if (tmp)
    {
        cout << "mergeSort is Success" << endl;
    }
    else
    {
        cout << "mergeSort is Fail" << endl;
    }

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}