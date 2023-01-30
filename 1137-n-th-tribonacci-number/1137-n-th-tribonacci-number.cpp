class Solution {
public:
    int tribonacci(int n) {
        int t3 = 0, t2 = 1, t1 = 1,tn;
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        for(int i =3; i<=n; i++){
            tn = t1+t2+t3;
            t3 = t2;
            t2 = t1;
            t1 = tn;
        }
    return tn;
    }
};