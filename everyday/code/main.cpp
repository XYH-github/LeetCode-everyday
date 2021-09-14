#include "Print.h"

//#include "21_8_28-sum_for_onedimenarray.cpp"
//#include "21_8_29-sum_for_oddlength_array.cpp"
//#include "21_9_2-linedlist_get_reciprocal.cpp"
#include "21_9_5-rank7_gene_rank10.cpp"

int main(void) {
	/*vector<int> nums = { 3, 1, 2, 10, 1 };
	Solution temp;
	nums = temp.runningSum(nums);
	Print<int>::PrintOneDemionVector(nums);*/

	/*vector<int> nums = { 1, 4, 2, 5, 3 };
	Solution temp;
	int result = temp.sumOddLengthSubarrays(nums);
	cout << result << endl;*/

	/*vector<int> nums = { 1, 2, 3, 4, 5 };
	LinkList *list_ptr = new LinkList();
	list_ptr->CreateLinkList(nums.size(), nums);
	Solution temp;
	ListNode *result = temp.getKthFromEnd(list_ptr->GetHead()->next, 2);
	LinkList::PrintLinkList(result);*/

	Solution temp;
	int result = temp.rand10();
	cout << result << endl;
}


