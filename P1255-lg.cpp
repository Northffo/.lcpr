#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
string dp[N];
int n;

string addBigNumber(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    string res = "";
    int carry = 0;

    while(i >= 0 || j >= 0 || carry) {
        if(i >= 0) carry += a[i--] - '0';
        if(j >= 0) carry += b[j--] - '0';
        res.push_back((carry % 10) + '0');
        carry /= 10;
    }

    reverse(res.begin(), res.end());

    return res;
}


int main()
{
    cin >> n;
    dp[1] = "1";
    dp[2] = "2";

    for(int i = 3; i <= n; i++) dp[i] = addBigNumber(dp[i - 1], dp[i - 2]);

    cout << dp[n];


    return 0;
}
