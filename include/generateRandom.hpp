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

vector<int> generataRandomArray(int maxSize, int maxValue, int minValue = 0)
{
    vector<int> vecArray;
    // 一、 c语言方法
    // srand((unsigned int)time(nullptr)); //产生随机种子,放在generataRandomArray调用之前
    // int randTmp = rand() % maxValue; //范围0 — maxValue-1, rand()函数所产生随机数的范围：0—32767，RAND_MAX
    for (auto i = 0; i < maxSize; i++)
    {
        int randTmp = (rand() % (maxValue - minValue + 1) + minValue);
        vecArray.push_back(randTmp);
    }

    // 二、c++方式
    // C++11之前，无论是C，还是C++都使用相同方式的来生成随机数，而在C++11中提供了随机数库，包括随机数引擎类、随机数分布类，简介如下：
    // C++ 11 在头文件 #include 中定义了随机数库，包括随机数生成器和随机数分布器。
    // 2.1随机数生成器
    // ①概述
    // 随机数生成器用来使用指定的种子产生一个随机数。

    // ② random_device :是标准库提供到一个非确定性随机数生成器，使用硬件作为随机数来源，故其调用代价较高，一般用来产生随机数种子。
    // random_device rd;
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << "random_device =" << rd() << endl;
    // }

    // ③ default_random_engine ：是标准库提供的默认随机数生成器，其实现和编译器有关，产生随机非负数（不推荐直接使用）。
    // random_device rd;
    // default_random_engine default_random_engine_randSend(rd()); //或  default_random_engine_randSend.seed(time(0));
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << "default_random_engine_randSend=" << default_random_engine_randSend() << endl;
    // }

    // ④ minstd_rand ：是标准库提供的采用线性同余算法的伪随机数生成器。
    // random_device rd;
    // minstd_rand minstd_rand_randSend(rd());
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << "minstd_rand_randSend=" << minstd_rand_randSend() << endl;
    // }

    // ⑤ mt19937 :是标准库提供的采用梅森旋转算法的伪随机数生成器，可以快速产生高质量到随机数。
    // random_device rd;
    // mt19937 mt19937_randSend(rd());
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << "mt19937_randSend=" << mt19937_randSend() << endl;
    // }

    // ⑥ ranlux24_base :是标准库提供的采用带进位减法的伪随机数生成器。
    // random_device rd;
    // ranlux24_base ranlux24_baser_randSend(rd());
    // for (int i = 0; i < 10; ++i)
    // {
    //     cout << "ranlux24_baser_randSend=" << ranlux24_baser_randSend() << endl;
    // }

    // 2.2 随机数分布器
    // ①概述
    // 随机数分布器用于限定生成随机数的范围及分布类型。

    // ② uniform_int_distribution：产生均匀分布的整数
    // random_device rd;                                         //用于生成随机数种子
    // //mt19937 randSend(rd());                                      //随机数生成器
    // default_random_engine randSend;
    // randSend.seed(time(0));
    // std::uniform_int_distribution<int> rdVaule1(0, maxValue); //左闭右闭区间
    // for (int i = 0; i < maxSize; i++)
    // {
    //     vecArray.push_back(rdVaule1(randSend));
    // }

    // ③ uniform_real_distribution： 用于生成指定范围的均匀分布的浮点数。
    // random_device rd;//用于生成随机数种子
    // mt19937 r_eng(rd());//随机数生成器
    // std::uniform_real_distribution<double> rdVaule2(1.5,19.5); // 左闭右闭区间
    // for (int i=0; i<10; i++) {
    //     std::cout << "uniform_real_distribution, rdVaule2=" << rdVaule2(r_eng)<< std::endl;
    // }

    // ④ normal_distribution ：用于生成指定均值和方差的正态分布的浮点数。
    // random_device rd;//用于生成随机数种子
    // mt19937 r_eng(rd());//随机数生成器
    // normal_distribution<double> rdVaule3(4, 1.5);//随机数分布器，均值、方差
    // for (int i=0; i<10; i++) {
    //      std::cout << "normal_distribution, rdVaule3=" << rdVaule3(r_eng)<< std::endl;
    //  }

    // ⑤ bernoulli_distribution ：用于生成二项分布到布尔值，可以指定 true 的概率。
    // random_device rd;//用于生成随机数种子
    // mt19937 r_eng(rd());//随机数生成器
    // bernoulli_distribution   rdVaule4(0.6);//随机数分布器，生成 1 的概率是 0.6
    // for (int i=0; i<10; i++) {
    //     std::cout << "bernoulli_distribution, rdVaule4=" << rdVaule4(r_eng)<< std::endl;
    // }

    return vecArray;
}

/*
int main(int argc, char const **argv)
{

    // vector<int> arr = generataRandomArray(10, 10);
    // myprint(arr);

    int maxSize = 5;
    int maxValue = 1000;
    int timeSize = 10;
    vector<int> vec;

    for (auto i = 0; i < timeSize; i++)
    {
        vec = generataRandomArray(maxSize, maxValue);
        myprint(vec);
    }

    // vector<int> arr2=copyArray(arr);
    // myprint(arr2);
    system("pause"); // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}
*/
