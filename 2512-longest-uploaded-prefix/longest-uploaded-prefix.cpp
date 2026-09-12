// Time complexity: Query: O(1)
// Time complexity: Upload: O(logn)

// Find smallest video which is not updated
class LUPrefix {
public:
    int inf = 1e5 + 1;
    vector<int> tree;
    int n;
    LUPrefix(int n) {
        tree = vector<int>(4*n);
        this->n = n;
        build(tree, 1, 0, n-1);
    }
    void build(vector<int>& tree, int v, int vl, int vr){
        if(vl == vr){
            tree[v] = vl;
            return;
        }

        int m = (vl + vr)/2;
        build(tree, v*2, vl, m);
        build(tree, v*2+1, m+1, vr);

        tree[v] = tree[v*2];
    }
    void update(vector<int>& tree, int v, int vl, int vr, int pos){
        if(vl == vr){
            tree[v] = inf;
            return;
        }

        int mid = (vl + vr) / 2;
        if(pos <= mid){
            update(tree, v*2, vl, mid, pos);
        }else{
            update(tree, v*2+1, mid+1, vr, pos);
        }
        tree[v] = min(tree[v*2], tree[v*2+1]);
    }

    void upload(int video) {
        // int videoIdx = video - 1
        update(tree, 1, 0, n-1, video - 1);
    }
    
    int longest() {
        return min(tree[1], n);
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */