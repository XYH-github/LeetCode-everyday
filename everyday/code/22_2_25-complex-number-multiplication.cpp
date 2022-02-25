/*

复数 可以用字符串表示，遵循 "实部+虚部i" 的形式，并满足下述条件：

实部 是一个整数，取值范围是 [-100, 100]
虚部 也是一个整数，取值范围是 [-100, 100]
i2 == -1
给你两个字符串表示的复数 num1 和 num2 ，请你遵循复数表示形式，返回表示它们乘积的字符串。

 

示例 1：

输入：num1 = "1+1i", num2 = "1+1i"
输出："0+2i"
解释：(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
示例 2：

输入：num1 = "1+-1i", num2 = "1+-1i"
输出："0+-2i"
解释：(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
 

提示：

num1 和 num2 都是有效的复数表示。

链接：https://leetcode-cn.com/problems/complex-number-multiplication

    string num1 = "1+-1i", num2 = "1+-1i";
    Solution temp;
    string ret = temp.complexNumberMultiply(num1, num2);
    cout << ret << endl;

*/

#include <string>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int len_1 = num1.size();
        int len_2 = num2.size();
        int start = 0;
        while (num1[start] != '+')
            start++;
        int num1_rel = stoi(num1.substr(0, start));
        int num1_img = stoi(num1.substr(start + 1, len_1 - start - 2));
        start = 0;
        while (num2[start] != '+')
            start++;
        int num2_rel = stoi(num2.substr(0, start));
        int num2_img = stoi(num2.substr(start + 1, len_2 - start - 2));
        int ret_rel = num1_rel * num2_rel - num1_img * num2_img;
        int ret_img = num1_rel * num2_img + num1_img * num2_rel;
        return to_string(ret_rel) + '+' + to_string(ret_img) + 'i';
    }
};

//class Solution {
//public:
//    string complexNumberMultiply(string num1, string num2) {
//        regex re("\\+|i");
//        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
//        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
//        int real1 = stoi(complex1[0]);
//        int imag1 = stoi(complex1[1]);
//        int real2 = stoi(complex2[0]);
//        int imag2 = stoi(complex2[1]);
//        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
//    }
//};
//
//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/complex-number-multiplication/solution/fu-shu-cheng-fa-by-leetcode-solution-163i/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。