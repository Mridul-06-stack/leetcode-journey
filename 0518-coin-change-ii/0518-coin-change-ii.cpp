class Solution {
public:
int helper(int idx, vector<int>& coins, int amount,
               vector<vector<int>>& dp) {

        if (amount == 0) return 1;
        if (idx < 0) return 0;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = 0;

        if (coins[idx] <= amount) {
            take =helper(idx, coins, amount - coins[idx], dp);
        }

        int not_take = helper(idx - 1, coins, amount, dp);

        return dp[idx][amount]= take+not_take;
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans=0;
        ans = helper(n - 1, coins, amount, dp);

       return ans;
    }
};