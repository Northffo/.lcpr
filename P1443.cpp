#include <bits/stdc++.h>

using namespace std;
const int N = 405;
typedef pair<int, int> PII;

bool st[N][N];
int res[N][N];
int n, m, x, y;
int cnt;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

// void bfs() {
//     queue<PII> q;

//     q.push(PII(x, y));
//     int step = 0;
//     while(q.size()) {
//         int len = q.size();

//         for(int i = 0; i < len; i++) {
//             PII idx = q.front();
//             q.pop();
//             res[idx.first][idx.second] = step;
//             st[idx.first][idx.second] = 1;
//             for(int i = 0; i < 8; i++) {
//                 int nx = idx.first + dx[i];
//                 int ny = idx.second + dy[i];
//                 if(nx > 0 && nx <= n && ny > 0 && ny <= m && !st[nx][ny]) {
//                     q.push(PII(nx, ny));
//                 }
//             }
//         }
//         step ++;
//     }

// }

int main()
{
    cin >> n >> m >> x >> y;

    memset(res, -1, sizeof(res));
    queue<PII> q;

    q.push(PII(x, y));
    res[x][y] = 0;
    st[x][y] = 1;
    int step = 0;
    while(q.size()) {
        int len = q.size();

        // for(int i = 0; i < len; i++) {
            PII idx = q.front();
            q.pop();
            // res[idx.first][idx.second] = step;
            // st[idx.first][idx.second] = 1;
            for(int i = 0; i < 8; i++) {
                int nx = idx.first + dx[i];
                int ny = idx.second + dy[i];
                if(nx > 0 && nx <= n && ny > 0 && ny <= m && !st[nx][ny]) {
                    q.push(PII(nx, ny));
                    res[nx][ny] = res[idx.first][idx.second] + 1;
                    st[nx][ny] = 1;
                }
            }
        // }
        step ++;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << res[i][j] << " ";
        }
        puts("");
    }


    return 0;
}
