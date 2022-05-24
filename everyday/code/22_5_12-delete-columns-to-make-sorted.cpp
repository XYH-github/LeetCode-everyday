/*

给你由 n 个小写字母字符串组成的数组 strs，其中每个字符串长度相等。

这些字符串可以每个一行，排成一个网格。例如，strs = ["abc", "bce", "cae"] 可以排列为：

abc
bce
cae
你需要找出并删除 不是按字典序升序排列的 列。在上面的例子（下标从 0 开始）中，列 0（'a', 'b', 'c'）和列 2（'c', 'e', 'e'）都是按升序排列的，而列 1（'b', 'c', 'a'）不是，所以要删除列 1 。

返回你需要删除的列数。

链接：https://leetcode.cn/problems/delete-columns-to-make-sorted

    vector<string> strs = { "cba", "daf", "ghi" };
    Solution temp;
    int ret = temp.minDeletionSize(strs);
    cout << ret << endl;

*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs.size();
        int ret = 0;
        vector<bool> delete_cell(strs[0].size());
        string cmp_temp = strs[0];
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < strs[i].size(); ++j)
                if (!delete_cell[j] && strs[i][j] < cmp_temp[j])
                    delete_cell[j] = true;
            cmp_temp = strs[i];
        }
        for (bool cell : delete_cell) {
            if (cell)
                ret++;
        }
        return ret;
    }
};