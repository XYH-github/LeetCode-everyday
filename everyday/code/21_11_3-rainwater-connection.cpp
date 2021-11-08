/*

给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。

 

示例 1:



输入: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
输出: 4
解释: 下雨后，雨水将会被上图蓝色的方块中。总的接雨水量为1+2+1=4。
示例 2:



输入: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
输出: 10
 

提示:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104

*/

#include <vector>
#include <queue>
using namespace std;

//class Solution {
//public:
//    int trapRainWater(vector<vector<int>>& heightMap) {
//        int result = 0;
//        int m = heightMap.size();
//        int n = heightMap[0].size();
//        if (m <= 2 || n <= 2)
//            return result;
//        typedef pair<int, int> pii;
//        priority_queue<pii, vector<pii>, greater<pii>> q;
//        vector<vector<bool>> visit(m, vector<bool>(n, false));
//        for (int i = 0; i < m; ++i)
//            for (int j = 0; j < n; ++j) 
//                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
//                    visit[i][j] = true;
//                    q.push({ heightMap[i][j], i * n + j });
//                }
//        int dict[5] = { -1, 0, 1, 0, -1};
//        while (!q.empty()) {
//            pii temp = q.top();
//            q.pop();
//            for (int i = 0; i < 4; ++i) {
//                int poi_i = temp.second / n + dict[i];
//                int poi_j = temp.second % n + dict[i + 1];
//                if (poi_i < 0 || poi_j < 0 || poi_i >= m || poi_j >= n || visit[poi_i][poi_j])
//                    continue;
//                if (temp.first > heightMap[poi_i][poi_j])
//                    result += temp.first - heightMap[poi_i][poi_j];
//                q.push({ max(temp.first, heightMap[poi_i][poi_j]), poi_i * n + poi_j });
//                visit[poi_i][poi_j] = true;
//            }
//        }
//        return result;
//    }
//};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        int maxHeight = 0;
        int dirs[] = { -1, 0, 1, 0, -1 };
        
        for (int i = 0; i < m; ++i)
            maxHeight = max(maxHeight, *max_element(heightMap[i].begin(), heightMap[i].end()));
        vector<vector<int>> water(m, vector<int>(n, maxHeight));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (water[i][j] > heightMap[i][j]) {
                        water[i][j] = heightMap[i][j];
                        q.push(make_pair(i, j));
                    }
                }
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
                    water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
                    q.push(make_pair(nx, ny));
                }
               
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += water[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
};

       