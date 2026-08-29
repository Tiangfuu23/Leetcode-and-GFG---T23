/*
Brute force: For each fruit i -> find basket j where j_min & basket[j] > fruit[i] & basket j is unsed
    if exists: -> mark basket is used
    if not: -> i is unplaced

    // time complexity: O(n^2)
*/

// Optimized approach
class Solution {
public:
    void build(vector<int>& arr, vector<int>& tree, int v, int vl, int vr){
        if(vl == vr){
            tree[v] = arr[vl];
            return;
        }
        int m = (vl + vr)/2;
        build(arr, tree, v*2, vl, m);
        build(arr, tree, v*2 + 1, m + 1, vr);

        tree[v] = max(tree[v*2], tree[v*2+1]);
    }

    void updateLeftMost(vector<int>& tree, int v, int vl, int vr, int val){
        if(vl == vr){
            tree[v] = 0;
            return;
        }

        int m = (vl+vr)/2;
        if(tree[v*2] >= val){
            updateLeftMost(tree, v*2, vl, m, val);
        }else{
            updateLeftMost(tree, v*2+1, m+1, vr, val);
        }

        tree[v] = max(tree[v*2], tree[v*2+1]);
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> tree(4*n);
        build(baskets, tree, 1, 0, n-1);
        int ans = 0;
        for(int& f : fruits){
            if(tree[1] >= f){
                updateLeftMost(tree, 1, 0, n-1, f);
            }else{
                ans++;
            }
        }
        return ans;
    }
};