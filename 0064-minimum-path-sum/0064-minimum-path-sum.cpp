class Solution {
public:
   int helper(vector<vector<int>>& grid,int row,int col,vector<vector<int>> &dp){
    int m=grid.size();
    int n=grid[0].size();
    if(row>=m||col>=n) return 1e9;
    if(row==m-1&&col==n-1) return grid[row][col];
   
   //bottom
   if(dp[row][col]!=-1) return dp[row][col];
   int left=grid[row][col]+helper(grid,row+1,col,dp);
   int right=grid[row][col]+helper(grid,row,col+1,dp);
   return dp[row][col]=min(left,right);}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(grid,0,0,dp);
    }
};