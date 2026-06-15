class Solution {
public:
    vector<int> result;

    vector<int> topoCheck(int n, vector<vector<int>>& adj, vector<int>& indegree) {

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                result.push_back(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {

                indegree[v]--; //indicates one dependency is resolved
                
                //indicates all dependency has been touched by bfs
                if (indegree[v] == 0) {
                    q.push(v);
                    result.push_back(v);
                }
            }
        }

        if (result.size() == n) return result;
        
        return {};
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return topoCheck(numCourses, adj, indegree);

    }
};