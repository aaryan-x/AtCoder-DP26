#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n);
    vector<ll> value(n);
    for (ll i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    
    vector<vector<ll>> dp(n, vector<ll>(w + 1, 0));
    for (int i = 0; i <= w; i++) {
        if (weight[0] <= i) {
            dp[0][i] = value[0]; // Take an element only if its weight is lesser than max possible weight
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= w; j++){
            ll notTaken = dp[i-1][j];
          
            ll taken = 0;
            if (j >= weight[i]) {
                taken = value[i] + dp[i-1][j - weight[i]];
            }  
            dp[i][j] = max(notTaken, taken);
        }
    }
    
    cout << dp[n-1][w] << endl;
}

int main(){
    solve();
    return 0;
}
