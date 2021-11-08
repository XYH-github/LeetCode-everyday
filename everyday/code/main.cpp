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

int main(void) {
	/*string input = "[[2, 2], [3, 3]];";
	Print<string>::VectorFormTrans(input);
	cout << input << endl;*/

	vector<int> arr = { 1,5,7,8,5,3,4,2,1 };
	int difference = -2;
	Solution temp;
	int result = temp.longestSubsequence(arr, difference);
	cout << result << endl;
}


