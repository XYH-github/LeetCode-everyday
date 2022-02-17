/*

当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。

 

示例 1：

输入：s = "YazaAay"
输出："aAa"
解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
"aAa" 是最长的美好子字符串。
示例 2：

输入：s = "Bb"
输出："Bb"
解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
示例 3：

输入：s = "c"
输出：""
解释：没有美好子字符串。
示例 4：

输入：s = "dDzeE"
输出："dD"
解释："dD" 和 "eE" 都是最长美好子字符串。
由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。
 

提示：

1 <= s.length <= 100
s 只包含大写和小写英文字母。

链接：https://leetcode-cn.com/problems/longest-nice-substring

    string s = "YazaAay";
    Solution temp;
    string ret = temp.longestNiceSubstring(s);
    cout << ret << endl;

*/
#include <string>
using namespace std;

//class Solution {
//public:
//    string longestNiceSubstring(string s) {
//        int max_pos = 0;
//        int max_len = 0;
//        for (int i = 0; i < s.size(); ++i) {
//            int lower = 0;
//            int upper = 0;
//            for (int j = i; j < s.size(); ++j) {
//                if (islower(s[j]))
//                    lower |= 1 << (s[j] - 'a');
//                else
//                    upper |= 1 << (s[j] - 'A');
//                if (lower == upper && j - i + 1 > max_len) {
//                    max_pos = i;
//                    max_len = j - i + 1;
//                }
//            }
//        }
//        return s.substr(max_pos, max_len);
//    }
//};

class Solution {
public:
    int max_pos = 0;
    int max_len = 0;
    void dfs(string s, int start, int end) {
        int lower = 0;
        int upper = 0;
        for (int i = start; i <= end; ++i)
            if (islower(s[i]))
                lower |= 1 << (s[i] - 'a');
            else
                upper |= 1 << (s[i] - 'A');
        int temp = lower ^ upper;
        if (temp != 0) {
            int i = 0;
            while (!(temp & 1)) {
                temp >>= 1;
                i++;
            }
            int k = start;
            while (k <= end) {
                while (k <= end && (s[k] == 'a' + i || s[k] == 'A' + i))
                    k++;
                if (k > end)
                    break;
                int st = k;
                while (k <= end && (s[k] != 'a' + i && s[k] != 'A' + i))
                    k++;
                dfs(s, st, k - 1);
            }
            return;
        }else if (max_len < end - start + 1) {
            max_len = end - start + 1;
            max_pos = start;
            return;
        }
    }

    string longestNiceSubstring(string s) {
        dfs(s, 0, s.size() - 1);
        return s.substr(max_pos, max_len);
    }
};