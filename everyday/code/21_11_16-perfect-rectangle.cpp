/*

给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，右上顶点是 (ai, bi) 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；否则，返回 false 。

 
示例 1：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
输出：true
解释：5 个矩形一起可以精确地覆盖一个矩形区域。
示例 2：


输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
输出：false
解释：两个矩形之间有间隔，无法覆盖成一个矩形。
示例 3：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
输出：false
解释：图形顶端留有空缺，无法覆盖成一个矩形。
示例 4：


输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
输出：false
解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。

链接：https://leetcode-cn.com/problems/perfect-rectangle

*/
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//    bool isRectangleCover(vector<vector<int>>& rectangles) {
//        vector<int>max_rectangle(rectangles[0]);
//        vector<int>tem_rectangle(rectangles[0]);
//        for (auto index : rectangles) {
//            if (index[0] <= max_rectangle[0] && index[1] <= max_rectangle[1])
//                max_rectangle[0] = index[0], max_rectangle[1] = index[1];
//            if (index[2] >= max_rectangle[2] && index[3] >= max_rectangle[3])
//                max_rectangle[2] = index[2], max_rectangle[3] = index[3];
//            tem_rectangle[0] = min(tem_rectangle[0], index[0]);
//            tem_rectangle[1] = min(tem_rectangle[1], index[1]);
//            tem_rectangle[2] = max(tem_rectangle[2], index[2]);
//            tem_rectangle[3] = max(tem_rectangle[3], index[3]);
//        }
//        if (max_rectangle != tem_rectangle)
//            return false;
//        int area = 0;
//        for (auto index : rectangles)
//            area += (index[3] - index[1]) * (index[2] - index[0]);
//        if (area != ((max_rectangle[3] - max_rectangle[1]) * 
//            (max_rectangle[2] - max_rectangle[0])))
//            return false;
//        vector<vector<bool>> mask(max_rectangle[3] - max_rectangle[1], 
//            vector<bool>(max_rectangle[2] - max_rectangle[0], false));
//        for (auto index : rectangles) 
//            for (int i = index[1]; i < index[3]; ++i)
//                for (int j = index[0]; j < index[2]; ++j)
//                    mask[i - max_rectangle[1]][j - max_rectangle[0]] = true;
//        for (auto index : mask)
//            for (auto index2 : index)
//                if (index2 == false)
//                    return false;
//        return true;
//    }
//};

//class Solution {
//public:
//    bool isRectangleCover(vector<vector<int>>& rectangles) {
//        vector<int>max_rectangle(rectangles[0]);
//        for (auto index : rectangles) {
//            max_rectangle[0] = min(max_rectangle[0], index[0]);
//            max_rectangle[1] = min(max_rectangle[1], index[1]);
//            max_rectangle[2] = max(max_rectangle[2], index[2]);
//            max_rectangle[3] = max(max_rectangle[3], index[3]);
//        }
//        vector<vector<int>> mask(max_rectangle[3] - max_rectangle[1],
//            vector<int>(max_rectangle[2] - max_rectangle[0], 0));
//        for (auto index : rectangles)
//            for (int i = index[1]; i < index[3]; ++i)
//                for (int j = index[0]; j < index[2]; ++j)
//                    mask[i - max_rectangle[1]][j - max_rectangle[0]] += 1;
//        for (auto index : mask)
//            for (auto index2 : index)
//                if (index2 != 1)
//                    return false;
//        return true;
//    }
//};



//class Solution {
//public:
//    typedef pair<int, int> Point;
//    bool isRectangleCover(vector<vector<int>>& rectangles) {
//        vector<int>max_rectangle(rectangles[0]);
//        for (auto index : rectangles) {
//            max_rectangle[0] = min(max_rectangle[0], index[0]);
//            max_rectangle[1] = min(max_rectangle[1], index[1]);
//            max_rectangle[2] = max(max_rectangle[2], index[2]);
//            max_rectangle[3] = max(max_rectangle[3], index[3]);
//        }
//        map<Point, int> cnt;
//        long area = 0;
//        for (auto rect : rectangles) {
//            area += (long) (rect[3] - rect[1]) * (rect[2] - rect[0]);
//            cnt[Point(rect[0], rect[1])] += 1;
//            cnt[Point(rect[0], rect[3])] += 1;
//            cnt[Point(rect[2], rect[3])] += 1;
//            cnt[Point(rect[2], rect[1])] += 1;
//        }
//        if (area != (long long)((max_rectangle[3] - max_rectangle[1]) *
//            (max_rectangle[2] - max_rectangle[0]))
//            || !cnt.count(Point(max_rectangle[0], max_rectangle[1]))
//            || !cnt.count(Point(max_rectangle[0], max_rectangle[3]))
//            || !cnt.count(Point(max_rectangle[2], max_rectangle[3]))
//            || !cnt.count(Point(max_rectangle[2], max_rectangle[1])))
//            return false;
//        cnt.erase(Point(max_rectangle[0], max_rectangle[1]));
//        cnt.erase(Point(max_rectangle[0], max_rectangle[3]));
//        cnt.erase(Point(max_rectangle[2], max_rectangle[3]));
//        cnt.erase(Point(max_rectangle[2], max_rectangle[1]));
//        for (auto entry : cnt)
//            if (entry.second != 2 && entry.second != 4)
//                return false;
//        return true;
//    }
//};


//class Solution {
//public:
//    typedef pair<int, int> Point;
//    bool isRectangleCover(vector<vector<int>>& rectangles) {
//        int length = rectangles.size();
//        vector<vector<int>> vertical_edge(length * 2, vector<int>(4));
//        int index_poi = 0;
//        for (auto index : rectangles){
//            vertical_edge[index_poi++] = { index[0], index[1], index[3], 0 };
//            vertical_edge[index_poi++] = { index[2], index[1], index[3], 1 };
//        }
//        sort(vertical_edge.begin(), vertical_edge.end(), cmpr);
//        length <<= 1;
//        for (int l = 0; l < length;) {
//            vector<Point> left_edge;
//            vector<Point> right_edge;
//            int r = l;
//            while (r < length && vertical_edge[l][0] == vertical_edge[r][0])
//                ++r;
//            for (int i = l; i < r; ++i) {
//                vector<Point>* p;
//                Point cur(vertical_edge[i][1], vertical_edge[i][2]);
//                if (vertical_edge[i][3] == 0)
//                    p = &left_edge;
//                else
//                    p = &right_edge;
//                if (p->empty())
//                    p->push_back(cur);
//                else {
//                    Point pre = p->at(p->size()-1);
//                    if (pre.second > cur.first)
//                        return false;
//                    else if (pre.second == cur.first)
//                        p->at(p->size() - 1).second = cur.second;
//                    else
//                        p->push_back(cur);
//                }
//            }
//            if (l > 0 && r < length) {
//                if (left_edge.size() != right_edge.size())
//                    return false;
//                for (int i = 0; i < left_edge.size(); ++i)
//                    if (left_edge[i] != right_edge[i])
//                        return false;
//            }
//            else
//                if (left_edge.size() + right_edge.size() != 1)
//                    return false;
//            l = r;
//        }
//        return true;
//    }
//
//    static bool cmpr(vector<int> x, vector<int> y) {
//        if (x[0] == y[0])
//            return x[1] < y[1];
//        else
//            return x[0] < y[0];
//    }
//    
//};


//class Solution {
//public:
//    bool isRectangleCover(vector<vector<int>>& rectangles) {
//        map<pair<int, int>, int> mp;
//        for (auto& item : rectangles) {
//            int x = item[0], y = item[1], a = item[2], b = item[3];
//            if (++mp[{x, y}] == 0) mp.erase({ x, y });
//            if (--mp[{x, b}] == 0) mp.erase({ x, b });
//            if (++mp[{a, b}] == 0) mp.erase({ a, b });
//            if (--mp[{a, y}] == 0) mp.erase({ a, y });
//        }
//        return mp.size() == 4 && mp.begin()->second == 1;
//    }
//};

namespace std {
    template<> struct hash<pair<int, int>> {
        inline size_t operator()(const pair<int, int> v) const {
            hash<int> h;
            return (h(v.first) << 32) + h(v.second);
        }
    };
}

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<pair<int, int>, int> mp;
        for (const auto& rect : rectangles) {
            int x = rect[0];
            int y = rect[1];
            int a = rect[2];
            int b = rect[3];
            int& p0 = mp[{x, y}];
            int& p1 = mp[{x, b}];
            int& p2 = mp[{a, y}];
            int& p3 = mp[{a, b}];
            if (p0 & 1) {
                return false;
            }
            p0 |= 1;
            if (p1 & 2) {
                return false;
            }
            p1 |= 2;
            if (p2 & 4) {
                return false;
            }
            p2 |= 4;
            if (p3 & 8) {
                return false;
            }
            p3 |= 8;
        }
        bool flag1 = false;
        bool flag2 = false;
        bool flag3 = false;
        bool flag4 = false;


        for (const auto& index : mp) {
            if (index.second == 9 || index.second == 6) {
                return false;
            }
            if (index.second == 1) {
                if (flag1) {
                    return false;
                }
                flag1 = true;
            }
            if (index.second == 2) {
                if (flag2) {
                    return false;
                }
                flag2 = true;
            }
            if (index.second == 4) {
                if (flag3) {
                    return false;
                }
                flag3 = true;
            }
            if (index.second == 8) {
                if (flag4) {
                    return false;
                }
                flag4 = true;
            }
        }
        return flag1 && flag2 && flag3 && flag4;
    }
};