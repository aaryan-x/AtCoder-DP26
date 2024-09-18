#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;
void solve() {
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();
    
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for (int i=1; i< n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Backtracking to find the LCS string
    string ans = "";
    int i = n, j = m;
    while (i>0 && j>0) {
        if (s[i-1] == t[j-1]) {
            ans.push_back(s[i-1]);
            i--;
            j--;
        } else if (dp[i-1][j] == dp[i][j]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
