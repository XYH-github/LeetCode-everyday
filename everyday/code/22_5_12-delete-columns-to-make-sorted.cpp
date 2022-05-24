/*

������ n ��Сд��ĸ�ַ�����ɵ����� strs������ÿ���ַ���������ȡ�

��Щ�ַ�������ÿ��һ�У��ų�һ���������磬strs = ["abc", "bce", "cae"] ��������Ϊ��

abc
bce
cae
����Ҫ�ҳ���ɾ�� ���ǰ��ֵ����������е� �С�����������ӣ��±�� 0 ��ʼ���У��� 0��'a', 'b', 'c'������ 2��'c', 'e', 'e'�����ǰ��������еģ����� 1��'b', 'c', 'a'�����ǣ�����Ҫɾ���� 1 ��

��������Ҫɾ����������

���ӣ�https://leetcode.cn/problems/delete-columns-to-make-sorted

    vector<string> strs = { "cba", "daf", "ghi" };
    Solution temp;
    int ret = temp.minDeletionSize(strs);
    cout << ret << endl;

*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs.size();
        int ret = 0;
        vector<bool> delete_cell(strs[0].size());
        string cmp_temp = strs[0];
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < strs[i].size(); ++j)
                if (!delete_cell[j] && strs[i][j] < cmp_temp[j])
                    delete_cell[j] = true;
            cmp_temp = strs[i];
        }
        for (bool cell : delete_cell) {
            if (cell)
                ret++;
        }
        return ret;
    }
};