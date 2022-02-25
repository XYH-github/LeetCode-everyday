#include "BinaryTree.h"

template <typename T>
//A£¨B£¨D£¬E£¨G£¬£©£©£¬C£¨£¬F£©£©# 
void BinaryTree<T>::CreateBinTree(TreeNode<T> *&BT) {
	stack<TreeNode<T>*> stk;
	BT = NULL;
	TreeNode<T>* p, * t;
	int k;
	char ch;
	cin >> ch;
	while (ch != RefValue)
	{
		switch (ch)
		{
		case '(':
			stk.push(p);
			k = 1;
			break;

		case ')':
			stk.pop();
			break;

		case ',':
			k = 2;
			break;

		default:
			p = new TreeNode<T>(ch);
			if (BT == NULL)
				BT = p;

			else if (k == 1) {
				t = stk.top();
				t->left = p;
			}
			else {
				t = stk.top();
				t->right = p;
			}
		}
		cin >> ch;
	}
}

template<typename T>
void BinaryTree<T>::CreateBinTree(TreeNode<T>*& BT, T* table)
{
	stack<TreeNode<T>*> stk;
	BT = NULL;
	TreeNode<T>* p, * t;
	int k;
	T* d = table;
	char ch;
	while ((ch = *d) != '\0') {
		switch (ch)
		{
		case '(':
			stk.push(p);
			k = 1;
			break;

		case ')':
			stk.pop();
			break;

		case ',':
			k = 2;
			break;

		default:
			p = new TreeNode<T>(ch);
			if (BT == NULL)
				BT = p;

			else if (k == 1) {
				t = stk.top();
				t->left = p;
			}
			else {
				t = stk.top();
				t->right = p;
			}
		}
		++d;
	}
}



template <typename T>
void BinaryTree<T>::CreateBinTreePreOrder(TreeNode<T>*& cur) {
	T item;
	if (cin >> item) {
		if (item != RefValue) {
			cur = new TreeNode<T>(item);
			if (cur == NULL) {
				cout << "error" << endl;
				exit(1);
			}
			CreateBinTreePreOrder(cur->left);
			CreateBinTreePreOrder(cur->right);
		}
		else {
			cur = NULL;
		}
	}
}

template<typename T>
void BinaryTree<T>::CreateBinTreePreOrder(TreeNode<T>*& cur, T*& table)
{
	if (*table != RefValue) {
		cur = new TreeNode<T>(*table);
		table ++;
		CreateBinTreePreOrder(cur->left, table);
		CreateBinTreePreOrder(cur->right, table);
	}
	else {
		cur = NULL;
		table = table++;
	}
}


template <typename T>
void BinaryTree<T>::CreateBinTreeByPre_In(TreeNode<T>*& cur, const T* pre, const T* in, int n) {
	if (n == 0) {
		cur = NULL;
		return;
	}
	int k = 0;
	while (pre[0] != in[k])
		k++;
	cur = new TreeNode<T>(in[k]);
	CreateBinTreeByPre_In(cur->left, pre+1, in, k);
	CreateBinTreeByPre_In(cur->right, pre+k+1, in+k+1, n-k-1);
}

template <typename T>
void BinaryTree<T>::CreateBinTreeByPos_In(TreeNode<T>*& cur, const T* pos, const T* in, int n) {
	if (n == 0) {
		cur = NULL;
		return;
	}
	cur = new TreeNode<T>(pos[n - 1]);
	int k = 0;
	const T* p = in;
	while (in[k] != pos[n - 1])
		k++;
	CreateBinTreeByPos_In(cur->left, pos, in, k);
	CreateBinTreeByPos_In(cur->right, pos + k, in + k + 1, n - k - 1);
}

template<typename T>
void BinaryTree<T>::CreateBinTreeLevelOrder(TreeNode<T>*& root)
{
	queue<TreeNode<T>*> queue;
	T ch;
	cin >> ch;
	root = new TreeNode<T>(ch);
	queue.push(root);
	cin >> ch;
	while (ch != RefValue) {
		TreeNode<T>* p = queue.front();
		queue.pop();
		p->left = new TreeNode<T>(ch);
		queue.push(p->left);
		cin >> ch;
		if (ch == RefValue)
			break;
		p->right = new TreeNode<T>(ch);
		queue.push(p->right);
		cin >> ch;
	}
}

template<typename T>
void BinaryTree<T>::CreateBinTreeLevelOrder(TreeNode<T>*& root, T* table, int n)
{
	queue<TreeNode<T>*> queue;
	T *ch = table;
	int temp = 0;
	root = new TreeNode<T>(*ch);
	queue.push(root);
	ch++, temp++;
	while (temp < n) {
		TreeNode<T>* p = queue.front();
		queue.pop();
		if (*ch != -1)
			p->left = new TreeNode<T>(*ch), queue.push(p->left);				
		ch++, temp++;
		if (temp >= n)
			break;
		if (*ch != -1)
			p->right = new TreeNode<T>(*ch), queue.push(p->right);
		ch++, temp++;
	}
}


template<typename T>
void BinaryTree<T>::PreOrder(TreeNode<T>* cur)
{
	if (cur != NULL) {
		cout << cur->val << " ";
		PreOrder(cur->left);
		PreOrder(cur->right);
	}
}

template<typename T>
void BinaryTree<T>::InOrder(TreeNode<T>* cur)
{
	if (cur != NULL) {
		InOrder(cur->left);
		cout << cur->val << " ";
		InOrder(cur->right);
	}
}

template<typename T>
void BinaryTree<T>::PosOrder(TreeNode<T>* cur)
{
	if (cur != NULL) {
		PosOrder(cur->left);
		PosOrder(cur->right);
		cout << cur->val << " ";
	}
}

template<typename T>
void BinaryTree<T>::PreOrderNorec(TreeNode<T>* cur)
{
	stack<TreeNode<T>*> stk;
	TreeNode<T>* p = cur;
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			cout << p->val << " ";
			stk.push(p);
			p = p->left;
		}
		if (!stk.empty()) {
			p = stk.top();
			stk.pop();
			p = p->right;
		}
	};
}

template<typename T>
void BinaryTree<T>::InOrderNorec(TreeNode<T>* cur)
{
	stack<TreeNode<T>*> stk;
	TreeNode<T>* p = cur;
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			stk.push(p);
			p = p->left;
		}
		if (!stk.empty()) {
			p = stk.top();
			stk.pop();
			cout << p->val << " ";
			p = p->right; 
		}
	} ;
}

template<typename T>
void BinaryTree<T>::PosOrderNorec(TreeNode<T>* cur)
{
	stack<TreeNode<T>*> stk;
	TreeNode<T>* p = cur, *r = NULL;
	while (p != NULL || !stk.empty()) {
		if (p != NULL) {
			stk.push(p);
			p = p->left;
		}
		else {
			p = stk.top();
			if (p->right != NULL && p->right != r)
				p = p->right;
			else {
				stk.pop();
				cout << p->val << " ";
				r = p;
				p = NULL;
			}
		}
	}
	
}

template<typename T>
void BinaryTree<T>::PreOrderAndEnd(TreeNode<T>* cur)
{
	if (cur != NULL) {
		cout << cur->val << ", ";
		PreOrderAndEnd(cur->left);
		PreOrderAndEnd(cur->right);
	}
	else
		cout << RefValue << ", ";
}

template<typename T>
void BinaryTree<T>::PreOrderNorec2(TreeNode<T>* cur)
{
	stack<TreeNode<T>*> stk;
	TreeNode<T>* t;
	stk.push(cur);
	while (!stk.empty()) {
		t = stk.top();
		stk.pop();
		cout << t->val << " ";
		if (t->right != NULL)
			stk.push(t->right);
		if (t->left != NULL)
			stk.push(t->left);
	}
}

template<typename T>
void BinaryTree<T>::LevelOrder(TreeNode<T>* cur)
{
	queue<TreeNode<T>*> queue;
	queue.push(cur);
	TreeNode<T>* p;
	while (!queue.empty()) {
		p = queue.front();
		queue.pop();
		cout << p->val << " ";
		if (p->left != NULL)
			queue.push(p->left);
		if (p->right != NULL)
			queue.push(p->right);
	}
}

template<typename T>
int BinaryTree<T>::Size(TreeNode<T>* cur)
{
	if (cur == NULL)
		return 0;
	return 1 + Size(cur->left) + Size(cur->right);
}

template<typename T>
int BinaryTree<T>::Height(TreeNode<T>* cur)
{
	if (cur == NULL)
		return 0;
	int left_height = Height(cur->left);
	int right_height = Height(cur->right);
	return max(left_height + 1, right_height + 1);
}

template<typename T>
int BinaryTree<T>::NodeTilt(TreeNode<T>* cur)
{
	return abs(SunNode(cur->right) - SunNode(cur->left));
}

template<typename T>
int BinaryTree<T>::SunNode(TreeNode<T>* cur)
{
	if (cur == NULL)
		return 0;
	return cur->val + SunNode(cur->left) + SunNode(cur->right);
}

template<typename T>
int BinaryTree<T>::OrderFindTilt(TreeNode<T>* cur)
{
	stack<TreeNode<T>*> stk;
	TreeNode<T>* p = cur;
	int result = 0;
	while (p != NULL || !stk.empty()) {
		while (p != NULL) {
			result += NodeTilt(p);
			stk.push(p);
			p = p->left;
		}
		if (!stk.empty()) {
			p = stk.top();
			stk.pop();
			p = p->right;
		}
	}
	return result;
}

template<typename T>
int BinaryTree<T>::OrderRecTilt(TreeNode<T>* cur, int& result)
{
	if (cur == NULL)
		return 0;
	int sumleft = OrderRecTilt(cur->left, result);
	int sumright = OrderRecTilt(cur->right, result);
	result += abs(sumleft - sumright);
	return sumleft + sumright + cur->val;

}

template<typename T>
void BinaryTree<T>::PrintBinTree(TreeNode<T>* cur)
{
	if (cur != NULL) {
		cout << cur->val;
		if (cur->left != NULL || cur->right != NULL) {
			cout << '(';
			if (cur->left != NULL)
				PrintBinTree(cur->left);
			cout << ',';
			if (cur->right != NULL)
				PrintBinTree(cur->right);
			cout << ')';
		}
	}
}

template<typename T>
void BinaryTree<T>::PrintBinTreeNoRec(TreeNode<T>* cur)
{
	stack<TreeNode<T>*> stk;
	TreeNode<T>* p = cur;
	do {
		if (p != NULL) 
			cout << p->val;
		if (p != NULL && (p->left != NULL || p->right != NULL)) {
			cout << '(';
			stk.push(NULL);
			if (p->right != NULL)
				stk.push(p->right);
			p = p->left;
		}
		else
		{
			TreeNode<T>* tmp = stk.top();
			stk.pop();
			if (tmp == NULL)
				cout << ")";
			else 
				cout << ",";
			p = tmp;
		}
	} while (!stk.empty());
}

template<typename T>
TreeNode<T>* BinaryTree<T>::Parent(TreeNode<T>* subtree, TreeNode<T>* cur)
{
	if (subtree == NULL)
		return NULL;
	if (subtree->left == cur || subtree->right == cur)
		return subtree;
	TreeNode<T>* p;
	if ((p = Parent(subtree->left, cur)) != NULL)
		return p;
	else
		return Parent(subtree->right, cur);
}


template<typename T>
void BinaryTree<T>::Destroy(TreeNode<T>*& subtree)
{
	if (subtree != NULL) {
		Destroy(subtree->left);
		Destroy(subtree->right);
		delete subtree;
		subtree = NULL;
	}
}

template<typename T>
bool BinaryTree<T>::Equal(TreeNode<T>* a, TreeNode<T>* b)
{
	if (a == NULL && b == NULL)
		return true;
	if (a != NULL && b != NULL && a->val == b->val && Equal(a->left, b->left) &&
		Equal(a->right, b->right))
		return true;
	return false;
}














