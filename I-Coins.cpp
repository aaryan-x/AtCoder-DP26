#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

void solve() {
    ll n;
    cin >> n;
    
    vector<double> p(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
  
    dp[0][0] = 1.0;  
    
    // DP computation
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += (1 - p[i-1]) * dp[i-1][j];
            // If we get a head in the current toss (only if j > 0)
            if (j > 0) {
                dp[i][j] += p[i-1] * dp[i-1][j-1];
            }
        }
    }
    
    // We need to count the probability where heads are strictly greater than half of the total coins
    double ans = 0.0;
    for (int i = (n / 2) + 1; i <= n; i++) {
        ans += dp[n][i];
    }
    
    cout << setprecision(9) << fixed << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
