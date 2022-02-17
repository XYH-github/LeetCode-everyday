/*

给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

 

示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]
示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
示例 4：

输入：n = 1
输出：[]

链接：https://leetcode-cn.com/problems/simplified-fractions

    int n = 4;
    Solution temp;
    vector<string> ret = temp.simplifiedFractions(n);
    Print<string>::PrintOneDemionVector(ret);

*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ret;
        if (n < 2)
            return ret;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j < i; ++j)
                if (simpliJudge(i, j))
                    ret.push_back( to_string(j) + '/' + to_string(i));
        return ret;
    }

    bool simpliJudge(int i, int j) {
        int z = j;
        while (i % j) {
            z = i % j;
            i = j;
            j = z;
        }
        if (z == 1)
            return true;
        else
            return false;
    }

    //bool simpliJudge(int i, int j) {
    //    while (i != j) 
    //        if (i > j)
    //            i = i - j;
    //        else
    //            j = j - i;
    //    if (i == 1)
    //        return true;
    //    else
    //        return false;
    //}

};