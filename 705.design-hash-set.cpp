/*
 * @lc app=leetcode.cn id=705 lang=cpp
 * @lcpr version=30122
 *
 * [705] 设计哈希集合
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
class MyHashSet {
public:
    MyHashSet() : data(base){
        
    }
    
    void add(int key) {
        if(contains(key)) return;

        int h = hash(key);
        data[h].push_back(key);        
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = data[h].begin(); it != data[h].end(); it++) {
            if((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int h = hash(key);
        for(auto it : data[h]) {
            if(it == key) return true;
        }

        return false;
    }

private: 
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"][[], [1], [2], [1], [3], [2], [2], [2], [2]]\n
// @lcpr case=end

 */

