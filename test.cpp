#include <bits/stdc++.h>

using namespace std;

int main()
{
   queue<int> hong, ming;
   int h[6] = {3, 1, 3, 5, 6, 4};
   int m[6] = {2, 4, 1, 2, 5, 6};

   // 初始化两个队列
   for(int i : h) hong.push(i);         
   for(int i : m) ming.push(i);

   bool card[15];           // 代表有哪些牌已经出过
   bool f = 1;                // f = true代表小明出牌

   stack<int> st;             // 代表桌面上的牌

   st.push(ming.front());     // 小明先出牌
   card[st.top()] = 1;        // 改变卡牌状态
   ming.pop();                // 出队
   

   while(st.size()) {
      if(!f) {             // 小红的回合
         int cd = hong.front();     // 记录要出的牌
         if(card[cd]) {             // 如果这张牌出过, 那么栈上存在这张牌，
            while(st.top() != cd) {    // 把这两张相同牌之间的牌重新加到队列
               hong.push(st.top());
               card[st.top()] = 0;
               st.pop();
            }
            hong.push(st.top());
            card[st.top()] = 0;
            st.pop();
         } else {          // 如果没出过
            st.push(cd);
            card[cd] = 1;
            hong.pop();
         }
         f = !f;           // 改变回合
      } else {
         int cd = ming.front();     // 记录要出的牌
         if(card[cd]) {             // 如果这张牌出过, 那么栈上存在这张牌，
            while(st.top() != cd) {    // 把这两张相同牌之间的牌重新加到队列
               ming.push(st.top());
               card[st.top()] = 0;
               st.pop();
            }
            ming.push(st.top());
            card[st.top()] = 0;
            st.pop();
         } else {          // 如果没出过
            st.push(cd);
            card[cd] = 1;
            ming.pop();
         }
         f = !f;           // 改变回合    
      }
   }
   
   // 如果是小明的回合， 说明最后一张牌是小红收走的
   if(f) cout << "hong win" << endl;
   else cout << "ming win" << endl;

   return 0;
}
