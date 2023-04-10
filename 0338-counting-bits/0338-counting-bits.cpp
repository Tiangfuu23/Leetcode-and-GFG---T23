class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i<=n; i++){
            int temp = i,cnt = 0;
            while(temp!=0){
                if(temp&1) cnt++;
                temp/=2;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};