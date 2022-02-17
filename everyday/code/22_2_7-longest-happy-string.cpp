/*

如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

s 是一个尽可能长的快乐字符串。
s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
s 中只含有 'a'、'b' 、'c' 三种字母。
如果不存在这样的字符串 s ，请返回一个空字符串 ""。

 

示例 1：

输入：a = 1, b = 1, c = 7
输出："ccaccbcc"
解释："ccbccacc" 也是一种正确答案。
示例 2：

输入：a = 2, b = 2, c = 1
输出："aabbc"
示例 3：

输入：a = 7, b = 1, c = 0
输出："aabaa"
解释：这是该测试用例的唯一正确答案。
 

提示：

0 <= a, b, c <= 100
a + b + c > 0

链接：https://leetcode-cn.com/problems/longest-happy-string

    int a = 1, b = 1, c = 7;
    Solution temp;
    string ret = temp.longestDiverseString(a, b, c);
    cout << ret << endl;

*/

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//class Solution {
//public:
//    string longestDiverseString(int a, int b, int c) {
//        string ret;
//        vector<pair<int, char>> arr = { {a, 'a'}, {b, 'b'}, {c, 'c'}};
//
//        while (true) {
//            sort(arr.begin(), arr.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
//                return a.first > b.first;
//                });
//            bool has_next = false;
//            for (auto &index : arr) {
//                int m = ret.size();
//                if (index.first <= 0)
//                    break;
//                if (m >= 2 && ret[m - 2] == index.second && ret[m - 1] == index.second)
//                    continue;
//                has_next = true;
//                ret.push_back(index.second);
//                index.first--;
//                break;
//            }
//            if (!has_next)
//                break;
//        }
//        return ret;
//    }
//};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ret;
        auto cmpy = [&](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first < b.first;
        };
        //priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmpy)> pri_queue(cmpy);
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pri_queue;
        pri_queue.push( { a, 'a' } );
        pri_queue.push( { b, 'b' } );
        pri_queue.push( { c, 'c' } );
        while (true) {
            pair<int, char> pair_max = pri_queue.top();
            pri_queue.pop();
            int m = ret.size();
            if (m >= 2 && ret[m - 2] == pair_max.second && ret[m - 1] == pair_max.second) {
                pair<int, char> pair_tmp = pri_queue.top();
                pri_queue.pop();
                pri_queue.emplace(pair_max);
                pair_max = pair_tmp;
            }
            if (pair_max.first <= 0)
                break;
            ret.push_back(pair_max.second);
            pair_max.first--;
            pri_queue.emplace(pair_max);
        }
        return ret; 
    }
    struct cmp {
        bool operator ()(const pair<int, char>& a, const pair<int, char>& b) {
            return a.first < b.first;
        }
    };
};