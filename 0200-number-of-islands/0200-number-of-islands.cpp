class Solution {
public:
    vector<pair<int, int>> directions = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};
    void find(vector<vector<int>> &visited,int row,int col,vector<vector<char>>& grid){
     queue<pair<int,int>> q1;
     q1.push({row,col});
     visited[row][col]=1;
     int n=grid.size();
     int m=grid[0].size();
     while(!q1.empty()){
        int row=q1.front().first;
        int col=q1.front().second;
        q1.pop();
        int newrow;
        int newcol;

        for(auto it:directions){
         newrow=row+it.first;
         newcol=col+it.second;
         if(newrow>=0&&newrow<n&&  newcol>=0 && newcol<m
         &&!visited[newrow][newcol] &&grid [newrow][newcol]=='1'
           ){
            visited[newrow][newcol]=1;
            q1.push({newrow,newcol});
            

           }
        }
     }




return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        vector<vector<int>> visited (n,vector<int>(m,0));


        for(int i=0;i<n;i++){
            for(int  j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                islands++;   
                find(visited,i,j,grid);
                }
            }
        }
   return islands; }
};