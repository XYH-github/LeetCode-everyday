/*

����һ����־���� logs��ÿ����־�����Կո�ָ����ִ������һ����Ϊ��ĸ�����ֻ�ϵ� ��ʶ�� ��

�����ֲ�ͬ���͵���־��

��ĸ��־������ʶ��֮�⣬�����־���Сд��ĸ���
������־������ʶ��֮�⣬�����־����������
�밴����������־��������

���� ��ĸ��־ ������ ������־ ֮ǰ��
��ĸ��־ �����ݲ�ͬʱ�����Ա�ʶ���󣬰�������ĸ˳��������������ͬʱ������ʶ������
������־ Ӧ�ñ���ԭ�������˳��
������־������˳��

���ӣ�https://leetcode.cn/problems/reorder-data-in-log-files

    vector<string> logs = { "dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero" };
    Solution temp;
    vector<string> ret = temp.reorderLogFiles(logs);
    Print<string>::PrintOneDemionVector(ret);

*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    vector<string> reorderLogFiles(vector<string>& logs) {
//        vector<string> temp_logs;
//        for (auto iter = logs.begin(); iter != logs.end();) {
//            if (isdigit(*iter->rbegin())) {
//                temp_logs.emplace_back(*iter);
//                iter = logs.erase(iter);
//            }
//            else
//                iter++;
//        }
//        sort(logs.begin(), logs.end(), [&](const string& a, const string& b) {
//            string copy_a = a;
//            string copy_b = b;
//            char* ptr_a = &copy_a[0];
//            char* ptr_b = &copy_b[0];
//            while (*ptr_a != ' ')
//                ptr_a++;
//            while (*ptr_b != ' ')
//                ptr_b++;
//            *ptr_a = '\0', *ptr_b = '\0';
//            ptr_a++, ptr_b++;
//            if (string(ptr_a) == string(ptr_b))
//                return copy_a < copy_b;
//            else
//                return string(ptr_a) < string(ptr_b);
//        });
//        for (string log : temp_logs) {
//            logs.emplace_back(log);
//        }
//        return logs;
//    }
//};



class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        stable_sort(logs.begin(), logs.end(), [&](const string& a, const string& b) {
            int pos1 = a.find_first_of(" ");
            int pos2 = b.find_first_of(" ");
            bool isDigit1 = isdigit(a[pos1 + 1]);
            bool isDigit2 = isdigit(b[pos2 + 1]);
            if (isDigit1 && isDigit2) {
                return false;
            }
            if (!isDigit1 && !isDigit2) {
                string s1 = a.substr(pos1);
                string s2 = b.substr(pos2);
                if (s1 != s2) {
                    return s1 < s2;
                }
                return a < b;
            }
            return isDigit1 ? false : true;
            });
 
        return logs;
    }
};

