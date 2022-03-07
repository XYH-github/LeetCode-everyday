#include "../code/Print.h"

#include "1-find-first-and-last-position-of-element-in-sorted-array.cpp"

int main(void) {
	//string input = "tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5;";
	//Print<string>::VectorFormTrans(input);
	//cout << input << endl;
	
	vector<int> nums = { 5, 7, 7, 8, 8, 10 };
	int target = 8;
	Solution temp;
	vector<int> ret = temp.searchRange(nums, target);
	Print<int>::PrintOneDemionVector(ret);
}