class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, int i, vector<bool>& visited, vector<bool>& inRec) {

        visited[i] = true;
        inRec[i] = true;

        for (auto& v : adj[i]) {
            if (!visited[v] && isCycle(adj, v, visited, inRec)) {
                return true;
            } else if (inRec[v] == true) {
                return true;
            }
        }

        inRec[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        vector<bool> visited(numCourses, 0);
        vector<bool> inRec(numCourses, 0);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && isCycle(adj, i, visited, inRec)) {
                return false;
            }
        }

        return true;
    }
};