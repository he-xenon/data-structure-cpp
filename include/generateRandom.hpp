#include <time.h>
#include <stdlib.h>

#include <ctime>
#include <random>

using namespace std;

/*
要取得 [a,b) 的随机整数，使用 (rand() % (b-a))+ a。
要取得 [a,b] 的随机整数，使用 (rand() % (b-a+1))+ a。
要取得 (a,b] 的随机整数，使用 (rand() % (b-a))+ a + 1。
通用公式: a + rand() % n；其中的 a 是起始值，n 是整数的范围。
要取得 0～1 之间的浮点数，可以使用 rand() / double(RAND_MAX)。RAND_MAX 的范围最少是在 32767 之间(int)。用 unsigned int 双字节是 65535，四字节是 4294967295 的整数范围。
*/
vector<int> generataRandomArray(int maxSize, int maxValue)
{
    vector<int> vecArray;
    // c语言，方法一
    srand((unsigned int)time(NULL)); //产生随机种子
    int randTmp = rand() % maxValue; //范围0 — maxValue-1, rand()函数所产生随机数的范围：0—32767，RAND_MAX

    for (auto i = 0; i < maxSize; i++)
    {
        randTmp = (rand() % maxValue + 1);
        vecArray.push_back(randTmp);
    }

    // cout << "generate Random vaule, randomValue=" << ret << endl;

    // c++方式二
    // C++11之前，无论是C，还是C++都使用相同方式的来生成随机数，而在C++11中提供了随机数库，包括随机数引擎类、随机数分布类，简介如下：
    /*
    // 1.随机数引擎类
    // 一般使用 default_random_engine 类，产生随机非负数（不推荐直接使用）
    std::default_random_engine  randSend;
    randSend.seed(time(0));
    for (int i=0; i<10; i++) {
        std::cout << "default_random_engine, randSend=" << randSend<< std::endl;
    }

    // 2.随机数分布类
    // uniform_int_distribution：产生均匀分布的整数
    std::uniform_int_distribution<int> rdVaule1(2,20); //左闭右闭区间
    for (int i=0; i<10; i++) {
        std::cout << "uniform_int_distribution, rdVaule1=" << rdVaule1(randSend)<< std::endl;
    }

    // 3.uniform_real_distribution：产生均匀分布的实数
    std::uniform_real_distribution<double> rdVaule2(1.5,19.5); // 左闭右闭区间
    for (int i=0; i<10; i++) {
        std::cout << "uniform_real_distribution, rdVaule2=" << rdVaule2(randSend)<< std::endl;
    }

    //4.normal_distribution：产生正态分布的实数
    std::normal_distribution<double> rdVaule3(0,1); // 均值为0，标准差为1
    for (int i=0; i<10; i++) {
        std::cout << "normal_distribution, rdVaule3=" << rdVaule3(randSend)<< std::endl;
    }

    // 5.bernoulli_distribution：生成二项分布的布尔值
    std::bernoulli_distribution rdVaule4(0.8); // 生成1的概率为0.8
    for (int i=0; i<10; i++) {
        std::cout << "bernoulli_distribution, rdVaule4=" << rdVaule4(randSend)<< std::endl;
    }
    */

    return vecArray;
}

/*
int main(int argc, char const **argv)
{

    vector<int> arr = generataRandomArray(10, 10);
    myprint(arr);

    vector<int> arr2=copyArray(arr);
    myprint(arr2);
    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
*/