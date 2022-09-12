#include "infa.h"

using namespace std;

int merge(vector<int> &vec, int L, int M, int R)
{
    vector<int> tmp(R - L + 1);
    int i = 0;
    int p1 = L;
    int p2 = M + 1;
    int tmpSum = 0;
    while (p1 <= M && p2 <= R)
    {
        tmpSum += vec[p1] < vec[p2] ? (R - p2 + 1) * vec[p1] : 0;
        tmp[i++] = vec[p1] < vec[p2] ? vec[p1++] : vec[p2++];
    }
    while (p1 <= M)
    {
        tmp[i++] = vec[p1++];
    }
    while (p2 <= R)
    {
        tmp[i++] = vec[p2++];
    }

    for (auto j = 0; j < tmp.size(); j++)
    {
        vec[L + j] = tmp[j];
    }

    return tmpSum;
}

// vec[L..R]既要排好序，也要求小和返回
// 所有merge时，产生的小和，累加
// 左 排序  merge
// 右 排序  merge
int process(vector<int> &vec, int L, int R)
{
    if (L == R)
    {
        // cout << "L = R, L=" << L << endl;
        return 0;
    }
    int M = L + ((R - L) >> 1);
    return process(vec, L, M) + process(vec, M + 1, R) + merge(vec, L, M, R);
}

int smallSum(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        cout << "vec.size < 2, size=" << vec.size() << endl;
        return 0;
    }
    int smallSum = process(vec, 0, vec.size() - 1);
    return smallSum;
}

//测试
int testSmallSumCompare(vector<int> &vec)
{
    if (vec.size() < 2)
    {
        return 0;
    }
    int sum = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += vec[j] < vec[i] ? vec[j] : 0;
        }
    }
    return sum;
}

int main(int argc, char const **argv)
{
    //生成随机数组
    int testTime = 5; //测试次数
    int MaxSize = 5;
    int MaxValue = 10000;
    srand((unsigned int)time(nullptr)); //产生随机种子

    cout << "Small Sum algorithm start" << endl;
    int flag = true;
    for (auto i = 0; i < testTime; i++)
    {
        vector<int> vec1 = generataRandomArray(MaxSize, MaxValue);
        vector<int> vec2 = copyArray(vec1);
        myprint(vec1);
        if (smallSum(vec1) != testSmallSumCompare(vec2))
        {
            flag = false;
            myprint(vec1);
            myprint(vec2);
            cout << smallSum(vec1) << endl;
            cout << testSmallSumCompare(vec2) << endl;
            break;
        }
        string printTmp = flag ? "Small Sum Sucess!" : "Sum Failed!";
        cout << i<<" times test "<< printTmp << " Small Sum=" <<smallSum(vec1)<< endl;
    }

    cout << "Small Sum algorithm end" << endl;

    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
