class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Courses with no prerequisites
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            // Complete this course
            // and remove its dependency from next courses
            for(auto next : adj[node]) {
                indegree[next]--;

                if(indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Cycle exists
        if(ans.size() != numCourses)
            return {};

        return ans;
    }
};