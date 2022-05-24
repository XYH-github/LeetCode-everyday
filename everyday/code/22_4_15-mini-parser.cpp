/*

给定一个字符串 s 表示一个整数嵌套列表，实现一个解析它的语法分析器并返回解析的结果 NestedInteger 。

列表中的每个元素只可能是整数或整数嵌套列表

 

示例 1：

输入：s = "324",
输出：324
解释：你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
示例 2：

输入：s = "[123,[456,[789]]]",
输出：[123,[456,[789]]]
解释：返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
1. 一个 integer 包含值 123
2. 一个包含两个元素的嵌套列表：
    i.  一个 integer 包含值 456
    ii. 一个包含一个元素的嵌套列表
         a. 一个 integer 包含值 789
 

提示：

1 <= s.length <= 5 * 104
s 由数字、方括号 "[]"、负号 '-' 、逗号 ','组成
用例保证 s 是可解析的 NestedInteger
输入中的所有值的范围是 [-106, 106]

链接：https://leetcode.cn/problems/mini-parser

*/


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <string>
#include <stack>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    NestedInteger deserialize(string s) {
//        if (s[0] != '[')
//            return NestedInteger(stoi(s));
//        int len = s.size();
//        int i = 0;
//        int nums = 0;
//        stack<NestedInteger> stk;
//        while (i < len) {
//            if (s[i] == '[') {
//                stk.emplace(NestedInteger());
//                ++i;
//            }
//            else if (s[i] == ',' || s[i] == ']') {
//                if (isdigit(s[i - 1])) {
//                    stk.top().add(NestedInteger(nums));
//                }
//                if (s[i] == ']' && stk.size() > 1) {
//                    NestedInteger ni = stk.top();
//                    stk.pop();
//                    stk.top().add(ni);
//                }
//                ++i;
//            }
//            else {
//                int l = 0;
//                int k = i;
//                while (isdigit(s[++i])) {
//                    l++;
//                }
//                nums = stoi(s.substr(k, l + 1));
//            }
//        }
//        return stk.top();
//    }
//};


//class Solution {
//public:
//    int index = 0;
//    NestedInteger deserialize(string s) {
//        if (s[index] == '[') {
//            index++;
//            NestedInteger ni;
//            while (s[index] != ']') {
//                ni.add(deserialize(s));
//                if (s[index] == ',')
//                    index++;
//            }
//            index++;
//            return ni;
//        }
//        else {
//            int l = 0;
//            int k = index;
//            while (isdigit(s[++index])) {
//                l++;
//            }
//            return NestedInteger(stoi(s.substr(k, l + 1)));
//        }
//    }
//};