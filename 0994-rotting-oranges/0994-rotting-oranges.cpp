class Solution {
public:
    vector<pair<int,int>> dir={
     {0,1},
     {1,0},
     {0,-1},
     {-1,0}
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int >,int>> q1;
        int time=0;
        int fresh=0;
        vector<vector<int>> visited (n,vector<int> (m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    visited[row][col]=1;
                    q1.push({{row,col},0});
                }
                 else if(grid[row][col] == 1) {
            fresh++;
        }
            }
        }
       while(!q1.empty()){
        int size=q1.size();
        for(int i=0;i<size;i++){
          int row=q1.front().first.first;
          int col=q1.front().first.second;
          int currtime=q1.front().second;
          time=max(time,currtime);
          q1.pop();
          int newrow;
          int newcol;
          for(auto it:dir){
           newrow=row+it.first;
           newcol=col+it.second;
           
           if(newrow>=0&&newrow<n && newcol>=0 && newcol<m && !visited[newrow][newcol] &&
   grid[newrow][newcol] == 1){
            visited[newrow][newcol]=1;
            grid[newrow][newcol]=2;
            fresh--;
            q1.push({{newrow,newcol},currtime+1});
           }
        

          }




        }
       }
       if(fresh>0){
        return -1;
       }

  return time;
    }
};