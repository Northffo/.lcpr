#include <bits/stdc++.h>

using namespace std;

const int N = 25;

long long cnt;
int m, n;
bool st[N][N];

void dfs(int i, int j) {
    if(i < 0 || i > n || j < 0 || j > m || st[i][j]) return;
    if(i == n && j == m) {
        cnt++;
        return;
    }

    st[i][j] = 1;

    dfs(i + 1, j);
    dfs(i, j + 1);

    st[i][j] = 0;
}

int main()
{
    cnt = 0;
    cin >> n >> m;
    int i, j;
    cin >> i >> j;
    st[i][j] = 1;
    st[i + 1][j + 2] = 1;
    st[i + 2][j + 1] = 1;
    st[i + 2][j - 1] = 1;
    st[i + 1][j - 2] = 1;
    st[i - 1][j - 2] = 1;
    st[i - 2][j - 1] = 1;
    st[i - 2][j + 1] = 1;
    st[i - 1][j + 2] = 1;
    dfs(0, 0);
    cout << cnt << endl;
    return 0;
}
