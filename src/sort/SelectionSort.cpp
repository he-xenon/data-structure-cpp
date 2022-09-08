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
    //数组
    int arr[] = {10, 8, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // vector
    vector<int> vec;
    for (size_t i = 0; i < size; i++)
    {
        vec.push_back(arr[i]);
    }

    selectionSort(arr, size);
    myprint(arr, size);

    selectionSort(vec);
    myprint(vec); 

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}