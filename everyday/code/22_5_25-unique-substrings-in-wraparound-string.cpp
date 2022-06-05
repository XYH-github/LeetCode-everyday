/*

把字符串 s 看作 "abcdefghijklmnopqrstuvwxyz" 的无限环绕字符串，所以 s 看起来是这样的：

"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd...." 。
现在给定另一个字符串 p 。返回 s 中 不同 的 p 的 非空子串 的数量 。 

 

示例 1：

输入：p = "a"
输出：1
解释：字符串 s 中只有 p 的一个 "a" 子字符。
示例 2：

输入：p = "cac"
输出：2
解释：字符串 s 中只有 p 的两个子串 ("a", "c") 。
示例 3：

输入：p = "zab"
输出：6
解释：在字符串 s 中有 p 的六个子串 ("z", "a", "b", "za", "ab", "zab") 。
 

提示：

1 <= p.length <= 105
p 由小写英文字母组成

链接：https://leetcode.cn/problems/unique-substrings-in-wraparound-string

    string p = "zab";
    Solution temp;
    int ret = temp.findSubstringInWraproundString(p);
    cout << ret << endl;

*/

#include <string>
#include <vector>
#include <numeric>
using namespace std;

//class Solution {
//public:
//    int findSubstringInWraproundString(string p) {
//        vector<int> cnt(26);
//        int len = p.size();
//        int i = 0;
//        while (i < len) {
//            int j = i + 1;
//            int count = 1;
//            while (j < len) {
//                if ((p[j - 1] - 'a' + 1) % 26 != p[j] - 'a')
//                    break;
//                j++;
//                count++;
//            }
//            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], count);
//            i++;
//        }
//        return accumulate(cnt.begin(), cnt.end(), 0);
//    }
//};


class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> cnt(26);
        int len = p.size();
        int i = 1;
        int k = 1;
        cnt[p[0] - 'a'] = 1;
        while (i < len) {
            if ((p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') {
                ++k;
            }
            else {
                k = 1;
            }
            cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], k);
            ++i;
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};