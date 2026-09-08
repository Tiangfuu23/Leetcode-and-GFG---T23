int inf = 1e6+1;
class Solution {
public:
    void build(vector<int>& tree, int v, int vl, int vr){
        if(vl == vr) {
            tree[v] = 1;
            return;
        };
        
        int m = (vl + vr)/2;
        build(tree, v*2, vl, m);
        build(tree, v*2+1, m + 1, vr);
        tree[v] = tree[v*2] + tree[v*2+1];
    }

    // same as find k-th min element ?
    int findKthEmpty(vector<int>& tree, int v, int vl, int vr, int k){
        if(vl == vr){
            return vl;
        }
        int m = (vl + vr) / 2;
        if(k <= tree[v*2]){
            return findKthEmpty(tree, v*2, vl, m, k);
        }else{
            return findKthEmpty(tree, v*2 + 1, m+1, vr, k - tree[v*2]);
        }
    }

    void update(vector<int>& tree, int v, int vl, int vr, int pos, int  val){
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

        tree[v] = tree[v*2] + tree[v*2+1];
    }
    // time = n*logn + n*logn
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& p1, vector<int>& p2){
            // Note: Nếu 2 người có cùng chiều cao thì ưu tiên xử lý người có k cao hơn trước vì người có k thấp hơn luôn luôn đứng trước (vì người đứng sau thì k phải > người đứng trước vì k người đứng sau = k người đứng trước + x)
            // ------- k1 ------ k2 = k1 + x >= k1 
            if(p1[0] == p2[0]) return p1[1] > p2[1];
            return p1[0] < p2[0];
        });
        
        vector<int> tree(4*n);
        build(tree, 1, 0, n-1);
        
        vector<vector<int>> ans(n, vector<int>(2));

        for(vector<int>& p : people){
            int pos = findKthEmpty(tree, 1, 0, n-1, p[1] + 1);
            update(tree, 1, 0, n - 1, pos, 0);
            // ans.push_back({p[0], p[1], pos});
            ans[pos] = p;
        }

        return ans;
    }
};