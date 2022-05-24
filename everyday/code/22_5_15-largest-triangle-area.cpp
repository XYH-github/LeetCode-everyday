/*

给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。

示例:
输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
输出: 2
解释:
这五个点如下图所示。组成的橙色三角形是最大的，面积为2。


注意:

3 <= points.length <= 50.
不存在重复的点。
 -50 <= points[i][j] <= 50.
结果误差值在 10^-6 以内都认为是正确答案。

链接：https://leetcode.cn/problems/largest-triangle-area

    vector<vector<int>> points = { {0,0},{0,1},{1,0},{0,2},{2,0} };
    Solution temp;
    double ret = temp.largestTriangleArea(points);
    cout << ret << endl;

*/

#include <vector>
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int len = points.size();
        double ret = 0;
        for (int i = 0; i < len - 2; ++i) {
            for (int j = i + 1; j < len - 1; ++j) {
                for (int k = j + 1; k < len; ++k) {
                    ret = max(ret, comMaxAres(points[i], points[j], points[k]));
                }
            }
        }
        return ret;
    }

    double comMaxAres(vector<int> a, vector<int> b, vector<int> c) {
        double x1 = b[0] - a[0];
        double y1 = b[1] - a[1];
        double x2 = c[0] - a[0];
        double y2 = c[1] - a[1];
        return abs(x1 * y2 - x2 * y1) / 2;
    }
};