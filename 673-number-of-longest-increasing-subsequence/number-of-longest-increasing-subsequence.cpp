class Solution {
public:
    void compress(vector<int>& nums){
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp; // map value to index
        int counter = 0;
        for(int i = 0; i<temp.size(); i++){
            mp.insert({temp[i], counter++});
        }
        vector<int> compressed_array;

        for(int i = 0; i<nums.size(); i++){
            nums[i] = mp[nums[i]];
        }
    }

    pair<int, int> queryMax(vector<pair<int, int>>& tree, int v, int vl, int vr, int l, int r){
        if(vr < l || vl > r)
            return {0,0};
        if(vl >= l && vr <= r){
            return tree[v];
        }
        int m = (vl+vr)/2;

        pair<int, int> pl = queryMax(tree, v*2, vl, m, l ,r);
        pair<int, int> pr = queryMax(tree, v*2+1, m+1, vr, l ,r);

        if(pl.first < pr.first){
            return pr;
        }else if(pl.first > pr.first){
            return pl;
        }else{
            return make_pair(pl.first, pl.second  + pr.second);
        }
    }

    void update(vector<pair<int, int>>& tree, int v, int vl, int vr, int pos, pair<int, int> val){
        if(vl == vr){
            if(tree[v].first == val.first){
                tree[v].second += val.second;
            }else{
                // if in this case: val.fisrt always greater than tree[v].first
                tree[v] = val;
            }
            return;
        }
        int m = (vl+vr)/2;
        if(pos <= m){
            update(tree, v*2, vl, m, pos, val);
        }else{
            update(tree, v*2+1, m+1, vr, pos, val);
        }

        tree[v].first = max(tree[v*2].first, tree[v*2+1].first);

        if(tree[v*2].first == tree[v*2+1].first){
            tree[v].second = tree[v*2].second + tree[v*2+1].second;
        }else{
            tree[v].second = (tree[v].first == tree[v*2].first) ? tree[v*2].second : tree[v*2+1].second;
        }
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        compress(nums);
        vector<pair<int, int>> tree(4*n);
        for(int& i : nums){
            // find max range 0 -> i - 1;
            pair<int, int> p = (i == 0 ? make_pair(0, 0) : queryMax(tree, 1, 0, n-1, 0, i-1));
            p.first = p.first + 1;
            p.second = p.second != 0 ? p.second : 1;
            // update
            update(tree, 1, 0, n-1, i, p);
        }

        return tree[1].second;
    }
};