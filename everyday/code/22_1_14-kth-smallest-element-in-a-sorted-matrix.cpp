/*

给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。

你必须找到一个内存复杂度优于 O(n2) 的解决方案。

 

示例 1：

输入：matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
输出：13
解释：矩阵中的元素为 [1,5,9,10,11,12,13,13,15]，第 8 小元素是 13
示例 2：

输入：matrix = [[-5]], k = 1
输出：-5
 

提示：

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
题目数据 保证 matrix 中的所有行和列都按 非递减顺序 排列
1 <= k <= n2

链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix

    vector<vector<int>> matrix = { {-5, -4}, {-5, -4} };
    int k = 2;
    Solution temp;
    int ret = temp.kthSmallest(matrix, k);
    cout << ret << endl;

*/

#include <vector>
#include <queue>
using namespace std;

//class Solution {
//public:
//    int kthSmallest(vector<vector<int>>& matrix, int k) {
//        struct cmp {
//            bool operator () (const vector<int>& a, const vector<int>& b) {
//                return a[0] > b[0];
//            }
//        };
//        priority_queue<vector<int>, vector<vector<int>>, cmp> queue;
//        /*auto cmp = [&](const vector<int>& a, const vector<int>& b) {
//            return a[0] > b[0];
//        };
//        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)>queue(cmp);*/
//        int ret;
//        for (vector<int> index : matrix)
//            queue.push(index);
//        while (k-- && !queue.empty()) {
//            vector<int> min_vec = queue.top();
//            queue.pop();
//            auto iter = min_vec.begin();
//            ret = *iter;
//            iter = min_vec.erase(iter);
//            if (iter != min_vec.end())
//                queue.push(min_vec);
//        }
//        return ret;
//    }
//};

//class Solution {
//public:
//    int kthSmallest(vector<vector<int>>& matrix, int k) {
//		struct point
//		{
//			int pos_x, pos_y, val;
//			point(int a, int b, int c) : pos_x(a), pos_y(b), val(c) {}
//			bool operator> (const point& a) const{ return this->val > a.val;}
//		};
//		int len_m = matrix.size();
//		int len_n = matrix[0].size();
//		int ret = 0;
//		priority_queue<point, vector<point>, greater<point>> queue;
//		for (int i = 0; i < len_m; ++i)
//			queue.emplace(i, 0, matrix[i][0]);
//		while (k-- && !queue.empty()) {
//			point min_now = queue.top();
//			queue.pop();
//			ret = min_now.val;
//			if (min_now.pos_y != len_n - 1)
//				queue.emplace(min_now.pos_x, min_now.pos_y + 1, matrix[min_now.pos_x][min_now.pos_y + 1]);
//		}
//		return ret;
//    }
//};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        len_m = matrix.size();
        len_n = matrix[0].size();
        matrix_ = matrix;
        int left = matrix[0][0];
        int right = matrix[len_m - 1][len_n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (checkCount(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int checkCount(int mid) {
        int left = 0;
        int botton = len_m - 1;
        int ret = 0;
        while (left < len_n && botton >= 0) {
            if (matrix_[botton][left] <= mid) {
                ret += botton + 1;
                left++;
            }
            else
                botton--;
        }
        return ret;
    }

private:
    int len_m;
    int len_n;
    vector<vector<int>> matrix_;
};