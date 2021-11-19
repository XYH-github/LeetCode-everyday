#pragma once
#include <stack>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
template <typename T>
struct TreeNode {
	T val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {};
	TreeNode(T x) : val(x), left(nullptr), right(nullptr) {};
	TreeNode(T x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

template <typename T>
class BinaryTree{
public:
	// constructor
	BinaryTree() : root(NULL) {}

	// constructor, ref endflag
	BinaryTree(T value) : RefValue(value), root(NULL) {}

	// destructor
	~BinaryTree() { Destroy(root); }

	TreeNode<T>* GetRootNode() { return root; }
	void CreateBinTree() { CreateBinTree(root); }
	void CreateBinTree(T* table) { CreateBinTree(root, table); }
	void CreateBinTreePreOrder() { CreateBinTreePreOrder(root); }
	void CreateBinTreePreOrder(T* table) { CreateBinTreePreOrder(root, table); }
	void CreateBinTreeByPre_In(const T* pre, const T* in, int n) { CreateBinTreeByPre_In(root, pre, in, n); }
	void CreateBinTreeByPos_In(const T* pos, const T* in, int n) { CreateBinTreeByPos_In(root, pos, in, n); }

	void PreOrder() { PreOrder(root); }
	void InOrder() { InOrder(root); }
	void PosOrder() { PosOrder(root); }

	void PreOrderNorec() { PreOrderNorec(root); }
	void InOrderNorec() { InOrderNorec(root); }
	void PosOrderNorec() { PosOrderNorec(root); }

	void PreOrderAndEnd() { PreOrderAndEnd(root); }
	void PreOrderNorec2() { PreOrderNorec2(root); }

	void LevelOrder() { LevelOrder(root); }

	int Size() { return Size(root); }
	int Height() { return Height(root); }

	void PrintBinTree() { PrintBinTree(root); };
	
	

	TreeNode<T>* Parent(TreeNode<T>* subtree, TreeNode<T>* cur);
	bool Equal(TreeNode<T>* a, TreeNode<T>* b);
	
private:
	void CreateBinTree(TreeNode<T>*& root);
	void CreateBinTree(TreeNode<T>*& root, T* table);
	void CreateBinTreePreOrder(TreeNode<T>*& cur);
	void CreateBinTreePreOrder(TreeNode<T>*& cur, T* table);
	void CreateBinTreeByPre_In(TreeNode<T>*& cur, const T* pre, const T* in, int n);
	void CreateBinTreeByPos_In(TreeNode<T>*& cur, const T* pos, const T* in, int n);
	void Destroy(TreeNode<T>*& subtree);

	void PreOrder(TreeNode<T>* cur);
	void InOrder(TreeNode<T>* cur);
	void PosOrder(TreeNode<T>* cur);

	void PreOrderNorec(TreeNode<T>* cur);
	void InOrderNorec(TreeNode<T>* cur);
	void PosOrderNorec(TreeNode<T>* cur);

	void PreOrderAndEnd(TreeNode<T>* cur);
	void PreOrderNorec2(TreeNode<T>* cur);

	void LevelOrder(TreeNode<T>* cur);
	void PrintBinTree(TreeNode<T>* cur);

	int Size(TreeNode<T>* cur);
	int Height(TreeNode<T>* cur);

	TreeNode<T>* root;
	T RefValue;	
};