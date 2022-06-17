/*

给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

示例 1：

输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：

输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

提示：

1 <= arr.length <= 10000
0 <= arr[i] <= 9

链接：https://leetcode.cn/problems/duplicate-zeros

    vector<int> input_vec = { 1, 0, 2, 3, 0, 4, 5, 0 };
    Solution temp;
    temp.duplicateZeros(input_vec);
    Print<int>::PrintOneDemionVector(input_vec);

*/

#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt = 0;
        int len = arr.size();
        int i = 0;
        while (i + cnt < len) {
            if (arr[i] == 0)
                cnt++;
            ++i;
        }
        int index = len;
        if (i + cnt != len) {
            arr[--index] = arr[len - cnt];
        }
        for (int i = len - cnt - 1; i >= 0; --i) {
            arr[--index] = arr[i];
            if (arr[i] == 0)
                arr[--index] = arr[i];
        }
        return;
    }
};