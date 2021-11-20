/*

给定一个正整数 n ，你可以做如下操作：

如果 n 是偶数，则用 n / 2替换 n 。
如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
n 变为 1 所需的最小替换次数是多少？

 

示例 1：

输入：n = 8
输出：3
解释：8 -> 4 -> 2 -> 1
示例 2：

输入：n = 7
输出：4
解释：7 -> 8 -> 4 -> 2 -> 1
或 7 -> 6 -> 3 -> 2 -> 1
示例 3：

输入：n = 4
输出：2
 

提示：

1 <= n <= 231 - 1

int num = 4;
    Solution temp;
    int result = temp.integerReplacement(num);
    cout << result << endl;

*/
#include <algorithm>
#include <unordered_map>
using namespace std;

//class Solution {
//public:
//    int integerReplacement(int n) {
//        if (n == 1)
//            return 0;
//        if (n % 2 == 0)
//            return 1 + integerReplacement(n / 2);
//        return 2 + min(integerReplacement(n / 2 + 1), 
//                integerReplacement(n / 2));
//    }
//};


//class Solution {
//private:
//    unordered_map<int, int> memo;
//
//public:
//    int integerReplacement(int n) {
//        if (n == 1) {
//            return 0;
//        }
//        if (memo.count(n)) {
//            return memo[n];
//        }
//        if (n % 2 == 0) {
//            return memo[n] = 1 + integerReplacement(n / 2);
//        }
//        return memo[n] = 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
//    }
//};


class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                ++ans;
                n /= 2;
            }
            else if (n % 4 == 1) {
                ans += 2;
                n /= 2;
            }
            else {
                if (n == 3) {
                    ans += 2;
                    n = 1;
                }
                else {
                    ans += 2;
                    n = n / 2 + 1;
                }
            }
        }
        return ans;
    }
};
