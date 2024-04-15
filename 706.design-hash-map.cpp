/*
 * @lc app=leetcode.cn id=706 lang=cpp
 * @lcpr version=30122
 *
 * [706] 设计哈希映射
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyHashMap {
    typedef pair<int, int> PII;
public:
    MyHashMap() :data(base){

    }
    
    void put(int key, int value) {
        int h = hash(key);

        for(auto it : data[h]) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }

        data[h].push_back(PII(key, value));
    }
    
    int get(int key) {
        int h = hash(key);

        for(auto it : data[h]) {
            if(it.first == key) return it.second;
        }

        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);

        if(get(key) == -1) return;
        for(auto it = data[h].begin(); it != data[h].end(); it++) {
            if((*it).first == key) {
                data[h].erase(it);
                return ;
            }
        }
    }

private:
    vector<list<PII>> data;
    const int base = 769;
    const int hash(int val) {return val % base;}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"][[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]\n
// @lcpr case=end

 */

