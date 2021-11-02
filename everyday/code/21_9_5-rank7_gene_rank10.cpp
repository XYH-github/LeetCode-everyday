#include <iostream>
#include <random>
#include <time.h>
/*
已有方法 rand7 可生成 1 到 7 范围内的均匀随机整数，试写一个方法 rand10 生成 1 到 10 范围内的均匀随机整数。

不要使用系统的 Math.random() 方法。


Solution temp;
    int result = temp.rand10();
    cout << result << endl;

*/



class Solution {
public:
    
    std::default_random_engine random{ time(NULL) };
    std::uniform_int_distribution<int> dis1{ 1, 7 };

    /*int rand10() {
        int a = rand7();
        int b = rand7();
        if (a > 4 && b < 4)
            return rand10();
        else
            return (a + b) % 10 + 1;
    }*/

    /*int rand10() {
        int a, b;
        while ((a = rand7()) == 7);
        while ((b = rand7()) > 5);
        return (a & 1 ? 0 : 5) + b;
    }*/

    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    } 



    int rand7() {
        return dis1(random);
    }
};