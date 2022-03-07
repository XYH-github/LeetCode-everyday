/*

给你一个 m x n 的二元矩阵 matrix ，且所有值被初始化为 0 。请你设计一个算法，随机选取一个满足 matrix[i][j] == 0 的下标 (i, j) ，并将它的值变为 1 。所有满足 matrix[i][j] == 0 的下标 (i, j) 被选取的概率应当均等。

尽量最少调用内置的随机函数，并且优化时间和空间复杂度。

实现 Solution 类：

Solution(int m, int n) 使用二元矩阵的大小 m 和 n 初始化该对象
int[] flip() 返回一个满足 matrix[i][j] == 0 的随机下标 [i, j] ，并将其对应格子中的值变为 1
void reset() 将矩阵中所有的值重置为 0
 

示例：

输入
["Solution", "flip", "flip", "flip", "reset", "flip"]
[[3, 1], [], [], [], [], []]
输出
[null, [1, 0], [2, 0], [0, 0], null, [2, 0]]

解释
Solution solution = new Solution(3, 1);
solution.flip();  // 返回 [1, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
solution.flip();  // 返回 [2, 0]，因为 [1,0] 已经返回过了，此时返回 [2,0] 和 [0,0] 的概率应当相同
solution.flip();  // 返回 [0, 0]，根据前面已经返回过的下标，此时只能返回 [0,0]
solution.reset(); // 所有值都重置为 0 ，并可以再次选择下标返回
solution.flip();  // 返回 [2, 0]，此时返回 [0,0]、[1,0] 和 [2,0] 的概率应当相同
 

提示：

1 <= m, n <= 104
每次调用flip 时，矩阵中至少存在一个值为 0 的格子。
最多调用 1000 次 flip 和 reset 方法。

    Solution temp(3, 1);
    Print<int>::PrintOneDemionVector(temp.flip());
    Print<int>::PrintOneDemionVector(temp.flip());
    Print<int>::PrintOneDemionVector(temp.flip());
    Print<int>::PrintOneDemionVector(temp.flip());
    temp.reset();
    Print<int>::PrintOneDemionVector(temp.flip());
    Print<int>::PrintOneDemionVector(temp.flip());

链接：https://leetcode-cn.com/problems/random-flip-matrix

*/

#include <vector>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//    Solution(int m, int n) {
//        srand(time(nullptr));
//        this->total = m * n;
//        this->m = m;
//        this->n = n;
//    }
//
//    vector<int> flip() {
//        if (total == 0)
//            return {};
//        int x = rand() % total;
//        pair<int, int> ret;
//        if (map.count(x))
//            ret = { map[x] / n, map[x] % n };
//        else
//            ret = {x / n, x % n};
//        total--;
//        if (map.count(total))
//            map[x] = map[total];
//        else
//            map[x] = total;
//        return {ret.first, ret.second};
//    }
//
//    void reset() {
//        total = m * n;
//        map.clear();
//    }
//
//private:
//    int total;
//    int m;
//    int n;
//    unordered_map<int, int> map;
//};


class Solution {
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        total = m * n;
        bucket_size = sqrt(m * n);
        for (int i = 0; i < total; i += bucket_size)
            buckets.push_back({});
        srand(time(nullptr));
    }

    vector<int> flip() {
        int x = rand() % total;
        int sum_zero = 0;
        int curr = 0;
        total--;
        for (auto &bucket : buckets) {
            if (sum_zero + bucket_size - bucket.size() > x) {
                for (int i = 0; i < bucket_size; ++i) {
                    if (!bucket.count(curr + i)) {
                        if (sum_zero == x) {
                            bucket.emplace(curr + i);
                            return { (curr + i) / n, (curr + i) % n };
                        }
                        sum_zero++;
                    }
                }
            }
                
            curr += bucket_size;
            sum_zero += bucket_size - bucket.size();
        }
        return {};
    }

    void reset() {
        for (auto &bucker : buckets)
            bucker.clear();
        total = m * n;
    }

private:
    int m;
    int n;
    int bucket_size;
    int total;
    vector<unordered_set<int>> buckets;
};