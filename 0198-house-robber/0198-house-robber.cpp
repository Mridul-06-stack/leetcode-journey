class Solution {
public:

     int   helper(int idx,vector<int>& nums,vector<int> &dp){
        if(idx>=nums.size()){ 
            return 0;
        }
     
      //pick
      if(dp[idx]==-1){
        dp[idx]=max(nums[idx]+helper(idx+2,nums,dp),helper(idx+1,nums,dp));
      }
   
     return dp[idx];
     }
    int rob(vector<int>& nums) {
        int maxi=0;
        int money=0;
        vector<int> dp(101,-1);
     return helper(0,nums,dp);  
      
    }
};