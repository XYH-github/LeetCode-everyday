/*

图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。

每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。

如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。



给你一个表示图像灰度的 m x n 整数矩阵 img ，返回对图像的每个单元格平滑处理后的图像 。

 

示例 1:



输入:img = [[1,1,1],[1,0,1],[1,1,1]]
输出:[[0, 0, 0],[0, 0, 0], [0, 0, 0]]
解释:
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
示例 2:


输入: img = [[100,200,100],[200,50,200],[100,200,100]]
输出: [[137,141,137],[141,138,141],[137,141,137]]
解释:
对于点 (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
对于点 (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
对于点 (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
 

提示:

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255

链接：https://leetcode-cn.com/problems/image-smoother

    vector<vector<int>> img = { {2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16} };
    Solution temp;
    vector<vector<int>> ret = temp.imageSmoother(img);
    Print<int>::PrintTwoDemionVector(ret);

*/

#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
//        int len_m = img.size();
//        int len_n = img[0].size();
//        vector<vector<int>> ret(len_m, vector<int>(len_n));
//        for (int i = 0; i < len_m; ++i) {
//            for (int j = 0; j < len_n; ++j) {
//                int temp_all = 0;
//                int count = 0;
//                for (int k = i - 1; k <= i + 1; ++k) {
//                    for (int d = j - 1; d <= j + 1; ++d) {
//                        if (k >= 0 && k < len_m && d >= 0 && d < len_n) {
//                            temp_all += img[k][d];
//                            count++;
//                        }
//                    }
//                }
//                ret[i][j] = temp_all / count;
//            }
//        }
//        return ret;
//    }
//};


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int len_m = img.size();
        int len_n = img[0].size();
        vector<vector<int>> sum_vec(len_m + 1, vector<int>(len_n + 1));
        vector<vector<int>> ret(len_m, vector<int>(len_n));
        for (int i = 0; i < len_m; ++i) {
            for (int j = 0; j < len_n; ++j) {
                sum_vec[i + 1][j + 1] = sum_vec[i][j + 1] + sum_vec[i + 1][j] - sum_vec[i][j] + img[i][j];
            }
        }
        for (int i = 0; i < len_m; ++i) {
            for (int j = 0; j < len_n; ++j) {
                int front_i = i - 1 >= 0 ? i - 1 : 0;
                int front_j = j - 1 >= 0 ? j - 1 : 0;
                int back_i = i + 1 < len_m ? i + 1 : len_m - 1;
                int back_j = j + 1 < len_n ? j + 1 : len_n - 1;
                ret[i][j] = sum_vec[back_i + 1][back_j + 1] - sum_vec[back_i + 1][front_j] - sum_vec[front_i][back_j + 1] + sum_vec[front_i][front_j];
                ret[i][j] /= (back_i + 1 - front_i) * (back_j + 1 - front_j);
            }
        }
        return ret;
    }
};