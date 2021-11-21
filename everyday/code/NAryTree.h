#pragma once
#include <vector>
#include <queue>

using namespace std;
template <typename T>
struct TreeNode {
	T val;
	vector<TreeNode*> children;

	TreeNode() {};
	TreeNode(T _val) : val(_val) : children(nullptr) {}
	TreeNode(T _val, vector<TreeNode*> _children) : val(_val), children(_children) {}
};

template <typename T>
class NAryTree {
public:
	NAryTree() : root(NULL) {}
	NAryTree(T value) : RefValue(value), root(NULL) {}
	~NAryTree() { Destroy(root); }

	void CreateNArrTreeLevelOrder() { CreateBinTreeLevelOrder(root); }
	void CreateNArrTreeLevelOrder(T* table, int n) { CreateBinTreeLevelOrder(root, table, n);}

private:
	void CreateNArrTreeLevelOrder(TreeNode<T>*& cur, T* table, int n);
	void Destroy(TreeNode<T>*& subtree);
	TreeNode<T>* root;
	T RefValue;
};


