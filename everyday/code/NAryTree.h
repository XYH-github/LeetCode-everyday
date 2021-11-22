#pragma once
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
template <typename T>
struct TreeNode {
	T val;
	vector<TreeNode*> children;

	TreeNode() {};
	TreeNode(T _val) : val(_val){}
	TreeNode(T _val, vector<TreeNode*> _children) : val(_val), children(_children) {}
};

template <typename T>
class NAryTree {
public:
	NAryTree() : root(NULL) {}
	NAryTree(T value) : RefValue(value), root(NULL) {}
	~NAryTree() { Destroy(root); }

	void CreateNArrTreeLevelOrder(T* table, int n) { CreateNArrTreeLevelOrder(root, table, n);}
	void LevelOrder() { LevelOrder(root); }
	int maxDepth() { return maxDepth(root); }

private:
	void LevelOrder(TreeNode<T>* cur);
	void CreateNArrTreeLevelOrder(TreeNode<T>*& cur, T* table, int n);
	void Destroy(TreeNode<T>*& subtree);
	int maxDepth(TreeNode<T>*& subtree);
	TreeNode<T>* root;
	T RefValue;
};

/*

int table[] = { 1,NULL,2,3,4,5,NULL,NULL,6,7,NULL,8,NULL,9,10,NULL,NULL,11,NULL,12,NULL,13,NULL,NULL,14 };
	NAryTree<int> narytree;
	narytree.CreateNArrTreeLevelOrder(table, sizeof(table) / sizeof(table[0]));
	narytree.LevelOrder();
	cout << endl;
	cout << narytree.maxDepth();

*/


