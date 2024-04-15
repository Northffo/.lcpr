#include <bits/stdc++.h>

using namespace std;
const int N = 23;

int A[N], B[N], C[N], D[N];
int s1, s2, s3, s4;
int res;
int no[N];

int dfs(int* t, int len) {
    if(len == 1) return t[0];
    if(len == 2) return max(t[0], t[1]);

    int cnt = 0;
    no[0] = t[0];
    no[1] = t[1];
    for(int i = 2; i < len; i++) {
        no[i] = abs(no[i - 1] - no[i - 2]);
        res += min(no[i - 1], no[i - 2]);
        no[i - 1] = t[i];
        if(i == len - 1) res += max(no[i], no[i - 1]);
    }
    return cnt;
}


int main()
{
    res = 0;
    cin >> s1 >> s2 >> s3 >> s4;

    for(int i = 0; i < s1; i++) cin >> A[i];
    for(int i = 0; i < s2; i++) cin >> B[i];
    for(int i = 0; i < s3; i++) cin >> C[i];
    for(int i = 0; i < s4; i++) cin >> D[i];

    res += dfs(A, s1);
    res += dfs(B, s2);
    res += dfs(C, s3);
    res += dfs(D, s4);

    cout << res << endl;

    return 0;
}
