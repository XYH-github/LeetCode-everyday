/*

累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。

说明：累加序列里的数 不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况。

 

示例 1：

输入："112358"
输出：true
解释：累加序列为: 1, 1, 2, 3, 5, 8 。1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
示例 2：

输入："199100199"
输出：true
解释：累加序列为: 1, 99, 100, 199。1 + 99 = 100, 99 + 100 = 199
 

提示：

1 <= num.length <= 35
num 仅由数字（0 - 9）组成

链接：https://leetcode-cn.com/problems/additive-number

    string input_string = "112358";
    Solution temp;
    bool result = temp.isAdditiveNumber(input_string);
    cout << result << endl;

*/
#include <string>
using namespace std;

//class Solution {
//public:
//    bool isAdditiveNumber(string num) {
//        int i_max = (num.size() - 1) >> 1;
//        if (num[0] == '0')
//            i_max = 1;
//        for (int i = 1; i <= i_max; ++i) {
//            int j_max = max(num.size() - i, ((num.size() + i) >> 1));
//            if (num[i] == '0')
//                j_max = i + 1;
//            for (int j = i + 1; j <= j_max; ++j)
//                if (isAdditive(num, i, j))
//                    return true;
//        }
//        return false;    
//    }
//
//    bool isAdditive(string num, int poi_first, int poi_second) {
//        long long first = atoll(num.substr(0, poi_first).c_str());
//        long long second = atoll(num.substr(poi_first, poi_second - poi_first).c_str());
//        int num_bit = max(poi_first, poi_second - poi_first);
//        int poi_now = poi_second;
//        do {
//            //int sum = first + second;
//            if (num[poi_now] == '0') {
//                num_bit = 1;
//                if (first + second != 0)
//                    return false;
//            }
//            long long sum = atoll(num.substr(poi_now, num_bit).c_str());
//            while (first != atoll(num.substr(poi_now, num_bit).c_str()) - second) 
//                if (atoi(num.substr(poi_now, ++num_bit).c_str()) - second > first || poi_now + num_bit > num.size())
//                    return false;
//            poi_now += num_bit;
//            second = first + second;
//            first = second - first;
//        } while (poi_now < num.size());
//        return true;
//    }
//};


//class Solution {
//public:
//    string num;
//    int n;
//    vector<vector<int>> list;
//    bool isAdditiveNumber(string _num) {
//        num = _num;
//        n = _num.size();
//        return dfs(0);
//    }
//    bool dfs(int u) {
//        int m = list.size();
//        if (u == n) return m >= 3; //至少包含3个数
//        int max = num[u] == '0' ? u + 1 : n; //处理前导0
//        vector<int> cur;
//        for (int i = u; i < max; i++) { //枚举[u,n - 1]
//            cur.insert(cur.begin(), num[i] - '0');
//            if (m < 2 or check(list[m - 2], list[m - 1], cur)) {
//                list.push_back(cur);
//                if (dfs(i + 1)) return true;
//                list.pop_back();
//            }
//        }
//        return false;
//    }
//    bool check(vector<int>& a, vector<int>& b, vector<int>& c) {
//        vector<int> ans;
//        int t = 0;
//        for (int i = 0; i < a.size() or i < b.size(); i++) {
//            if (i < a.size()) t += a[i];
//            if (i < b.size()) t += b[i];
//            ans.push_back(t % 10);
//            t /= 10;
//        }
//        if (t) ans.push_back(1); //处理最高位的进位
//        bool ok = (c.size() == ans.size()); //检查长度
//        for (int i = 0; i < c.size() and ok; i++) {
//            if (c[i] != ans[i]) ok = false; //逐位检查
//        }
//        return ok;
//    }
//};



class Solution {
public:
    bool isAdditiveNumber(string num) {
        int i_max = (num.size() - 1) >> 1;
        if (num[0] == '0')
            i_max = 1;
        for (int i = 1; i <= i_max; ++i) {
            int j_max = max(num.size() - i, ((num.size() + i) >> 1));
            if (num[i] == '0')
                j_max = i + 1;
            for (int j = i + 1; j <= j_max; ++j)
                if (isAdditive(num, i, j))
                    return true;
        }
        return false;
    }

    bool isAdditive(string num, int poi_first, int poi_second) {
        string first = num.substr(0, poi_first);
        string second = num.substr(poi_first, poi_second - poi_first);
        int poi_now = poi_second;
        do {
            string sum = stringAdd(first, second);
            
            if (num.substr(poi_now, sum.size()) != sum)
                return false;
            poi_now += sum.size();
            first = second;
            second = sum;
        } while (poi_now < num.size());
        return true;
    }
    string stringAdd(string a, string b) {
        string result;
        char carry = 0;
        char cur = 0;
        for (auto iter_a = a.rbegin(), iter_b = b.rbegin(); iter_a != a.rend() || iter_b != b.rend() || carry != 0;) {
            cur = carry;
            if (iter_a != a.rend()) {
                cur += *iter_a - '0';
                iter_a++;
            }
            if (iter_b != b.rend()) {
                cur += *iter_b - '0';
                iter_b++;
            }
            carry = cur / 10;
            cur %= 10;
            result.push_back(cur + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};