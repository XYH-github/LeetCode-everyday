/*

这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。

 

示例 1：

输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
输出：3
解释：
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
示例 2：

输入：courses = [[1,2]]
输出：1
示例 3：

输入：courses = [[3,2],[4,3]]
输出：0
 

提示:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104

链接：https://leetcode-cn.com/problems/course-schedule-iii

    vector<vector<int>> courses = { {100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200} };
    Solution temp;
    int ret = temp.scheduleCourse(courses);
    cout << ret << endl;

*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//class Solution{
//public:
//    vector<int> old_vec;
//    vector<vector<int>> all_rank;
//    int scheduleCourse(vector<vector<int>>& courses) {
//        int len = courses.size();
//        old_vec = vector<int>(len);
//        for (int i = 0; i < len; ++i)
//            old_vec[i] = i;
//        //dfs(0, len - 1);
//        do {
//            all_rank.emplace_back(old_vec);
//        } while (next_permutation(old_vec.begin(), old_vec.end()));
//        int ret = 0;
//        for (vector<int> index : all_rank) {
//            int now_time = 0;
//            int now_num = 0;
//            for (int i = 0; i < len; ++i) {
//                if (courses[index[i]][1] >= courses[index[i]][0] + now_time) {
//                    now_time += courses[index[i]][0];
//                    now_num++;
//                }
//            }
//            ret = max(ret, now_num);
//        }
//        return ret;
//    }
//
//    //void dfs(int start, int end) {
//    //    if (start == end)
//    //        all_rank.emplace_back(old_vec);
//    //    else
//    //        for (int i = start; i <= end; ++i) {
//    //            swap(old_vec[start], old_vec[i]);
//    //            dfs(start + 1, end);
//    //            swap(old_vec[start], old_vec[i]);
//    //        }
//    //    return;
//    //}
//};


class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        priority_queue<int> queue;
        int time_now = 0;
        for (vector<int> index : courses) {
            if (index[0] + time_now <= index[1]) {
                time_now += index[0];
                queue.emplace(index[0]);
            }
            else {
                if (!queue.empty() && queue.top() > index[0]) {
                    time_now -= queue.top() - index[0];
                    queue.pop();
                    queue.push(index[0]);
                }
            }
        }
        return queue.size();
    }
};