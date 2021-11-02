/*

所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

 

示例 1：

输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
示例 2：

输入：s = "AAAAAAAAAAAAA"
输出：["AAAAAAAAAA"]

string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution temp;
	vector<string> result = temp.findRepeatedDnaSequences(str);
	Print<string>::PrintVectorForString(result);

*/
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// hasmap
//class Solution {
//    const int L = 10;
//public:
//    vector<string> findRepeatedDnaSequences(string s) {
//        vector<string> ans;
//        unordered_map<string, int> cnt;
//        int n = s.length();
//        for (int i = 0; i < n - L; ++i) {
//            string sub = s.substr(i, L);
//            if (++cnt[sub] == 2)
//                ans.push_back(sub);
//        }
//        return ans;
//    }
//};

class Solution {
	const int L = 10;
	unordered_map<char, int> dict = { {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		int n = s.length();
		if (n <= L)
			return ans;
		int x = 0;
		for (int i = 0; i < L - 1; ++i)
			x = (x << 2) | dict[s[i]];
		unordered_map<int, int> cnt;
		for (int i = 0; i <= n - L; ++i) {
			x = ((x << 2) | dict[s[i + L - 1]]) & ((1 << (2 * L)) - 1);
			if (++cnt[x] == 2)
				ans.push_back(s.substr(i, L));
		}
		return ans;
	}
};