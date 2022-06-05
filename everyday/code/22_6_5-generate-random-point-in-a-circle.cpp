/*

给定圆的半径和圆心的位置，实现函数 randPoint ，在圆中产生均匀随机点。

实现 Solution 类:

Solution(double radius, double x_center, double y_center) 用圆的半径 radius 和圆心的位置 (x_center, y_center) 初始化对象
randPoint() 返回圆内的一个随机点。圆周上的一点被认为在圆内。答案作为数组返回 [x, y] 。
 

示例 1：

输入:
["Solution","randPoint","randPoint","randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
输出: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
解释:
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint ();//返回[-0.02493，-0.38077]
solution.randPoint ();//返回[0.82314,0.38945]
solution.randPoint ();//返回[0.36572,0.17248]
 

提示：

0 < radius <= 108
-107 <= x_center, y_center <= 107
randPoint 最多被调用 3 * 104 次

链接：https://leetcode.cn/problems/generate-random-point-in-a-circle

    double radius = 1.0, x_center = 0.0, y_center = 0.0;
    Solution temp(radius, x_center, y_center);
    Print<double>::PrintOneDemionVector(temp.randPoint());
    Print<double>::PrintOneDemionVector(temp.randPoint());
    Print<double>::PrintOneDemionVector(temp.randPoint());

*/

#define _USE_MATH_DEFINES
#include <vector>
#include <time.h>
#include <math.h>
#include <random>
using namespace std;

//class Solution {
//public:
//    Solution(double radius, double x_center, double y_center) :
//        _radius(radius), _x_center(x_center), _y_center(y_center) {
//        srand((unsigned)time(NULL));
//    }
//
//    vector<double> randPoint() {
//        double rand_len = sqrt((double)(rand()) / ((double)(RAND_MAX / (_radius * _radius))));
//        double angle = -M_PI + (double)(rand()) / ((double)(RAND_MAX / (M_PI * 2)));
//        return { _x_center + rand_len * sin(angle), _y_center + rand_len * cos(angle) };
//    }
//
//private:
//    double _radius;
//    double _x_center;
//    double _y_center;
//};


class Solution {
public:
    Solution(double radius, double x_center, double y_center) : 
        dis(-radius, radius), xc(x_center), yc(y_center), r(radius){}

    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r)
                return { xc + x, yc + y };
        }
    }

private:
    mt19937 gen{ random_device{}() };
    uniform_real_distribution <double> dis;
    double xc, yc, r;
};