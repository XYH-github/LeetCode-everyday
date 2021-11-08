#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Print {
public:
	/*static void PrintOneDemionVector(vector<int> nums) {
		cout << "[";
		for (int i = 0; i < nums.size(); ++i)
			cout << " " << nums[i] << ",";
		cout << "]";
	}*/

	static void PrintOneDemionVector(vector<T> nums) {
		cout << "[";
		for (int i = 0; i < nums.size(); ++i) {
			cout << " " << nums[i];
			if (i != nums.size() - 1)
				cout << ",";
		}
		cout << "]";
	}

	static void PrintTwoDemionVector(vector<vector<T>> arr) {
		for (int i = 0; i < arr.size(); ++i) {
			PrintOneDemionVector(arr[i]);
			cout << endl;
		}
	}

	static void PrintVectorForString(vector<T> arr) {
		for (int i = 0; i < arr.size(); ++i) {
			cout << arr[i] << endl;
		}
	}

	static void VectorFormTrans(string& str) {
		for (auto& index : str) {
			if (index == '[')
				index = '{';
			if (index == ']')
				index = '}';
		}
	}
};