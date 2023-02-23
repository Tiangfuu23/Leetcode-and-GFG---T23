#include <bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

bool fcompare(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return a.first < b.first;
    }
}

void solve(){
    int n; cin >> n;
    int x;
    unordered_map<int,int> mp; // value-freq
    for(int i = 0; i<n; i++){
        cin >> x;
        if(mp.find(x) != mp.end()) mp[x]++;
        else mp.insert({x,1});
    }
    vector<pair<int,int>> arr;
    for(auto& i : mp){
        arr.push_back(i);
    }
    sort(arr.begin(), arr.end(), fcompare);
    for(pair<int,int>& i : arr){
        while(i.second != 0){
            cout << i.first << " ";
            i.second--;
        }
    }
    cout << endl;
}

int main() {
    faster();
	int t; cin >> t;
	while(t--){
	    solve();
	}
	return 0;
}