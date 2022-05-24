/*

某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：

输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
order.length == 26
在 words[i] 和 order 中的所有字符都是英文小写字母。

链接：https://leetcode.cn/problems/verifying-an-alien-dictionary

    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution temp;
    bool ret = temp.isAlienSorted(words, order);
    cout << ret << endl;

*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int len = words.size();
        for (int i = 1; i < len; ++i) {
            if (!isVaild(words[i - 1], words[i], order))
                return false;
        }
        return true;
    }

    bool isVaild(string a, string b, string order) {
        vector<int> cnt(26);
        for (int i = 0; i < 26; ++i) {
            cnt[order[i] - 'a'] = i;
        }
        int len_a = a.size(), len_b = b.size();
        int i_a = 0, i_b = 0;
        while (i_a < len_a && i_b < len_b) {
            if (cnt[a[i_a] - 'a'] < cnt[b[i_b] - 'a'])
                return true;
            else if (cnt[a[i_a] - 'a'] > cnt[b[i_b] - 'a'])
                return false;
            i_a++, i_b++;
        }
        return len_b >= len_a;
    }
};