class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size();
        int cnt_zero = 0, cnt_one = 0;
        int ans = 0;
        for(int i = 0; i<n ; i++){
            if(s[i] == '0'){
                cnt_zero++;
            }else if(s[i] == '1' && i>0 && s[i-1] == '0'){
                int j = i;
                while(j<n && s[j] == '1'){
                    cnt_one++;
                    j++;
                }
                ans = fmax(ans,2*fmin(cnt_one,cnt_zero));
                cnt_zero = cnt_one = 0;
                i = j-1;
            }
        }
        return ans;
    }
};