//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{   
	    int n = nums.size();
	    unordered_map<int,int> mp; // value - its indices
    	for(int i = 0; i<n; i++) {
    		mp[nums[i]] = i;
    	}
    	vector<int> target = nums;
    	sort(target.begin(), target.end());
    	int ans = 0;
    	for(int i = 0; i<n; i++){
    		if(nums[i] != target[i]){
    			ans++;
    			// find target[i] in arr and swap it with arr[i]
    			int idx = mp[target[i]];
    			mp[nums[i]] = idx;
    			swap(nums[i],nums[idx]);
    		}
    	}
    	return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends