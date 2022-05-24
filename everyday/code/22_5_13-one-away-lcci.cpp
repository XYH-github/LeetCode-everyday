/*

字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

示例 1:

输入:
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入:
first = "pales"
second = "pal"
输出: False

链接：https://leetcode.cn/problems/one-away-lcci

    string first = "pale", second = "ple";
    Solution temp;
    bool ret = temp.oneEditAway(first, second);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len_f = first.size();
        int len_s = second.size();
        if ((len_f > len_s + 1) || (len_f + 1 < len_s))
            return false;
        if (len_f < len_s) {
            int i = 0, j = 0, error = 0;
            while (i < len_f) {
                if (first[i] != second[j]) {
                    j++;
                    if (++error > 1)
                        return false;
                }
                else {
                    i++;
                    j++;
                }
            }
            return true;
        }
        else if (len_f > len_s) {
            int i = 0, j = 0, error = 0;
            while (i < len_s) {
                if (second[i] != first[j]) {
                    j++;
                    if (++error > 1)
                        return false;
                }
                else {
                    i++;
                    j++;
                }
            }
            return true;
        }
        else {
            int i = 0, j = 0, error = 0;
            while (i < len_s) {
                if (second[i] != first[j]) {
                    if (++error > 1)
                        return false;
                }
                i++;
                j++;
            }
            return true;
        }
    }
};