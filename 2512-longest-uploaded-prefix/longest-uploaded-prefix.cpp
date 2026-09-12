// Time complexity: Query: O(1)
// Time complexity: Upload: O(logn)
class LUPrefix {
public:
    vector<pair<int, int>> tree; // [left, right)
    int n;
    LUPrefix(int n) {
        tree = vector<pair<int, int>>(4*n);
        this->n = n;
    }
    
    void update(vector<pair<int, int>>& tree, int v, int vl, int vr, int pos){
        if(vl == vr){
            tree[v] = {vl, vr + 1};
            return;
        }

        int mid = (vl + vr) / 2;
        if(pos <= mid){
            update(tree, v*2, vl, mid, pos);
        }else{
            update(tree, v*2+1, mid+1, vr, pos);
        }
        if(tree[v*2].second == tree[v*2+1].first){
            // can expand
            tree[v] = {tree[v*2].first, tree[v*2+1].second};
        }else{
            tree[v] = tree[v*2];
        }
    }

    void upload(int video) {
        // int videoIdx = video - 1
        update(tree, 1, 0, n-1, video - 1);
    }
    
    int longest() {
        return tree[1].second;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */