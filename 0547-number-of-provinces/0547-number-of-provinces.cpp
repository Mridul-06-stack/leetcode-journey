class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &visited,int idx){
      visited[idx]=1;
      for(int i=0;i<adj.size();i++){
        if(!visited[i]&&adj[idx][i]==1&&i!=idx){
            dfs(adj,visited,i);
        }
      }
      return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
       int number=0;
       vector<int> visited(n,0);

        for(int i=0;i<n;i++){
       if(!visited[i]){
        number++;
        dfs(isConnected,visited,i);

       } 
        }
    return number; }
};