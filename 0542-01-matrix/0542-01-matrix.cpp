class Solution {
public:
   vector<pair<int,int>> dir={
   {0,1},
    {1,0},
    {-1,0},
    {0,-1}
   };
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>> q1;
        vector<vector<int>> visited (n,vector<int> (m,0));
       vector<vector<int>> ans (n,vector<int> (m,0));
       for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
       if(mat[row][col]==0){
        q1.push({{row,col},0});
        visited[row][col]=1;
       }
        }
       }
      while(!q1.empty()){
        int row=q1.front().first.first;
        int col=q1.front().first.second;
         int dis=q1.front().second;
         int newrow;
         int newcol;
         q1.pop();
         ans[row][col]=dis;
         for(auto it:dir){
            newrow=row+it.first;
            newcol=col+it.second;
            if(newrow>=0&& newrow<n && newcol>=0 && newcol<m && !visited[newrow][newcol]){
            visited[newrow][newcol]=1;
            q1.push({{newrow,newcol},dis+1});
            }
         }


      }
return ans;
    }
};