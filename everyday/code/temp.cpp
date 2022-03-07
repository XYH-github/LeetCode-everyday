#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;
        for (int i = 0; i < len; ++i) {
            ret.emplace_back(nums[i]);
            while (ret.size() > 1) {
                int temp = getMaxComDivi(ret.back(), ret[ret.size() - 2]);
                if (temp > 1) {
                    temp = ret.back() / temp * ret[ret.size() - 2];
                    ret.pop_back();
                    ret.back() = temp;
                }else
                    break;
            }
        }
        return ret;
    }

    int getMaxComDivi(int num_a, int num_b) {
        while (num_a != num_b)
            if (num_a > num_b)
                num_a -= num_b;
            else
                num_b -= num_a;
        return num_a;
    }
};