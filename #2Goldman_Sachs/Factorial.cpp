class Solution {
public:
long long int pow(int n,int k){
    int ans=0;
    while(n>0){
        ans+=(n/k);
        n/=k;
    }
    return ans;
}
    int trailingZeroes(int n) {
       int x1 = pow(n,5);
       int x2 = pow(n,2);
       return min(x1,x2);
    }
};