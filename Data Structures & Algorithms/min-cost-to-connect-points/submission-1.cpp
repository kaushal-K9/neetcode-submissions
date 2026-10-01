class Solution {
public: 
    typedef pair<int, int> P;

    //it does not matter in prims, which node we are starting from
    int prims(vector<vector<P>>& adj, int V) {

        vector<bool> inMST(V, false);
        priority_queue<P, vector<P>, greater<P>> pq;

        //automatically take in the first node in adj
        //{0, 0} represents 
        //starting from node at index 0 in adj
        //therefore, no cost to reach it
        pq.push({0,0});

        int sum = 0;

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();
            
            //pq is meant to be min-heap and 
            //is based on wt
            //therefore, wt = p.first
            int wt = p.first;
            int node = p.second;

            if (inMST[node] == true) continue;

            inMST[node] = true;
            sum += wt;

            for (auto& temp : adj[node]) {

                int neighbor = temp.first;
                int neighbor_wt = temp.second;

                if (inMST[neighbor] == false) {
                    pq.push({neighbor_wt, neighbor});
                }
            }
        }

        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int V = points.size();

        vector<vector<P>> adj(V);
        
        //create an adj list for each node 
        //of style ({node, separation})

        //when you store {j, d} for i
        //also store {i, d} for j
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        return prims(adj, V);
    }
};