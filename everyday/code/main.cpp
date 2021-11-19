#include "Print.h"


//#include "21_8_28-sum_for_onedimenarray.cpp"
//#include "21_8_29-sum_for_oddlength_array.cpp"
//#include "21_9_2-linedlist_get_reciprocal.cpp"
//#include "21_9_5-rank7_gene_rank10.cpp"
//#include "21_9_30-area_for_retang.cpp"
//#include "21_8_30-selete_num_by_weight.cpp"
//#include "21_10_2-dec2tohex.cpp"
//#include "21_10_3-fraction2todec.cpp"
//#include "21_10_10-sumfor_1234.cpp"
//#include "21_10_9-dataflow_to_array.cpp"
//#include "21_10_8-get_repeat_form_dna.cpp"
//#include "21_10_11-num_to_english_format.cpp"
//#include "21_10_30-single-number.cpp"
//#include "21_11_3-rainwater-connection.cpp"
//#include "21_11_8-game-for-guest-digital.cpp"
//#include "21_11_7-sum-for-range.cpp"
//#include "21_11_6-missing-num.cpp"
//#include "21_11_5-longest-arithmetic-sunsequence.cpp"
//#include "21_11_4-vaild-perfect-square.cpp"
//#include "21_11_17-maximum-product-of-word-lengths.cpp"
//#include "21_11_16-perfect-rectangle.cpp"

#include "template.cpp"
#include "BinaryTree.h"

int main(void) {
	/*string input = "[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]];";
	Print<string>::VectorFormTrans(input);
	cout << input << endl;*/

	/*vector<vector<int>> num = { {1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4} };
	Solution temp;
	bool result = temp.isRectangleCover(num);
	cout << result << endl;*/
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

	string table2 = "1 2 4 # # 5 8 # # 9 # # 3 6 # # 7 # #";
	BinaryTree<char> bintree2('#');
	bintree2.CreateBinTreePreOrder((char*)table2.c_str());
	
	bintree2.PreOrder();
	cout << endl;
	bintree2.InOrder();
	cout << endl;
	bintree2.PosOrder();
	cout << endl;


}


