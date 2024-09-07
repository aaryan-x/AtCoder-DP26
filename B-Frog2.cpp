#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<ll> dp(n, LLONG_MAX);
    dp[0] = 0;

    for (ll i = 1; i < n; i++) {
      
      for(int steps = 1; steps <= k && i-steps>=0; steps++){
        ll jump = dp[i-steps] + abs(h[i]-h[i-steps]);
        dp[i]= min(dp[i], jump);
      }
    }

    cout << dp[n - 1] << endl;
}

int main() {
    solve();
    return 0;
}

