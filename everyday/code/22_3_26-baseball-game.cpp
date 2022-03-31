/*

��������һ�������������ư�������ļ�¼Ա���ⳡ���������ɻغ���ɣ���ȥ���غϵĵ÷ֿ��ܻ�Ӱ���Ժ󼸻غϵĵ÷֡�

������ʼʱ����¼�ǿհ׵ġ����õ�һ����¼�������ַ����б� ops������ ops[i] ������Ҫ��¼�ĵ� i �������ops ��ѭ��������

���� x - ��ʾ���غ��»�÷��� x
"+" - ��ʾ���غ��»�õĵ÷���ǰ���ε÷ֵ��ܺ͡���Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���������Ч�ķ�����
"D" - ��ʾ���غ��»�õĵ÷���ǰһ�ε÷ֵ���������Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
"C" - ��ʾǰһ�ε÷���Ч������Ӽ�¼���Ƴ�����Ŀ���ݱ�֤��¼�˲���ʱǰ�����Ǵ���һ����Ч�ķ�����
���㷵�ؼ�¼�����е÷ֵ��ܺ͡�

���ӣ�https://leetcode-cn.com/problems/baseball-game

    vector<string> ops = { "5", "2", "C", "D", "+" };
    Solution temp;
    int ret = temp.calPoints(ops);
    cout << ret << endl;

*/

#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        int ret = 0;
        for (string op : ops) {
            if (op == "C") {
                ret -= stk.top();
                stk.pop();
            }
            else if (op == "D") {
                int temp = stk.top();
                ret += temp * 2;
                stk.emplace(temp * 2);
            }
            else if (op == "+") {
                int top = stk.top();
                stk.pop();
                int temp = stk.top();
                stk.emplace(top);
                stk.emplace(top + temp);
                ret += top + temp;
            }
            else {
                stk.emplace(atoi(op.c_str()));
                ret += atoi(op.c_str());
            }
        }
        return ret;
    }
};