/*

将非负整数 num 转换为其对应的英文表示。

 

示例 1：

输入：num = 123
输出："One Hundred Twenty Three"
示例 2：

输入：num = 12345
输出："Twelve Thousand Three Hundred Forty Five"
示例 3：

输入：num = 1234567
输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
示例 4：

输入：num = 1234567891
输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

*/
#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<string> singles = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    vector<string> teens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    vector<string> tens = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    vector<string> thousands = { "", "Thousand", "Million", "Billion" };


public:
    string ans;
    int poi_sta = 0;
    bool mode = 0;
    int len = 0;
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        else
            recuTran(num);
        return ans;
    }
    void recuTran(int num) {
        ++poi_sta;
        int poi = poi_sta;
        int temp = num % 10;
        if (num / 10)
            ans = numberToWords(num / 10);
        if (poi % 3 == 0 && temp != 0) {
            ans.append(singles[temp]);
            ans.append(" Hundred ");
        }
        else if (poi % 3 == 2) {
            mode = 0;
            if (temp > 1) {
                ans.append(tens[temp]);
                ans.append(" ");
            }
            else if (temp == 1)
                mode = 1;
        }
        else if (poi % 3 == 1)
        {
            if (mode == 0) {
                ans.append(singles[temp]);
                if (temp != 0)
                    ans.append(" ");
            }
            else if (mode == 1) {
                ans.append(teens[temp]);
                ans.append(" ");
            }
            if (ans.length() != len) {
                ans.append(thousands[poi / 3]);
                ans.append(" ");
            }
            len = ans.length();
            if (poi == 1) {
                while (ans[ans.length() - 1] == ' ')
                    ans = ans.substr(0, ans.length() - 1);
            }
                
        }
    }

};



