/*

给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。

注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。

 

示例 1：

输入：a = "abcd", b = "cdabcdab"
输出：3
解释：a 重复叠加三遍后为 "abcdabcdabcd", 此时 b 是其子串。
示例 2：

输入：a = "a", b = "aa"
输出：2
示例 3：

输入：a = "a", b = "a"
输出：1
示例 4：

输入：a = "abc", b = "wxyz"
输出：-1
 

提示：

1 <= a.length <= 104
1 <= b.length <= 104
a 和 b 由小写英文字母组成

链接：https://leetcode-cn.com/problems/repeated-string-match

    string a = "abcd", b = "cdabcdab";
    Solution temp;
    int ret = temp.repeatedStringMatch(a, b);
    cout << ret << endl;

*/

#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int repeatedStringMatch(string a, string b) {
//        int len_a = a.size();
//        int len_b = b.size();
//        int a_start = 0;
//        if (len_b == 0)
//            return 1;
//        while (a_start < len_a) {
//            if (a[a_start] != b[0])
//                a_start++;
//            else {
//                int b_start = 0;
//                int a_a_start = a_start;
//                int ret = 1;
//                while (++b_start < len_b) {
//                    if (++a_a_start == len_a)
//                        a_a_start = 0, ret++;
//                    if (a[a_a_start] != b[b_start])
//                        break;
//                }
//                if (b_start == len_b)
//                    return ret;
//                a_start++;
//            }
//        }
//        return -1;
//    }
//};



class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        if (len_b == 0)
            return 0;
        int pos = str_str(a, b);
        if (pos == -1)
            return pos;
        if (len_a - pos >= len_b)
            return 1;
        return 2 + (len_b - len_a + pos - 1) / len_a;

    }

    int str_str(string ss, string pp) {
        int m = ss.size();
        int n = pp.size();
        if (n == 0)
            return 0;
        vector<int> next(n);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j && pp[i] != pp[j])
                j = next[j - 1];
            if (pp[i] == pp[j])
                j++;
            next[i] = j;
        }

        for (int i = 0, j = 0; i < m + n; ++i) {
            while (j && ss[i % m] != pp[j])
                j = next[j - 1];
            if (ss[i % m] == pp[j])
                j++;
            if (j == n)
                return i - n + 1;
        }
        return -1;
    }
};