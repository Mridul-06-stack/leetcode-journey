class Solution {
public:
    map<pair<int,int>,int> dp;
    int helper(int idx,vector<int>& coins,int amount){
    if(amount==0) return 0;
    if(idx<0) return 1e9;
    int number=INT_MAX;
    int take=1e9;
    if(dp.count({idx,amount})) return dp[{idx,amount}];
    if(coins[idx]<=amount){
         take=1+helper(idx,coins,amount-coins[idx]);
    }
    int not_take=helper(idx-1,coins,amount);
    number=min(take,not_take);

   return dp[{idx,amount}]=number;
    }
    int coinChange(vector<int>& coins, int amount) {
     int n=coins.size();
     int ans=helper(n-1,coins,amount);   
     return ans>=1e9?-1:ans;
    }
};