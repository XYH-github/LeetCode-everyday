/*

����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����

�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�

ʾ�� 1:

����: ������: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

���: "1(2(4))(3)"

����: ԭ�����ǡ�1(2(4)())(3())����
����ʡ�����в���Ҫ�Ŀ����Ŷ�֮��
�����ǡ�1(2(4))(3)����
ʾ�� 2:

����: ������: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

���: "1(2()(4))(3)"

����: �͵�һ��ʾ�����ƣ�
�������ǲ���ʡ�Ե�һ�����������ж���������֮���һ��һӳ���ϵ��

���ӣ�https://leetcode-cn.com/problems/construct-string-from-binary-tree

    Solution temp;
    int bin_input[] = { 1, 2, 3, -1, 4};
    temp.CreateBinTreeLevelOrder(bin_input, sizeof(bin_input) / sizeof(int));
    string ret = temp.tree2str(temp.GetRootNode());
    cout << ret << endl;

*/

#include "BinaryTree.h"
#include <functional>
using namespace std;

class Solution : public BinaryTree<int> {
public:
    string tree2str(TreeNode<int>* root) {
        string ret;
        function<void(TreeNode<int>*)> dfs = [&](TreeNode<int>* ptr) {
            if (ptr == nullptr)
                return;
            ret += to_string(ptr->val);
            if (ptr->left || ptr->right) {
                ret.push_back('(');
                dfs(ptr->left);
                ret.push_back(')');
            }
            if (ptr->right) {
                ret.push_back('(');
                dfs(ptr->right);
                ret.push_back(')');
            }
        };
        dfs(root);
        return ret;
    }
};
