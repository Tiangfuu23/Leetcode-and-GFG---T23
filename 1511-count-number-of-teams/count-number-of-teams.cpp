class Solution {
public:
    vector<int> coordinateCompress(vector<int>& rating){
        vector<int> temp = rating;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        
        for(int i = 0; i<temp.size(); i++){
            mp.insert({temp[i], i});
        }

        vector<int> compressedArray(rating.size());
        for(int i = 0; i<rating.size(); i++){
            compressedArray[i] = mp[rating[i]];
        }

        return compressedArray;
    }

    void build(vector<int>& arr, vector<int>& tree, int v, int vl, int vr){
        if(vl == vr){
            tree[v] = arr[vl];
            return;
        }

        int m = (vl + vr)/2;
        build(arr, tree, v*2, vl, m);
        build(arr, tree, v*2+1, m+1, vr);

        tree[v] = tree[v*2] + tree[v*2+1];
    }

    void update(vector<int>& tree, int v, int vl, int vr, int pos, int value){
        if(vl == vr){
            tree[v] = value;
            return;
        }

        int m = (vl + vr)/2;
        if(pos <= m){
            update(tree, v*2, vl, m, pos, value);
        }else{
            update(tree, v*2+1, m+1, vr, pos, value);
        }

        tree[v] = tree[v*2] + tree[v*2+1];
    }

    int query(vector<int>& tree, int v, int vl, int vr, int l, int r){
        if(vr < l || vl > r){
            return 0;
        }

        if(l <= vl && vr <= r){
            return tree[v];
        }
        int m = (vl + vr) / 2;
        return query(tree, v*2, vl, m, l, r) + query(tree, v*2+1, m + 1, vr, l, r);
    }

    int numTeams(vector<int>& rating) {
        int n = 1000, ans = 0;
        vector<int> compressed_arr = coordinateCompress(rating);
        vector<int> temp(n, 0);
        for(int& num : compressed_arr){
            temp[num] = 1;
        }
        vector<int> left_tree(4*n), right_tree(4*n);
        build(temp, right_tree, 1, 0, n-1);
        update(right_tree, 1, 0, n-1, compressed_arr[0], 0);
        update(left_tree, 1, 0, n-1, compressed_arr[0], 1);

        for(int i = 1; i<compressed_arr.size()-1; i++){
            int num = compressed_arr[i];
        
            int less_left = query(left_tree, 1, 0, n -1, 0, num -1);
            int greater_left = query(left_tree, 1, 0, n -1, num+1, n-1);

            int less_right = query(right_tree, 1, 0, n -1, 0, num -1);
            int greater_right = query(right_tree, 1, 0, n -1, num+1, n-1);

            ans += (less_left * greater_right) + (greater_left * less_right);
            update(left_tree, 1, 0, n-1, num, 1);
            update(right_tree, 1, 0, n-1, num, 0);
        }
        return ans;
    }
};