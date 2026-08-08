class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {

        // Currently in this DFS path => cycle
        if (state[node] == 1)
            return false;

        // Already completely processed
        if (state[node] == 2)
            return true;

        state[node] = 1;  // currently visiting

        for (int neighbour : adj[node]) {
            if (!dfs(neighbour, adj, state))
                return false;
        }

        state[node] = 2;  // completely finished

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (state[i] == 0) {
                if (!dfs(i, adj, state))
                    return false;
            }
        }

        return true;
    }
};