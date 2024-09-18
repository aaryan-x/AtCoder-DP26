#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == '#')    dp[i][j] = 0;
            else if (i == 0 && j == 0)    dp[i][j] = 1;  
            else {
                ll up = 0, left = 0;
                if (i > 0) up = dp[i-1][j];    // From the top
                if (j > 0) left = dp[i][j-1];  // From the left
                dp[i][j] = (up + left) % mod;
            }
        }
    }
  
    cout << dp[n-1][m-1];
}

int main() {
    solve();
    return 0;
}
