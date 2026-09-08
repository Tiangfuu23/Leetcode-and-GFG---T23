int inf = 1e6+1;
class Solution {
public:
    void init(vector<pair<int ,int>>& tree, int v, int vl, int vr){
        tree[v] = {inf, vr - vl + 1};
        if(vl == vr) return;
        
        int m = (vl + vr)/2;
        init(tree, v*2, vl, m);
        init(tree, v*2+1, m + 1, vr);
    }
    pair<int, int> chooseBest(pair<int, int>& pl, pair<int, int>& pr){
        if(pl.first < pr.first) return pr;
        
        if(pl.first > pr.first) return pl;

        return {pl.first, pl.second + pr.second};
    }

    pair<int, int> findMax(vector<pair<int, int>>& tree, int v, int vl, int vr, int l, int r){
        if(vr < l || vl > r){
            return {-1, 0}; // 
        }

        if(vl >= l && vr <= r){
            return tree[v];
        }

        int m = (vl+vr)/2;
        pair<int, int> pl = findMax(tree, v*2, vl, m, l, r);
        pair<int, int> pr = findMax(tree, v*2 + 1, m+1, vr, l, r);
    
        return chooseBest(pl, pr);
    }

    void update(vector<pair<int, int>>& tree, int v, int vl, int vr, int pos, pair<int, int> val){
        if(vl == vr){
            tree[v] = val;
            return;
        }

        int m = (vl + vr)/2;

        if(pos <= m){
            update(tree, v*2, vl, m, pos, val);
        }else {
            update(tree, v*2+1, m + 1, vr, pos, val);
        }

        pair<int, int> p = chooseBest(tree[v*2], tree[v*2 + 1]);
        tree[v] = p;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2){
            if(p1[0] == p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        });
        
        vector<pair<int, int>> tree(4*n); // max value, no.of time its appear
        init(tree, 1, 0, n-1);
        
        vector<vector<int>> ans(n, vector<int>(2));

        unordered_set<int> isTaken;

        for(vector<int>& p : people){
            int i = p[1];

            for(; i < n; i++){
                if(isTaken.find(i) != isTaken.end()) continue;
                // check range [0, i-1]
                pair<int, int> q = findMax(tree, 1, 0, n-1, 0, i-1);
                
                bool isFound = (q.first >= p[0] && q.second == p[1]) || (q.first < p[0] && p[1] == 0);

                // if(p[0] == 6 && p[1] == 1 && i == 3){
                //     // vector<int> temp = {q.first, q.second};
                //     // ans.push_back(temp);
                //     // return ans;

                //             for(auto p : tree){
                //             ans.push_back({p.first, p.second});
                //         }
                        
                //         return ans;
                // }

                if(isFound){
                    isTaken.insert(i);
                    update(tree, 1, 0 , n-1, i, {p[0], 1});
                    break;
                }
            }
            if(i < n){
                ans[i] = p;
            }
        }

        return ans;
    }
};