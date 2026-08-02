class Solution {
public:
vector<pair<int,int>> dir={
{0,1},
{1,0},
{0,-1},
{-1,0}
};
     void dfs(vector<vector<int>> &visited,vector<vector<char>>& board,int row,int col){
        int newrow;
        int newcol;
        int n=board.size();
        int m=board[0].size();
    
       for(auto it:dir){
        newrow=row+it.first;
        newcol=col+it.second;
        if(newrow>=0 &&newrow<n && newcol>=0 && newcol<m && !visited[newrow][newcol]&&board[newrow][newcol]=='O'){
             visited[newrow][newcol]=1;
            dfs(visited,board,newrow,newcol);
        }
       }


     return;

    }
    void solve(vector<vector<char>>& board) {
    int n=board.size();
    int m=board[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(i==0||j==0||i==n-1||j==m-1){
            if(board[i][j]=='O'){
                visited[i][j]=1;
                dfs(visited,board,i,j);
            }
        }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }
    return ;
    }
};