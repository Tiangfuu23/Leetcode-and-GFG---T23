class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        unordered_set<int> trustSomeOne;
        unordered_map<int,int> count;
        for(vector<int>& i : trust){
            trustSomeOne.insert(i[0]);
            if(count.find(i[1]) != count.end()) count[i[1]]++;
            else count.insert({i[1],1});
        }
        for(int i = 1; i<=n; i++){
            if(trustSomeOne.find(i) == trustSomeOne.end()){
                if(count.find(i) != count.end() && count[i] == n-1) return i;
            }
        }
        return -1;
    }
};