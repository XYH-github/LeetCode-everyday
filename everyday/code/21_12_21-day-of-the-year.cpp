/*

给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。请你计算并返回该日期是当年的第几天。

通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。

 

示例 1：

输入：date = "2019-01-09"
输出：9
示例 2：

输入：date = "2019-02-10"
输出：41
示例 3：

输入：date = "2003-03-01"
输出：60
示例 4：

输入：date = "2004-03-01"
输出：61
 

提示：

date.length == 10
date[4] == date[7] == '-'，其他的 date[i] 都是数字
date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日

链接：https://leetcode-cn.com/problems/day-of-the-year

string date = "2004-03-01";
	Solution temp;
	int result = temp.dayOfYear(date);
	cout << result << endl;

*/
#include <ctime>
#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int dayOfYear(string date) {
//        int years = 0;
//        int mons = 0;
//        int days = 0;
//        int result = 0;
//        for (int i = 0; i < 4; ++i)
//            years = years * 10 + (int)date[i] - 48;
//        for (int i = 5; i < 7; ++i)
//            mons = mons * 10 + (int)date[i] - 48;
//        for (int i = 8; i < 10; ++i)
//            days = days * 10 + (int)date[i] - 48;
//        for (int i = 1; i < mons; ++i) {
//            if (i < 8) {
//                if (i == 2)
//                    result += 28;
//                else
//                    result += (i % 2 == 0) ? 30 : 31;
//            }
//            else
//                result += (i % 2 == 0) ? 31 : 30;
//        }
//        if (years % 400 == 0 || (years % 4 == 0 && years % 100 != 0) && mons > 2)
//            result += 1;
//        return result + days;
//    }
//};

//class Solution {
//public:
//    int dayOfYear(string date) {
//        tm t{};
//        //strptime(date.c_str(), "%Y-%m-%d", &t);
//        istringstream ss(date);
//        ss >> get_time(&t, "%Y-%m-%d");
//        mktime(&t);
//        return t.tm_yday + 1;
//    }
//};