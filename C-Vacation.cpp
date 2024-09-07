#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> activity(n, vector<ll>(3, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 3; j++) {
            cin >> activity[i][j];
        }
    }

    vector<ll> prev(3, 0);
  
    prev[0] = activity[0][0];
    prev[1] = activity[0][1];
    prev[2] = activity[0][2];
  
    for (int day = 1; day < n; day++) {
        vector<ll> curr(3, 0);

        curr[0] = activity[day][0] + max(prev[1], prev[2]);  // Task 0 today
        curr[1] = activity[day][1] + max(prev[0], prev[2]);  // Task 1 today
        curr[2] = activity[day][2] + max(prev[0], prev[1]);  // Task 2 today

        prev = curr;
    }
  
    ll res = max({prev[0], prev[1], prev[2]});
    cout << res << endl;
}

int main() {
    solve();
    return 0;
}
