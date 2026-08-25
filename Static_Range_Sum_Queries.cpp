#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
  int n, q; cin >> n >> q;
  ll arr[n], prefixSum[n + 1];
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }

  prefixSum[0] = 0;
  for(int i = 1; i<=n; i++){
    prefixSum[i] = prefixSum[i-1] + arr[i-1];
  }

  for(int t = 0; t <q; t++){
    int l,h; cin >> l >> h;
    cout << prefixSum[h] - prefixSum[l-1] << endl;
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
