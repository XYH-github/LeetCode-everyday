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
	void CreateBinTreePreOrder(T* table) { T* p = table; CreateBinTreePreOrder(root, p); }
	void CreateBinTreeByPre_In(const T* pre, const T* in, int n) { CreateBinTreeByPre_In(root, pre, in, n); }
	void CreateBinTreeByPos_In(const T* pos, const T* in, int n) { CreateBinTreeByPos_In(root, pos, in, n); }
	void CreateBinTreeLevelOrder() { CreateBinTreeLevelOrder(root); }
	void CreateBinTreeLevelOrder(T* table, int n) { CreateBinTreeLevelOrder(root, table, n); }
	

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
	int NodeTilt() { return NodeTilt(root); }
	int SunNode() { return SunNode(root); }
	int OrderFindTilt() { return OrderFindTilt(root); }
	int OrderRecTilt() { int result = 0;  OrderRecTilt(root, result); return result; }

	void PrintBinTree() { PrintBinTree(root); };
	void PrintBinTreeNoRec() { PrintBinTreeNoRec(root); }
	
	

	TreeNode<T>* Parent(TreeNode<T>* subtree, TreeNode<T>* cur);
	bool Equal(TreeNode<T>* a, TreeNode<T>* b);
	
private:
	void CreateBinTree(TreeNode<T>*& root);
	void CreateBinTree(TreeNode<T>*& root, T* table);
	void CreateBinTreePreOrder(TreeNode<T>*& cur);
	void CreateBinTreePreOrder(TreeNode<T>*& cur, T*& table);
	void CreateBinTreeByPre_In(TreeNode<T>*& cur, const T* pre, const T* in, int n);
	void CreateBinTreeByPos_In(TreeNode<T>*& cur, const T* pos, const T* in, int n);
	void CreateBinTreeLevelOrder(TreeNode<T>*& root);
	void CreateBinTreeLevelOrder(TreeNode<T>*& root, T* table, int n);
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
	void PrintBinTreeNoRec(TreeNode<T>* cur);

	int Size(TreeNode<T>* cur);
	int Height(TreeNode<T>* cur);
	int NodeTilt(TreeNode<T>* cur);
	int SunNode(TreeNode<T>* cur);
	int OrderFindTilt(TreeNode<T>* cur);
	int OrderRecTilt(TreeNode<T>* cur, int &result);

	TreeNode<T>* root;
	T RefValue;	
};

/*


string table = "1(2(4,5(8,9)),3(6,7))";
	BinaryTree<char> bintree('#');
	bintree.CreateBinTree((char*)table.c_str());
	bintree.PreOrder();
	cout << endl;
	bintree.PreOrderNorec();
	cout << endl;
	bintree.PreOrderNorec2();
	cout << endl;
	bintree.PreOrderAndEnd();
	cout << endl;

	bintree.InOrder();
	cout << endl;
	bintree.InOrderNorec();
	cout << endl;

	bintree.PosOrder();
	cout << endl;
	bintree.PosOrderNorec();
	cout << endl;

	bintree.LevelOrder();
	cout << endl;

	bintree.PrintBinTree();
	cout << endl;

	string table2_str = "1 2 4 # # 5 8 # # 9 # # 3 6 # # 7 # #";
	Print<string>::StringRemoveSpace(table2_str);
	BinaryTree<char> bintree2('#');
	char* table2 = (char *)table2_str.c_str();
	bintree2.CreateBinTreePreOrder(table2);

	bintree2.PreOrder();
	cout << endl;
	bintree2.InOrder();
	cout << endl;
	bintree2.PosOrder();
	cout << endl;

	string table_pre = "1 2 4 5 8 9 3 6 7";
	string table_in = "4 2 8 5 9 1 6 3 7";
	string table_pos = "4 8 9 5 2 6 7 3 1";
	Print<string>::StringRemoveSpace(table_pre);
	Print<string>::StringRemoveSpace(table_in);
	Print<string>::StringRemoveSpace(table_pos);
	BinaryTree<char> bintree3('#');
	bintree3.CreateBinTreeByPre_In((char*) table_pre.c_str(), (char *)table_in.c_str(), table_pre.length());
	BinaryTree<char> bintree4('#');
	bintree4.CreateBinTreeByPos_In((char*)table_pos.c_str(), (char*)table_in.c_str(), table_pre.length());

	bintree3.PreOrder();
	cout << endl;
	bintree3.InOrder();
	cout << endl;
	bintree3.PosOrder();
	cout << endl;

	bintree4.PreOrder();
	cout << endl;
	bintree4.InOrder();
	cout << endl;
	bintree4.PosOrder();
	cout << endl;

	cout << bintree3.Size() << endl;
	cout << bintree3.Height() << endl;
	bintree3.PrintBinTree();
	cout << endl;
	bintree3.PrintBinTreeNoRec();
	cout << endl;

	cout << bintree4.Size() << endl;
	cout << bintree4.Height() << endl;
	bintree4.PrintBinTree();
	cout << endl;
	bintree4.PrintBinTreeNoRec();
	cout << endl;

*/