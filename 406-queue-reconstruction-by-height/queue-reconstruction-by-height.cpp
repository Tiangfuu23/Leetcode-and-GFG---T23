int inf = -1;
// tuple<int, int, int> naturalValue = {inf, 1, };
class Solution {
public:
    void init(vector<tuple<int ,int, int>>& tree, int v, int vl, int vr){
        tree[v] = {inf, vr - vl + 1, vr - vl + 1};
        if(vl == vr) return;
        
        int m = (vl + vr)/2;
        init(tree, v*2, vl, m);
        init(tree, v*2+1, m + 1, vr);
    }
    tuple<int, int, int> chooseBest(tuple<int, int, int>& a, tuple<int, int, int>& b){
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        if(a1 < b1) return {b1, b2, a3 + b3};
        
        if(a1 > b1) return {a1, a2, a3 + b3};

        return {a1, a2 + b2, a3 + b3};
    }

    tuple<int, int, int> findMax(vector<tuple<int, int, int>>& tree, int v, int vl, int vr, int l, int r){
        if(vr < l || vl > r){
            return {inf - 1, 0, 0}; // 
        }

        if(vl >= l && vr <= r){
            return tree[v];
        }

        int m = (vl+vr)/2;
        auto pl = findMax(tree, v*2, vl, m, l, r);
        auto pr = findMax(tree, v*2 + 1, m+1, vr, l, r);
    
        return chooseBest(pl, pr);
    }

    void update(vector<tuple<int, int, int>>& tree, int v, int vl, int vr, int pos, tuple<int, int, int> val){
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

        auto  p = chooseBest(tree[v*2], tree[v*2 + 1]);
        tree[v] = p;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2){
            if(p1[0] == p2[0]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });
        
        vector<tuple<int, int, int>> tree(4*n); // max value, no.of time its appear
        init(tree, 1, 0, n-1);
        
        vector<vector<int>> ans(n, vector<int>(2));
        
        // for(auto [a,b,c] : tree){
        //     ans.push_back({a,b,c});
        // }        
        // return ans;

        unordered_set<int> isTaken;

        for(vector<int>& p : people){
            int i = p[1];

            for(; i < n; i++){
                if(isTaken.find(i) != isTaken.end()) continue;
                // check range [0, i-1]
                auto [a, b ,c] = findMax(tree, 1, 0, n-1, 0, i-1);
                
                bool isFound = (a >= p[0] && b + c == p[1]) || (a < p[0] && c == p[1]);

                // if(p[0] == 5 && p[1] == 2 && i == 2){
                //     ans.push_back({a,b,c});
                //     return ans;

                //         //     for(auto p : tree){
                //         //     ans.push_back({p.first, p.second});
                //         // }
                        
                //         // return ans;
                // }

                    
                if(isFound){
                    isTaken.insert(i);
                    update(tree, 1, 0 , n-1, i, {p[0], 1, 0});
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