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

    //数组
    int arr[] = {20, 1, 9, 10, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // vector
    vector<int> vec;
    for (size_t i = 0; i < size; i++)
    {
        vec.push_back(arr[i]);
    }

    insertionSort(arr, size);
    myprint(arr, size);

    insertionSort(vec);
    myprint(vec);

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
