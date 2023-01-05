class Solution {
public:
    long long solve(vector<int> a,int n){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0] = 0;
        for(int i=0;i<n;i++){
            dp[0] += (i*nums[i]);
        }
        long long sum = solve(nums,n);
        int j=n-1;
        for(int i=1;i<n;i++){
            dp[i] = dp[i-1] + (sum - (n*nums[j--]));
        }
        int maxi = dp[0];
        for(int i=1;i<n;i++){
            if(dp[i]>maxi){
                maxi = max(maxi,dp[i]);
            }
        }
        return maxi;
    }
};