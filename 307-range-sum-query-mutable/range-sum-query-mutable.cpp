class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        this->tree = vector<int>(nums.size() * 4);
        build(nums, 1, 0, nums.size() - 1);
    }
    
    void build(vector<int>& nums, int v, int vl, int vr){
        if(vl == vr){
            tree[v] = nums[vl];
            return;
        }

        int tm = (vl + vr) / 2;
        build(nums, v*2, vl, tm);
        build(nums, v*2 + 1, tm + 1, vr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }

    void update(int v, int vl, int vr, int index, int val){
        if(vl == vr){
            tree[v] = val;
            return;
        }
        int tm = (vl+vr)/2;
        if(index <= tm){
            update(v*2, vl, tm, index, val);
        }else{
            update(v*2+1, tm+1, vr, index, val);
        }
        tree[v] = tree[v*2] + tree[v*2 + 1];
    }

    void update(int index, int val) {
        update(1, 0, nums.size() - 1, index, val);
    }
    
    int sumRange(int v, int vl, int vr, int l, int r){
        if(vr < l || vl > r){
            return 0;
        }

        if(vl >= l && vr <= r){
            return tree[v];
        }
        int vm = (vl + vr)/2;
        return sumRange(v*2, vl, vm, l, r) + sumRange(v*2+1, vm + 1, vr, l , r);
    }

    int sumRange(int left, int right) {
        return sumRange(1, 0, nums.size() - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */