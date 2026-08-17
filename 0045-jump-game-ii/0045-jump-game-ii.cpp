class Solution {
public:
   int helper(int idx,vector<int>& nums,vector<int> &dp){
    if(idx==nums.size()-1){
        return 0;
    }
    
    int minJump=1e9;
    if(dp[idx]!=-1) return dp[idx];
   for(int i = idx + 1; i <= idx + nums[idx] && i < nums.size(); i++){
    int currjump=i-idx;
    int cost=1+helper(i,nums,dp);
    minJump=min(minJump,cost);
    
    }
   return dp[idx]=minJump;
   }
    int jump(vector<int>& nums) {
        vector<int> dp (nums.size(),-1);
        return helper(0,nums,dp);
    }
};