
class Solution {
public:
    bool helper(int idx, int jump,
                vector<int>& stones,
                unordered_map<int, int>& pos,
                vector<vector<int>>& dp) {

        // Reached last stone
        if (idx == stones.size() - 1)
            return true;

        // Already calculated
        if (dp[idx][jump] != -1)
            return dp[idx][jump];

        // Try jump-1, jump, jump+1
        for (int nextJump = jump - 1;
             nextJump <= jump + 1;
             nextJump++) {

            if (nextJump <= 0)
                continue;

            int nextPos = stones[idx] + nextJump;

            // Check if a stone exists at nextPos
            if (pos.find(nextPos) != pos.end()) {

                int nextIdx = pos[nextPos];

                if (helper(nextIdx, nextJump,
                           stones, pos, dp)) {

                    return dp[idx][jump] = true;
                }
            }
        }

        return dp[idx][jump] = false;
    }

    bool canCross(vector<int>& stones) {

       if(stones[1]!=1) return false;

        // stone position -> index
        unordered_map<int, int> pos;
       int n=stones.size();
        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        // dp[index][jump]
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // First jump is 1, so we start at stone index 1
        return helper(1, 1, stones, pos, dp);
    }
};