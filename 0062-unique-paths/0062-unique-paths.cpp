class Solution {
    vector<vector<int>> directions={
        {0,1},
        {1,0}
    };int new_row;
        int new_col;
     int find(int row,int col ,int &m,int &n,vector<vector<int>> &dp){
      if(row<0||col<0||row>=m||col>=n){
            return 0;
        } if(row==m-1&&col==n-1){
            return 1;
        }
        
        if(dp[row][col]==-1){
            int number=0;
        for(const auto& dir: directions){
            new_row=row+dir[0];
            new_col=col+dir[1];
         number+=find(new_row,new_col,m,n,dp);
        }
        dp[row][col]=number;
        }

        return dp[row][col];
    }
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(0,0,m,n,dp);
        
    }
};