class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ne = nums;
        sort(ne.begin(),ne.end());
        int start_pos = 1 , end_pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=ne[i]){
                start_pos = i;
                break;
            }
        }
        for(int j = nums.size()-1;j>=0;j--){
             if(nums[j]!=ne[j]){
                end_pos = j;
                break;
            }
        }
        return end_pos-start_pos+1;
    }
};