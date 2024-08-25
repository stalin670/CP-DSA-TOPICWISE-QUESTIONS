// A.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000

void solve() {
    ll n;
    cin >> n;
    vector<ll> height(n);
    for(auto &it : height)
        cin >> it;

    vector<ll> dp(n + 1, inf);
    dp[0] = 0;
    dp[1] = abs(height[0] - height[1]);
    for(ll i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]), dp[i - 2] + abs(height[i] - height[i - 2]));        
    }
    cout << dp[n - 1] << endl;
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
