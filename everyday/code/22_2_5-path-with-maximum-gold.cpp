/*

��Ҫ����һ����󣬵��ʿ���ѧ���Ѿ�̽������������е���Դ�ֲ������ô�СΪ?m * n ������ grid �����˱�ע��ÿ����Ԫ���е������ͱ�ʾ��һ��Ԫ���еĻƽ�����������õ�Ԫ���ǿյģ���ô���� 0��

Ϊ��ʹ������󻯣�����Ҫ�����¹��������ɻƽ�

ÿ���󹤽���һ����Ԫ���ͻ��ռ��õ�Ԫ���е����лƽ�
��ÿ�ο��Դӵ�ǰλ�������������ĸ������ߡ�
ÿ����Ԫ��ֻ�ܱ����ɣ����룩һ�Ρ�
���ÿ��ɣ����룩�ƽ���ĿΪ 0 �ĵ�Ԫ��
�󹤿��Դ������� ����һ�� �лƽ�ĵ�Ԫ�����������ֹͣ��
?

ʾ�� 1��

���룺grid = [[0,6,0],[5,8,7],[0,9,0]]
�����24
���ͣ�
[[0,6,0],
 [5,8,7],
 [0,9,0]]
һ���ռ����ƽ��·���ǣ�9 -> 8 -> 7��
ʾ�� 2��

���룺grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
�����28
���ͣ�
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
һ���ռ����ƽ��·���ǣ�1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7��
?

��ʾ��

1 <= grid.length,?grid[i].length <= 15
0 <= grid[i][j] <= 100
��� 25 ����Ԫ�����лƽ�

���ӣ�https://leetcode-cn.com/problems/path-with-maximum-gold

    vector<vector<int>> grid = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    Solution temp;
    int ret = temp.getMaximumGold(grid);
    cout << ret << endl;

*/
#include <vector>
#include <stack>
using namespace std;

//class Solution {
//public:
//    const int direct[5] = { 0, 1, 0, -1, 0};
//    vector<vector<int>> grid;
//    int hight;
//    int width;
//    int temp_ret = 0;
//    int max_ret = INT_MIN;
//    int getMaximumGold(vector<vector<int>>& grid) {
//        this->grid = grid;
//        this->hight = grid.size();
//        this->width = grid[0].size();
//        int ret = INT_MIN;
//        for (int i = 0; i < hight; ++i)
//            for (int j = 0; j < width; ++j)
//                ret = max(ret, dfs(i, j));
//        return ret;
//    }
//    int dfs(int pos_x, int pos_y) {
//        if (pos_x < 0 || pos_x >= hight || pos_y >= width ||
//            pos_y < 0 || grid[pos_x][pos_y] == 0)
//            return temp_ret;
//        else {
//            temp_ret += grid[pos_x][pos_y];
//            int tmp = grid[pos_x][pos_y];
//            grid[pos_x][pos_y] = 0;
//            for (int i = 0; i < 4; ++i) {
//                int new_x = pos_x + direct[i];
//                int new_y = pos_y + direct[i + 1];
//                max_ret = max(max_ret, dfs(new_x, new_y));
//            }
//            temp_ret -= tmp;
//            grid[pos_x][pos_y] = tmp;
//            return max_ret;
//        }
//    }
//};

class Solution {
public:
    const int direct[5] = { 0, 1, 0, -1, 0 };
    int getMaximumGold(vector<vector<int>>& grid) {
        stack<vector<int>> stk;
        int hight = grid.size();
        int width = grid[0].size();
        int ret_temp = 0;
        int ret_max = 0;
        for (int i = 0; i < hight; ++i)
            for (int j = 0; j < width; ++j)
                if (grid[i][j] > 0)
                    stk.push({i, j, grid[i][j]});
        while (!stk.empty()) {
            vector<int> temp = stk.top();
            if (grid[temp[0]][temp[1]] == 0) {
                ret_max = max(ret_max, ret_temp);
                grid[temp[0]][temp[1]] = temp[2];
                ret_temp -= temp[2];
                stk.pop();
                continue;
            }
            ret_temp += temp[2];
            grid[temp[0]][temp[1]] = 0;
            for (int i = 0; i < 4; ++i) {
                int new_x = temp[0] + direct[i];
                int new_y = temp[1] + direct[i + 1];
                if (new_x >= 0 && new_x < hight && new_y >= 0 &&
                    new_y < width && grid[new_x][new_y] != 0)
                    stk.push({new_x, new_y, grid[new_x][new_y] });
            }
        }
        return ret_max;
    }
};