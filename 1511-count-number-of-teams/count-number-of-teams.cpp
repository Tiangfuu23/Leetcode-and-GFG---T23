class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int m = 1; m<n-1; m++){
            int greaterLeft = 0, smallerLeft = 0, greaterRight = 0, smallerRight = 0;
            for(int j = 0; j<m; j++){
                if(rating[j] < rating[m]) smallerLeft++;
                if(rating[j] > rating[m]) greaterLeft++;
            }

            for(int j = m +1; j<n; j++){
                if(rating[j] < rating[m]) smallerRight++;
                if(rating[j] > rating[m]) greaterRight++;
            }

            ans += (smallerLeft * greaterRight) + (greaterLeft * smallerRight);
        }

        return ans;
    }
};