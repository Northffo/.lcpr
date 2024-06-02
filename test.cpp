#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int>& a, pair<char,int>& b) {
   return a.second > b.second;   // 按照second降序
}

void sort_unordered_map() {
   unordered_map<char, int> mp;

   int idx = 1;
   for(char c = 'a'; c <= 'z'; c++) {
      mp[c] = idx++;
   }

   // 利用vector构造函数快速转换
   vector<pair<char, int>> sorted_mp(mp.begin(), mp.end());
   
   sort(sorted_mp.begin(), sorted_mp.end(), cmp);

   // 此时可以选择直接使用排序后的vector或者再转换为哈希表
   for(auto [a, b] : sorted_mp) {
      cout << a << "" << b << endl;
   }
}



int main() {
   sort_unordered_map();

   return 0;
}