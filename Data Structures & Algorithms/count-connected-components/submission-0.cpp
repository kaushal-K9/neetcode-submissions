class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int>& vis) {

        vis[i] = 1;

        for (auto& v : adj[i]) {
            if (!vis[v]) {
                dfs(adj, v, vis);
            }
        }

        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for (auto& e : edges) {
            int a = e[0];
            int b = e[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, i, vis);
                count++;
            }
        }

        return count;
    }
};
