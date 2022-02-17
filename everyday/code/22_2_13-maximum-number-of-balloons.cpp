/*

给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。

字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。

 

示例 1：



输入：text = "nlaebolko"
输出：1
示例 2：



输入：text = "loonbalxballpoon"
输出：2
示例 3：

输入：text = "leetcode"
输出：0
 

提示：

1 <= text.length <= 10^4
text 全部由小写英文字母组成

链接：https://leetcode-cn.com/problems/maximum-number-of-balloons

    string text = "loonbalxballpoon";
    Solution temp;
    int ret = temp.maxNumberOfBalloons(text);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ret = INT_MAX;
        int hash_map[5] = {0};
        for (char index : text)
            if (index == 'b')
                ++hash_map[0];
            else if (index == 'a')
                ++hash_map[2];
            else if (index == 'l')
                ++hash_map[1];
            else if (index == 'o')
                ++hash_map[3];
            else if (index == 'n')
                ++hash_map[4];
        for (int i = 0; i < 5; ++i)
            if (i % 2)
                ret = min(hash_map[i] / 2, ret);
            else
                ret = min(hash_map[i], ret);
        return ret;
    }
};