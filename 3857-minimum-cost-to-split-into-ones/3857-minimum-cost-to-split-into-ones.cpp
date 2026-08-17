class Solution {
public:
    int helper(int n, vector<int> &dp){

        if(n <= 1) return 0;
        if(dp[n] != -1) return dp[n];

        int minCost = INT_MAX;

        for(int i = 1; i < n; i++){
            int a = i, b = n-i;
            int cost = a*b + helper(a,dp) + helper(b,dp);
            minCost = min(minCost, cost);
            dp[n] = minCost;
        }

        return dp[n]= minCost ;
    }
    int minCost(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};