/*
���� ��ά ƽ�������� ��ֱ�߹��ɵ� ���Σ�������㲢�����������θ��ǵ��������

ÿ���������� ���� ����� ���� ���������ʾ��

��һ�������������¶��� (ax1, ay1) �����϶��� (ax2, ay2) ���塣
�ڶ��������������¶��� (bx1, by1) �����϶��� (bx2, by2) ����

���룺ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
�����45
ʾ�� 2��

���룺ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
�����16

int ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2;
    Solution temp;
    int result = temp.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    cout << result << endl;


*/
#include <algorithm>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        if (ax2 > bx1 && bx2 > ax1 && ay1 < by2 && ay2 > by1)
            return area - abs(min(ax2, bx2) - max(bx1, ax1)) * abs(min(ay2, by2) - max(ay1, by1));
        else
            return area;
    }   
};