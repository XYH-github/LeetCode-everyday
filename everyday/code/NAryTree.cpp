#include "NAryTree.h"

template<typename T>
void NAryTree<T>::LevelOrder(TreeNode<T>* cur)
{
	queue<TreeNode<T>*> queue;
	cout << cur->val << ", ";
	cout << "NULL" << ", ";
	queue.push(cur);
	while (!queue.empty()) {
		vector<TreeNode<T>*> vec = queue.front()->children;
		queue.pop();
		int i = 0;
		if (vec.empty())
			break;
		while (vec[i] != nullptr) {
			cout << vec[i]->val << ", ";
			queue.push(vec[i++]);
		}
		cout << "NULL" << ", ";
	}
}

template<typename T>
void NAryTree<T>::CreateNArrTreeLevelOrder(TreeNode<T>*& cur, T* table, int n)
{
	queue<TreeNode<T>*> queue;
	T *ch = table;
	int temp = 0;
	cur = new TreeNode<T>(*ch);
	queue.push(cur);
	ch++, temp++;
	ch++, temp++;
	while (temp < n) {
		TreeNode<T>* p = queue.front();
		queue.pop();
		vector<TreeNode<T>*> vec;
		
		while (temp < n && *ch != NULL) {
			TreeNode<T>* tmp_ptr = new TreeNode<T>(*ch);
			ch++, temp++;
			queue.push(tmp_ptr);
			vec.push_back(tmp_ptr);
		}
		vec.push_back(nullptr);
		ch++, temp++;
		p->children = vec;
	}
}

template<typename T>
void NAryTree<T>::Destroy(TreeNode<T>*& subtree)
{
	if (subtree != nullptr) {
		vector<TreeNode<T>*> vec = subtree->children;
		int i = 0;
		while (!vec.empty() && vec[i] != nullptr) 
			Destroy(vec[i++]);
		delete(subtree);
		subtree = nullptr;
	}
}

template<typename T>
int NAryTree<T>::maxDepth(TreeNode<T>*& subtree)
{
	if (subtree->children.empty() || subtree->children[0] == nullptr)
		return 1;
	int num = 0;
	for (auto index : subtree->children)
		if (index != nullptr)
			num = max(maxDepth(index), num);
	return 1 + num;
}

