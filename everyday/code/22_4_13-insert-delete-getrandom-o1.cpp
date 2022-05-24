/*

实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

 

示例：

输入
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
输出
[null, true, false, true, 2, true, false, 2]

解释
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。

链接：https://leetcode.cn/problems/insert-delete-getrandom-o1

    RandomizedSet temp;
    cout << temp.insert(1) << endl;
    cout << temp.remove(2) << endl;
    cout << temp.insert(2) << endl;
    cout << temp.getRandom() << endl;
    cout << temp.remove(1) << endl;
    cout << temp.insert(2) << endl;
    cout << temp.getRandom() << endl;

*/

#include <time.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//class RandomizedSet {
//public:
//    RandomizedSet() {
//        srand((unsigned)time(NULL));
//        vec.clear();
//        pos_map.clear();
//        len = 0;
//    }
//
//    bool insert(int val) {
//        if (pos_map.count(val)) {
//            return false;
//        }
//        vec.emplace_back(val);
//        pos_map[val] = len;
//        len++;
//        return true;
//    }
//
//    bool remove(int val) {
//        if (!pos_map.count(val))
//            return false;
//        int pos = pos_map[val];
//        vec[pos] = vec.back();
//        pos_map[vec.back()] = pos;
//        vec.pop_back();
//        pos_map.erase(val);
//        len--;
//        return true;
//    }
//
//    int getRandom() {
//        return vec[rand() % len];
//    }
//
//private:
//    int len;
//    vector<int> vec;
//    unordered_map<int, int> pos_map;
//};


class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
        len = 0;
        set.clear();
    }

    bool insert(int val) {
        if (set.count(val))
            return false;
        set.emplace(val);
        len++;
        return true;
    }

    bool remove(int val) {
        if (!set.count(val))
            return false;
        set.erase(val);
        len--;
        return true;
    }

    int getRandom() {
        int rand_index = rand() % len;
        auto iter = set.begin();
        advance(iter, rand_index);
        return *iter;
    }

private:
    int len;
    unordered_set<int> set;
};