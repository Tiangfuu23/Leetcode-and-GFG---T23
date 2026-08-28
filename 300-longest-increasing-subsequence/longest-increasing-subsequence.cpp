class Solution {
public:
        vector<int> compress(vector<int>& nums){
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp; // map value to index
        int counter = 0;
        for(int i = 0; i<temp.size(); i++){
            mp.insert({temp[i], counter++});
        }
        vector<int> compressed_array;
        for(int& n : nums){
            compressed_array.push_back(mp[n]);
        }

        return compressed_array;
    }

    int queryMax(vector<int>& tree, int v, int vl, int vr, int l, int r){
        if(vr < l || vl > r)
            return 0;
        if(vl >= l && vr <= r){
            return tree[v];
        }
        int m = (vl+vr)/2;
        return max(queryMax(tree, v*2, vl, m, l ,r), queryMax(tree, v*2+1, m+1, vr, l ,r));
    }

    void update(vector<int>& tree, int v, int vl, int vr, int pos, int val){
        if(vl == vr){
            tree[v] = val;
            return;
        }
        int m = (vl+vr)/2;
        if(pos <= m){
            update(tree, v*2, vl, m, pos, val);
        }else{
            update(tree, v*2+1, m+1, vr, pos, val);
        }

        tree[v] = max(tree[v*2], tree[v*2+1]);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = compress(nums);
        // return arr.size();
        vector<int> tree(4*n);
        // int ans = 0;
        for(int& i : arr){
            // find max range 0 -> i - 1;
            int len = (i == 0 ? 1 : queryMax(tree, 1, 0, n-1, 0, i-1) + 1);
            // update
            update(tree, 1, 0, n-1, i, len);
            // ans = max(ans, len);
        }

        return tree[1];
    }
};