#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

void build(ll arr[], ll tree[], int node, int node_low, int node_high){
    if(node_low == node_high){
        tree[node] = arr[node_low];
        return;
    }

    int last_in_left = (node_low + node_high)/2;
    build(arr, tree, node*2, node_low, last_in_left);
    build(arr, tree, node*2+1, last_in_left + 1, node_high);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void update(ll tree[], int node, int node_low, int node_high, int pos, ll value){
    if(node_low == node_high){
        tree[node] = value;
        return;
    }

    int last_in_left = (node_low + node_high)/2;
    if(pos <= last_in_left){
        update(tree, node*2, node_low, last_in_left, pos, value);
    }else{
        update(tree, node*2+1, last_in_left + 1, node_high, pos, value);
    }
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll sum(ll tree[], int node, int node_low, int node_high, int l, int r){
    if(node_high < l || node_low > r){
        // outside
        return 0;
    }

    if(node_low >= l && node_high <= r){
        // completely inside
        return tree[node];
    }
    int lil = (node_low + node_high)/2;
    return sum(tree, node * 2, node_low, lil, l, r) + sum(tree, node * 2 + 1, lil + 1, node_high, l, r);
}

void solve() {
    int n,q; cin >> n >> q;
    ll arr[n], tree[n*4];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    build(arr, tree, 1, 0, n-1);

    while(q--){
        int t, a, b; cin >> t >> a >> b;
        if(t == 1){
            // update tree
            update(tree, 1, 0, n-1, a-1, b);
        }else{
            // return sum in range a,b
            ll res = sum(tree, 1, 0, n-1, a-1, b-1);
            cout << res << endl;
        }
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
