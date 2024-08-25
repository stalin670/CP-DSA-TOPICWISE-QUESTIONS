// F.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000
#define mod 1000000007

// Memoization/Recursive DP

ll helper_function(ll i, ll j, ll n, ll m, string s, string t, vector<vector<ll>>& dp) {
    if (i > n || j > m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == t[j - 1])
        return dp[i][j] = 1 + helper_function(i + 1, j + 1, n, m, s, t, dp);

    return dp[i][j] = max(helper_function(i + 1, j, n, m, s, t, dp), helper_function(i, j + 1, n, m, s, t, dp));
}

void solve() {
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size();

    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1, 0));

    // Iterative DP

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
    }

    // ll len = helper_function(1, 1, n, m, s, t, dp);

    string ans = "";
    ll i = n, j = m;
    while (i > 0 and j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] >= dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll tc;
    tc = 1;
    // cin >> tc;
    for (ll i = 1; i <= tc; i++) {
        // cout << "TEST CASE : " << i << " : ";
        solve();
    }

    return 0;
}

