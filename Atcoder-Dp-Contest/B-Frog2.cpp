// B.cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1000000000

ll call_func(ll ind, vector<ll> &arr, vector<ll> &dp, ll k) {
    if(ind == arr.size() - 1)
        return 0;
    if(dp[ind] != -1)
        return dp[ind];

    ll ans = inf;
    for(ll j = 1; j <= k; j++) 
        if(ind + j < arr.size())
            ans = min(ans, abs(arr[ind] - arr[ind + j]) + call_func(ind + j, arr, dp, k));
    return dp[ind] = ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++)
        cin >> arr[i];

    vector<ll> dp(n + 1, -1);

    cout << call_func(0, arr, dp, k) << endl;

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
