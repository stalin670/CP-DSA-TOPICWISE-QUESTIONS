// E.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000
#define mod 1000000007

ll helper_function(ll ind, ll max_value, vector<ll>& wt, vector<ll>& val, vector<vector<ll>>& dp) {
    if (max_value == 0)
        return 0;
    if (ind < 0)
        return 1e12;

    if (dp[ind][max_value] != -1)
        return dp[ind][max_value];

    ll min_wt = helper_function(ind - 1, max_value, wt, val, dp);
    if (max_value - val[ind] >= 0) {
        min_wt = min(min_wt, helper_function(ind - 1, max_value - val[ind], wt, val, dp) + wt[ind]);
    }

    return dp[ind][max_value] = min_wt;
}

void solve() {
    ll n, w;
    cin >> n >> w;

    vector<ll> wt(n), val(n);
    for (ll i = 0; i < n; i++)
        cin >> wt[i] >> val[i];

    ll max_value = 1e5;

    vector<vector<ll>> dp(n + 1, vector<ll> (max_value + 10, -1));

    for (ll value = max_value; value >= 0; value--) {
        ll max_wt = helper_function(n - 1, value, wt, val, dp);
        if (max_wt <= w) {
            cout << value << endl;
            return;
        }
    }
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

