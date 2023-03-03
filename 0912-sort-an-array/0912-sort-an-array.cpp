class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int hight){
        int l = low, r = mid+1, k =0, size = hight-low +1;
        vector<int> sorted(size,0);
        while(l <= mid && r <=hight) sorted[k++] = arr[l] < arr[r] ? arr[l++] : arr[r++];
        while(l <= mid) sorted[k++] = arr[l++];
        while(r <= hight) sorted[k++] = arr[r++];
        for(int i =0; i<size; i++) arr[low+i] = sorted[i];  
    } 
    void merge_sort(vector<int>& arr, int low, int hight){
        if(low>=hight) return;
        int mid = low + (hight-low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,hight);
        merge(arr,low,mid,hight);
    }
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums,0,nums.size()-1);
        return nums;
    }
};