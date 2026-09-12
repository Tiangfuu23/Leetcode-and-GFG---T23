class LUPrefix {
public:
    unordered_set<int> st;
    int ans = 0;
    LUPrefix(int n) {
        
    }
    
    void upload(int video) {
        st.insert(video);
        while(st.find(ans + 1) != st.end()){
            ans++;
        }
    }
    
    int longest() {
        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */