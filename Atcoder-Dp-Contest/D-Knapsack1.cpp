// D.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000

ll helper_function(ll ind, ll max_wt, ll n, vector<pair<ll, ll>>& wt_val, vector<vector<ll>>& dp) {
    if(ind == n - 1) {
        if(wt_val[ind].first <= max_wt)
            return wt_val[ind].second;
        return 0;
    }

    if(dp[ind][max_wt] != -1)
        return dp[ind][max_wt];

    ll take = 0, not_take;
    if(wt_val[ind].first <= max_wt) {
        take = wt_val[ind].second + helper_function(ind + 1, max_wt - wt_val[ind].first, n, wt_val, dp);
    }
    not_take = 0 + helper_function(ind + 1, max_wt, n, wt_val, dp);

    return dp[ind][max_wt] = max(take, not_take);
}

void solve() {
	ll n, W;
    cin >> n >> W;
    vector<pair<ll, ll>> wt_val(n);
    for(auto &it : wt_val)
        cin >> it.first >> it.second;

    vector<vector<ll>> dp(n + 1, vector<ll> (W + 1, -1));

    cout << helper_function(0, W, n, wt_val, dp);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int tc;
    tc = 1;
    // cin >> tc;
    for(ll i = 1; i <= tc; i++) {
        // cout << "TEST CASE : " << i << " : ";
        solve();
    }

    return 0;
}
