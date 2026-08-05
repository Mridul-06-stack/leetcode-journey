class Solution {
public:
    vector<pair<int,int> > dir={
   { 0,-1},
   {0,1},
   {-1,0},
   {1,0}
    };
    int dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int row,int col,int &currarea){
   visited[row][col]=1;
   int newrow;
   int newcol;
   int n=grid.size();
   int m=grid[0].size();
   for(auto [dr,dc]: dir)
{
    newrow=row+dr;
    newcol=col+dc;
    if(newrow>=0&& newrow<n&& newcol>=0&& newcol<m &&!visited[newrow][newcol] && grid[newrow][newcol]==1){
        currarea++;
        dfs(grid,visited,newrow,newcol,currarea);
    }
}
return currarea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            int area=0;
            vector<vector<int>> visited(n,vector<int> (m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++ ){
              if(grid[i][j]==1&&!visited[i][j]){
              int currarea=1;
              area=max(area,dfs(grid,visited,i,j,currarea));
              }
                }
            }
    return area;}
};