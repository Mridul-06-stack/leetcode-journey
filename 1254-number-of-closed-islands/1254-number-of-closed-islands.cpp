class Solution {
public:
    vector<pair<int,int>> dir={
        {0,-1},
        {0,1},
         {-1,0},
         {1,0}
    };
    void  mark(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &visited){
     int newrow;
     visited[row][col]=1;
     int newcol;
     int n=grid.size();
     int m=grid[0].size();
     for(auto [dr,dc]:dir){
        newrow=row+dr;
        newcol=col+dc;
        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==0&&!visited[newrow][newcol]){
            mark(newrow,newcol,grid,visited);
        }
     }


return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){ 
                    if(grid[i][j]==0){
                        mark(i,j,grid,visited);
                    }
                }
            }
        }
        int count=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]==0){ 
             count++;
                mark(i,j,grid,visited);
            }
        }
     }



return count;
    }
};