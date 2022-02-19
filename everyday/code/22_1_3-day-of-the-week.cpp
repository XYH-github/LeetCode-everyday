/*

给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

 

示例 1：

输入：day = 31, month = 8, year = 2019
输出："Saturday"
示例 2：

输入：day = 18, month = 7, year = 1999
输出："Sunday"
示例 3：

输入：day = 15, month = 8, year = 1993
输出："Sunday"
 

提示：

给出的日期一定是在 1971 到 2100 年之间的有效日期。

链接：https://leetcode-cn.com/problems/day-of-the-week

    int day = 18, month = 7, year = 1999;
    Solution temp;
    string ret = temp.dayOfTheWeek(day, month, year);
    cout << ret << endl;

*/

#include <string>
#include <vector>
#include <time.h>
using namespace std;

//class Solution {
//public:
//    // 1970.12.31是星期四
//    string dayOfTheWeek(int day, int month, int year) {
//        vector<string> week = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
//        vector<int> mouth_days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
//        int days = 365 * (year - 1971) + (year - 1969) / 4;
//        for (int i = 0; i < month - 1; ++i)
//            days += mouth_days[i];
//        if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month > 2)
//            days += 1;
//        days += day;
//        return week[(days + 3) % 7];
//    }
//};

//class Solution {
//    static constexpr const char* list[]{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//public:
//    string dayOfTheWeek(int day, int month, int year) {
//        tm time{ 0, 0, 0, day, month - 1, year - 1900 };
//        mktime(&time);
//        return list[time.tm_wday];
//    }
//};
//
//class Solution {
//public:
//    string dayOfTheWeek(int day, int month, int year) {
//        tm time{ 0, 0, 0, day, month - 1, year - 1900 };
//        char ret[10];
//        mktime(&time);
//        strftime(ret, 10, "%A", &time);
//        return ret;
//    }
//};

class Solution {
public:
    string dayOfTheWeek(int d, int m, int y) {
        vector<string> weeks = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        if (m < 3) m += 12, --y;
        int c = y / 100;
        y %= 100;
        int D = c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1 + 210;//加上30*7防止出现负数
        return weeks[D % 7];
    }
};