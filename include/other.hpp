#include <iostream>
#include <vector>

using namespace std;

//比较两个数组是否一样
int isEqual(vector<int> vec1, vector<int> vec2)
{
    if (vec1.size() != vec2.size())
    {
        cout << "vector size is unequal, vec1.size=" << vec1.size() << ",vec2.size=" << vec2.size() << endl;
        return false;
    }

    if (vec1.size() == 0 || vec2.size() == 0)
    {
        cout << "vector size is NULL, vec1.size=" << vec1.size() << ",vec2.size=" << vec2.size() << endl;
        return false;
    }

    for (int i = 0; i < vec1.size(); i++)
    {
        if (vec1[i] != vec2[i])
        {
            return false;
        }
    }
    return true;
}

//拷贝
vector<int> copyArray(vector<int> arr)
{
    vector<int> tmp;
    tmp = arr;

    return tmp;
}