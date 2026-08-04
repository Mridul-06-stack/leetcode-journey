class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

   


        for(int i=0;i<n;i++){
           
        if(visited[i]==-1){
             queue<int> q1;
        q1.push(i);
        visited[i] = 0;
        while (!q1.empty()) {
            int node = q1.front();
            q1.pop();
            for (auto it : graph[node]) {

                if (visited[it] == -1) {
                    q1.push(it);
                    visited[node] == 0 ? visited[it] = 1 : visited[it] = 0;
                } else if (visited[it] == 0 || visited[it] == 1) {
                    int next = visited[it];
                    int current = visited[node];
                    if (current == next) {
                        return false;
                    }
                }
            }
              



        }
        }
        }
   return true; }
};