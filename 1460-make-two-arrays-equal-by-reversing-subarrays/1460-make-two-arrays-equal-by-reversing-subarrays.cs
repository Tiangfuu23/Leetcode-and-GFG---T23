// 4 2 3 5 1 
public class Solution {
    public bool CanBeEqual(int[] target, int[] arr) {
        int n = target.Length;
        int[] mp = new int[1001];
        
        for(int i = 0; i<n; i++){
            mp[target[i]] += 1;
            mp[arr[i]] -= 1;
        }
        
        foreach(int num in mp) if(num != 0) return false;
        return true;
    }
}