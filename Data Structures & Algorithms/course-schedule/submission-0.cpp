class Solution {
public:

    bool topoCheck(int n, vector<vector<int>>& adj, vector<int>& indegree) {

        int count = 0;

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                count++;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& i : adj[u]) {
                
                indegree[i]--;

                if (indegree[i] == 0) {
                    q.push(i);
                    count++;
                }
            }
        }

        return count == n;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
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
