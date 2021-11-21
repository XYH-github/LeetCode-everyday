#include "NAryTree.h"

template<typename T>
void NAryTree<T>::CreateNArrTreeLevelOrder(TreeNode<T>*& cur, T* table, int n)
{
	queue<TreeNode<T>*> queue;
	T *ch = table;
	int temp = 0;
	cur = new TreeNode<T>(*ch);
	queue.push(cur);
	ch++, temp++;
	while (temp < n) {
		TreeNode<T> *p = queue.
	}
}

template<typename T>
void NAryTree<T>::Destroy(TreeNode<T>*& subtree)
{
	if (subtree != nullptr) {
		TreeNode<T>* p = subtree->children;
		while (p != nullptr) 
			Destroy(p++);
		delete(subtree);
		subtree = nullptr;
		return;
	}
}

