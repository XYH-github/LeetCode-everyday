/*

给定一个表示整数的字符串 n ，返回与它最近的回文整数（不包括自身）。如果不止一个，返回较小的那个。

“最近的”定义为两个整数差的绝对值最小。

 

示例 1:

输入: n = "123"
输出: "121"
示例 2:

输入: n = "1"
输出: "0"
解释: 0 和 2是最近的回文，但我们返回最小的，也就是 0。
 

提示:

1 <= n.length <= 18
n 只由数字组成
n 不含前导 0
n 代表在 [1, 1018 - 1] 范围内的整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-closest-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

    string a = "1213", b = "-1221";
    string n = "1000";
    Solution temp;
    string ret = temp.nearestPalindromic(n);
    //string ret = temp.strAdd(a, b);
    cout << ret << endl;

*/

#include <string>
using namespace std;



//class Solution {
//
//public:
//    string nearestPalindromic(string n) {
//        if (n == "10" || n == "11")
//            return "9";
//        int len = n.size();
//        string ret = n.substr(0, (len + 1) / 2);
//        string str_max(ret);
//        string str_min(ret);
//
//        for (int i = len / 2 - 1; i >= 0; --i)
//            str_max.push_back(ret[i]);
//        if (str_max < n) {
//            str_min = str_max;
//            str_max = ret;
//            str_max = strAdd(str_max, "1");
//            for (int i = len / 2 - 1; i >= 0; --i)
//                str_max.push_back(str_max[i]);
//        }
//        else if (str_max > n) {
//            str_min = strAdd(str_min, "-1");
//            for (int i = len / 2 - 1; i >= 0; --i) {
//                int temp = i >= str_min.size() ? str_min[i - 1] : str_min[i];
//                    str_min.push_back(temp);
//            }
//        }
//        else {
//            str_max = ret;
//            str_max = strAdd(str_max, "1");
//            for (int i = len / 2 - 1; i >= 0; --i)
//                str_max.push_back(str_max[i]);
//            str_min = strAdd(str_min, "-1");
//            for (int i = len / 2 - 1; i >= 0; --i)
//                str_min.push_back(str_min[i]);
//        }
//        string cmp1 = strAdd(n, "-" + str_max);
//        string cmp2 = strAdd(str_min, "-" + n); 
//        if (cmpMin(cmp1, cmp2))
//            return str_max;
//        else
//            return str_min;
//    }
//
//    bool cmpMin(string str, string str2) {
//        if (str.size() != str2.size())
//            return str.size() < str2.size();
//        else
//            return str < str2;
//    }
//
//    string strAdd(string str, string i) {
//        int len_s = str.size();
//        int len_i = i.size();
//        if (len_s == 0 && len_i == 0)
//            return "";
//        if (i[0] == '-') {
//            len_i--;
//            i = i.substr(1, len_i);
//            int step = 0;
//            bool flag = false;
//            if (cmpMin(str, i)) {
//                swap(str, i);
//                swap(len_i, len_s);
//                flag = true;
//            }
//            while (len_i > 0 || len_s > 0) {
//                len_i--;
//                len_s--;
//                char ch_s = 0;
//                char ch_i = 0;
//                if (len_s >= 0)
//                    ch_s = str[len_s] - '0';
//                if (len_i >= 0)
//                    ch_i = i[len_i] - '0';
//                char temp = ch_s - ch_i - step;
//                step = 0;
//                if (temp < 0) {
//                    temp += 10;
//                    step = 1;
//                }
//                str[len_s] = temp + '0';
//            }
//            while (*str.begin() == '0' && str.begin() != str.end() - 1)
//                str.erase(str.begin());
//            //if (flag)
//            //    str.insert(0, "-");
//        }
//        else {
//            int step = 0;
//            while (len_i > 0 || len_s > 0) {
//                len_i--;
//                len_s--;
//
//                char ch_s = 0;
//                char ch_i = 0;
//                if (len_s >= 0)
//                    ch_s = str[len_s] - '0';
//                if (len_i >= 0)
//                    ch_i = i[len_i] - '0';
//                char temp = ch_s + ch_i + step;
//                if (temp > 9) {
//                    temp -= 10;
//                    step = 1;
//                }
//                str[len_s] = temp + '0';
//            }
//            if (step == 1)
//                str.insert(0, "1");
//        }
//        return str;
//    }
//};


class Solution {
public:
    string nearestPalindromic(string n) {
        long len = n.size();
        long num = stol(n);
        // 考虑 10000 的情况 -> 9999
        if (num < 10 || num == pow(10, len - 1))
        {
            return to_string(num - 1);
        }
        // 考虑 10001 的情况 -> 9999
        else if (num - 1 == pow(10, len - 1))
        {
            return to_string(num - 2);
        }
        // 考虑 9999 的情况 -> 10001
        else if (num + 1 == pow(10, len))
        {
            return to_string(num + 2);
        }

        // 取前一半
        long half = stol(n.substr(0, (len + 1) / 2));
        long minAbs = INT_MAX;
        string ans = "";

        for (int dx : {-1, 0, 1})
        {
            //前半部分
            string firstHalf = to_string(half + dx);
            //后半部分
            string  resHalf = firstHalf.substr(0, len / 2);
            string lastHalf(resHalf.rbegin(), resHalf.rend());
            //整体
            string curr = firstHalf + lastHalf;
            //计算差
            long currAbs = abs(stol(curr) - num);
            //最最近（差最小）的回文数
            if (curr != n && currAbs < minAbs)
            {
                minAbs = currAbs;
                ans = curr;
            }
        }
        return ans;
    }
};