// C.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000

ll call_func(ll prev_state, ll curr_state, ll n, vector<vector<ll>>& arr, vector<vector<ll>>& dp) {
    if(curr_state == n - 1) {
        ll max_from_last = 0;
        for(ll i = 0; i < 3; i++)
            if(i != prev_state)
                max_from_last = max(max_from_last, arr[curr_state][i]);
        return max_from_last;
    }
    if(dp[curr_state][prev_state] != -1)
        return dp[curr_state][prev_state];

    ll max_points = 0;
    for(ll i = 0; i < 3; i++) {
        if(prev_state != i) {
            max_points = max(max_points, arr[curr_state][i] + 
                call_func(i, curr_state + 1, n, arr, dp));
        }
    }

    return dp[curr_state][prev_state] = max_points;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3));
    for(auto &it : arr)
        cin >> it[0] >> it[1] >> it[2];

    vector<vector<ll>> dp(n, vector<ll>(4, -1));

    cout << call_func(3, 0, n, arr, dp);
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

