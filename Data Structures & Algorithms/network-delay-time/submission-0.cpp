class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adj;

        //create an adjacency list of type
        // node -> {target(node), dist} from itself
        for (auto& vec : times) {
            int node = vec[0];
            int target = vec[1];
            int dist = vec[2];

            adj[node].push_back({target, dist});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        //a result stores the min distance of each node from source
        vector<int> result(n + 1, INT_MAX);

        //distance of target from itself is zero
        result[k] = 0;
        //saved as {dist, targetNode} in priority queue
        pq.push({0, k});

        while (!pq.empty()) {
            //distance from the source for this node is d
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (d > result[node]) continue;

            for (auto& neighbor : adj[node]) {

                int adjNode = neighbor.first;
                //distance from the node to adjNode is dist
                int dist = neighbor.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

        int ans = *max_element(result.begin() + 1, result.end());

        return ans == INT_MAX? -1 : ans;
    }
};