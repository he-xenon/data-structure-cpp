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
            if(vec[j] > vec[j+1])
            {
                swap(vec[j],vec[j+1]);
            }
        }
    }
    return true;
}

int main(int argc, char const **argv)
{
    //数组
    int arr[] = {200, 1, 9, 10, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // vector
    vector<int> vec;
    for (size_t i = 0; i < size; i++)
    {
        vec.push_back(arr[i]);
    }

    bubbleSort(arr, size);
    myprint(arr, size);

    myprint(vec);
    bubbleSort(vec);
    myprint(vec);


    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
