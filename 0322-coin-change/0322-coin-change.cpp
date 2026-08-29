class Solution {
public:

    int helper(int idx, vector<int>& coins, int amount,
               vector<vector<int>>& dp) {

        if (amount == 0) return 0;
        if (idx < 0) return 1e9;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int take = 1e9;

        if (coins[idx] <= amount) {
            take = 1 + helper(idx, coins, amount - coins[idx], dp);
        }

        int not_take = helper(idx - 1, coins, amount, dp);

        return dp[idx][amount] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(n - 1, coins, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};