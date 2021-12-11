/*

给你一个字符串数组 board 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 board 所显示的状态时，才返回 true 。

井字游戏的棋盘是一个 3 x 3 数组，由字符 ' '，'X' 和 'O' 组成。字符 ' ' 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（' '）中。
玩家 1 总是放字符 'X' ，而玩家 2 总是放字符 'O' 。
'X' 和 'O' 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。

示例 1：


输入：board = ["O  ","   ","   "]
输出：false
解释：玩家 1 总是放字符 "X" 。
示例 2：


输入：board = ["XOX"," X ","   "]
输出：false
解释：玩家应该轮流放字符。
示例 3：


输入：board = ["XXX","   ","OOO"]
输出：false
Example 4:


输入：board = ["XOX","O O","XOX"]
输出：true
 

提示：

board.length == 3
board[i].length == 3
board[i][j] 为 'X'、'O' 或 ' '

链接：https://leetcode-cn.com/problems/valid-tic-tac-toe-state

vector<string> board = { "XOX","OXO","XOX"};
    Solution temp;
    bool result = temp.validTicTacToe(board);
    cout << result << endl;
*/
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<vector<int>> array(3, vector<int>(3));
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    array[i][j] = 0;
                else if (board[i][j] == 'X')
                    array[i][j] = 1;
                else
                    array[i][j] = -1;
        int first_temp = 0;
        int second_temp = 0;
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            if (array[0][i] == array[1][i] && array[1][i] == 
                array[2][i] && array[0][i] == 1)
                first_temp |= 1;
            if (array[0][i] == array[1][i] && array[1][i] ==
                array[2][i] && array[0][i] == -1)
                second_temp |= 1;
            if (array[i][0] == array[i][1] && array[i][1] == 
                array[i][2] && array[i][1] == 1)
                first_temp |= 2;
            if (array[i][0] == array[i][1] && array[i][1] ==
                array[i][2] && array[i][1] == -1)
                second_temp |= 2;
            sum += array[2][i] + array[1][i] + array[0][i];
        }
        if (array[0][0] == array[1][1] && array[1][1] == 
            array[2][2] && array[2][2] == 1)
            first_temp |= 4;
        if (array[0][0] == array[1][1] && array[1][1] ==
            array[2][2] && array[2][2] == -1)
            second_temp |= 4;
        if (array[0][2] == array[1][1] && array[1][1] ==
            array[2][0] && array[2][0] == 1)
            first_temp |= 4;
        if (array[0][2] == array[1][1] && array[1][1] ==
            array[2][0] && array[2][0] == -1)
            second_temp |= 4;
        if (first_temp + second_temp == 0 && sum <= 1 && sum > -1)
            return true;
        if (first_temp & 7 && second_temp == 0 && sum == 1)
            return true;
        if (first_temp == 0 && second_temp & 7 && sum == 0)
            return true;
        return false;
    }
};