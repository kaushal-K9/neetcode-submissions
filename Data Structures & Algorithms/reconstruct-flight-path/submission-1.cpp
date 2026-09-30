class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> result;

    void DFS(const string& city) {
        while (!adj[city].empty()) {
            auto it = adj[city].begin();

            string next = *it;
            adj[city].erase(it);

            DFS(next);
        }

        result.push_back(city);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        DFS("JFK");

        reverse(result.begin(), result.end());

        return result;
    }
};
