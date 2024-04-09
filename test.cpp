#include <bits/stdc++.h>

using namespace std;
const int N = 15;

bool row[15], col[15], dig[30], udig[30];
int n;
int cnt;
int v[15];

void dfs(int u) {
   if(u == n) {
      cnt++;
      if(cnt <= 3) {
         for(int i = 1; i <= n; i++) cout << v[i] << " "; 
         puts("");
      }
      return;
   }

   for(int i = 1; i <= n; i++) {
      if(!col[i] && !dig[u + i] && !udig[u - i + n]) {
         col[i] = 1;
         dig[u + i] = 1;
         udig[u - i + n] = 1; 
         v[u] = i;
         dfs(u + 1);
         col[i] = 0;
         dig[u + i] = 0;
         udig[u - i + n] = 0; 
      }
   }
}



int main()
{
   cin >> n;

   memset(row, 0, sizeof(row));
   memset(dig, 0, sizeof(dig));
   memset(udig, 0, sizeof(udig));

   cnt = 0;
   dfs(1);
   cout << cnt;

   return 0;
}
