/*

你和你的朋友，两个人一起玩 Nim 游戏：

桌子上有一堆石头。
你们轮流进行自己的回合， 你作为先手 。
每一回合，轮到的人拿掉 1 - 3 块石头。
拿掉最后一块石头的人就是获胜者。
假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。

 

示例 1：

输入：n = 4
输出：false
解释：以下是可能的结果:
1. 移除1颗石头。你的朋友移走了3块石头，包括最后一块。你的朋友赢了。
2. 移除2个石子。你的朋友移走2块石头，包括最后一块。你的朋友赢了。
3.你移走3颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
在所有结果中，你的朋友是赢家。
示例 2：

输入：n = 1
输出：true
示例 3：

输入：n = 2
输出：true
 

提示：

1 <= n <= 231 - 1

链接：https://leetcode.cn/problems/nim-game

	int n = 43;
	Solution temp;
	bool ret = temp.canWinNim(n);
	cout << ret << endl;

*/

#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<int> memory;
//    bool canWinNim(int n) {
//        memory.resize(n + 1, -1);
//        return dfs(n);
//    }
//
//    bool dfs(int left) {
//        if (memory[left] == 1)
//            return true;
//        else if (memory[left] == 0)
//            return false;
//        memory[left] = 0;
//        if (left <= 3) {
//            memory[left] = 1;
//            return true;
//        }
//        for (int i = 1; i <= 3; ++i) {
//            if (!dfs(left - i)) {
//                memory[left] = 1;
//                return true;
//            }
//        }
//        return false;
//    }
//};


class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};