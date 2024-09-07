#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<ll> dp(n, LLONG_MAX);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);

    for (ll i = 2; i < n; i++) {
        ll oneJump = dp[i - 1] + abs(h[i] - h[i - 1]);
        ll twoJumps = dp[i - 2] + abs(h[i] - h[i - 2]);
        dp[i] = min(oneJump, twoJumps);
    }

    cout << dp[n - 1] << endl;
}

int main() {
    solve();
    return 0;
}
