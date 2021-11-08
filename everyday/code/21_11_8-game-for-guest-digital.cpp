/*

你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：

猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls", 公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows", 奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。

提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。

 

示例 1:

输入: secret = "1807", guess = "7810"
输出: "1A3B"
解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1807"
  |
"7810"
示例 2:

输入: secret = "1123", guess = "0111"
输出: "1A1B"
解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1123"        "1123"
  |      or     |
"0111"        "0111"
注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
示例 3：

输入：secret = "1", guess = "0"
输出："0A0B"
示例 4：

输入：secret = "1", guess = "1"
输出："1A0B"

*/
#include <string>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    string getHint(string secret, string guess) {
//        int count_a = 0, count_b = 0;
//        string::iterator it_a = secret.begin();
//        string::iterator it_b = guess.begin();
//        while (it_a != secret.end() && it_b != guess.end())
//            if (*it_a == *it_b) {
//                ++count_a;
//                secret.erase(it_a);
//                guess.erase(it_b);
//            }
//            else {
//                ++it_a;
//                ++it_b;
//            }
//        unordered_map<char, int> map_se, map_gu;
//        for (char index : secret)
//            ++map_se[index];
//        for (char index : guess)
//            ++map_gu[index];
//        for (auto index : map_se) 
//            count_b += map_gu.find(index.first) == map_gu.end() ? 0 :
//                min(index.second, map_gu[index.first]);
//        
//        return to_string(count_a) + "A" + to_string(count_b) + "B";
//    }
//};

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            }
            else {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            cows += min(cntS[i], cntG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";

    }
};