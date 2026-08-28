class Solution {
public:
map<pair<int, int>, int> dp;
    int helper(int idx,int sum,vector<int> & nums,int target){
      if(idx==nums.size()){

         if(sum==target)return 1;
         return 0;
      }
      pair<int,int> state={idx,sum};
      if(dp.count(state)){
        return dp[state];
      }
     int add=helper(idx+1,sum+nums[idx],nums,target);
     int sub=helper(idx+1,sum-nums[idx],nums,target);



return dp[state]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

         return helper(0,0,nums,target);
    }
};