class Solution {
public:
    bool iscycleDFS(vector<vector<int>>& adj, int i, 
    unordered_set<int>& visited, int prev) {

        visited.insert(i);

        for (auto& v : adj[i]) {

            if (v == prev) continue;

            if (visited.find(v) != visited.end()) return true;

            if (iscycleDFS(adj, v, visited, i)) return true;
        }

        return false;

    }

    bool validTree(int n, vector<vector<int>>& edges) {

        unordered_set<int> visited;
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];

            adj[b].push_back(a);
            adj[a].push_back(b);
        }

        if (iscycleDFS(adj, 0, visited, -1)) return false;

        return visited.size() == n;
    }
};
