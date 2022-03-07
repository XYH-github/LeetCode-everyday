﻿/*

有 buckets 桶液体，其中 正好 有一桶含有毒药，其余装的都是水。它们从外观看起来都一样。为了弄清楚哪只水桶含有毒药，你可以喂一些猪喝，通过观察猪是否会死进行判断。不幸的是，你只有 minutesToTest 分钟时间来确定哪桶液体是有毒的。

喂猪的规则如下：

选择若干活猪进行喂养
可以允许小猪同时饮用任意数量的桶中的水，并且该过程不需要时间。
小猪喝完水后，必须有 minutesToDie 分钟的冷却时间。在这段时间里，你只能观察，而不允许继续喂猪。
过了 minutesToDie 分钟后，所有喝到毒药的猪都会死去，其他所有猪都会活下来。
重复这一过程，直到时间用完。
给你桶的数目 buckets ，minutesToDie 和 minutesToTest ，返回在规定时间内判断哪个桶有毒所需的 最小 猪数。

 

示例 1：

输入：buckets = 1000, minutesToDie = 15, minutesToTest = 60
输出：5
示例 2：

输入：buckets = 4, minutesToDie = 15, minutesToTest = 15
输出：2
示例 3：

输入：buckets = 4, minutesToDie = 15, minutesToTest = 30
输出：2
 

提示：

1 <= buckets <= 1000
1 <= minutesToDie <= minutesToTest <= 100

int buckets = 4, minutesToDie = 15, minutesToTest = 30;
    Solution temp;
    int result = temp.poorPigs(buckets, minutesToDie, minutesToTest);
    cout << result << endl;

*/
#include <math.h>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
//        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
//    }
//};

//class Solution {
//public:
//    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
//        if (buckets == 1) {
//            return 0;
//        }
//        vector<vector<int>> combinations(buckets + 1, vector<int>(buckets + 1));
//        combinations[0][0] = 1;
//        int iterations = minutesToTest / minutesToDie;
//        vector<vector<int>> f(buckets, vector<int>(iterations + 1));
//        for (int i = 0; i < buckets; ++i)
//            f[i][0] = 1;
//        for (int i = 0; i < iterations; ++i)
//            f[0][i] = 1;
//        for (int i = 1; i < buckets; ++i) {
//            combinations[i][0] = 1;
//            combinations[i][i] = 1;
//            for (int j = 1; j < i; ++j)
//                combinations[i][j] = combinations[i - 1][j - 1] + combinations[i - 1][j];
//            for (int j = 1; j <= iterations; ++j)
//                for (int k = 0; k <= i; ++k)
//                    f[i][j] += f[k][j - 1] * combinations[i][i - k];
//            if (f[i][iterations] >= buckets)
//                return i;
//        }
//        return 0;
//    }
//};


class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int iter_nums = minutesToTest / minutesToDie;
        vector<vector<int>> cont(buckets + 1, vector<int>(buckets + 1, 1));
        vector<vector<int>> f(buckets, vector<int>(iter_nums + 1, 1));
        for (int i = 1; i < buckets; ++i) {
            for (int j = 1; j < i; ++j) 
                cont[j][i] = cont[j - 1][i - 1] + cont[j][i - 1];
            for (int j = 1; j < iter_nums + 1; ++j) 
                for (int k = 1; k <= i; ++k)
                    f[i][j] += f[k][j - 1] * cont[k][i];
            if (f[i][iter_nums] >= buckets)
                return i;
        }
        return 0;
    }
};