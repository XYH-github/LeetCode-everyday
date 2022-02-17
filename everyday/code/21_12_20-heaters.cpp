/*

冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

在加热器的加热半径范围内的每个房屋都可以获得供暖。

现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置，请你找出并返回可以覆盖所有房屋的最小加热半径。

说明：所有供暖器都遵循你的半径标准，加热的半径也一样。

 

示例 1:

输入: houses = [1,2,3], heaters = [2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: houses = [1,2,3,4], heaters = [1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
示例 3：

输入：houses = [1,5], heaters = [2]
输出：3
 

提示：

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109

链接：https://leetcode-cn.com/problems/heaters

vector<int> houses = { 282475249, 622650073, 984943658, 144108930, 470211272, 101027544, 457850878, 458777923 },
    heaters = { 823564440, 115438165, 784484492, 74243042, 114807987, 137522503, 441282327, 16531729, 823378840, 143542612 };
    Solution temp;
    int result = temp.findRadius(houses, heaters);
    cout << result << endl;

*/
#include <vector>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    int findRadius(vector<int>& houses, vector<int>& heaters) {
//        sort(houses.begin(), houses.end());
//        sort(heaters.begin(), heaters.end());
//        int length = houses.size();
//        int left = 0;
//        int right = max(houses[length - 1], heaters[heaters.size() - 1]) - min(houses[0], heaters[0]);
//        int mid = 0;
//        bool flag = 0;
//        while (right > left) {
//            mid = (left + right) / 2;
//            int houses_index = 0;
//            int heaters_index = 0;
//            while (heaters_index < heaters.size() && houses_index < length) {
//                if (houses[houses_index] >= heaters[heaters_index] - mid) {
//                    while (houses_index < length) {
//                        if (houses[houses_index] > heaters[heaters_index] + mid)
//                            break;
//                        else
//                            houses_index++;
//                    }
//                } 
//                else
//                    break;
//                heaters_index++;
//            }
//            if (houses_index == length)
//                right = mid;
//            else
//                left = mid + 1;
//        }
//        return left;
//    }
//};

//class Solution {
//public:
//    int findRadius(vector<int>& houses, vector<int>& heaters) {
//        int ans = 0;
//        sort(heaters.begin(), heaters.end());
//        for (int house : houses) {
//            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
//            int i = j - 1;
//            int rightDistance = j >= heaters.size() ? INT_MAX : heaters[j] - house;
//            int leftDistance = i < 0 ? INT_MAX : house - heaters[i];
//            int curDistance = min(leftDistance, rightDistance);
//            ans = max(ans, curDistance);
//        }
//        return ans;
//    }
//};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0, j = 0; i < houses.size(); i++) {//双指针
            int curDistance = abs(houses[i] - heaters[j]);
            while (j < heaters.size() - 1 && abs(houses[i] - heaters[j]) >= abs(houses[i] - heaters[j + 1])) {
                j++;
                curDistance = min(curDistance, abs(houses[i] - heaters[j]));
            }
            ans = max(ans, curDistance);
        }
        return ans;
    }
};


