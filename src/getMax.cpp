#include "infa.h"

using namespace std;

int process(vector<int> arr, int L, int R)
{
    if (L == R)
    {
        cout << "L == R, L=" << L <<  endl;
        return arr[L];
    }
    // int mid = L + (R-L)/2;//中点
    int mid = L + ((R - L) >> 1);
    int leftMax = process(arr, L, mid);
    int rightMax = process(arr, mid + 1, R);
    int MaxValue = max(leftMax, rightMax);
    return MaxValue;
}

// arr[L...R]范围最大值
int getMax(vector<int> arr)
{
    int maxValue = process(arr, 0, arr.size() - 1);
    return maxValue;
}

int main(int argc, char const **argv)
{

    vector<int> arr;
    int arrSize = 5;
    int maxVaule = 100;
    srand((unsigned int)time(NULL));
    for (auto i = 0; i < arrSize; i++)
    {
        int value = rand() % maxVaule + 1;
        arr.push_back(value);
    }

    myprint(arr);
    int temp = getMax(arr);

    cout << "tempMax =" << temp << endl;

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
