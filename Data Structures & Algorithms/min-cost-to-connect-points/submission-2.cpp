class Solution {
public: 

    class DSU {
        public:

        vector<int> parent;
        vector<int> rank;

        //constructor for DSU class
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            //nodes are now represented by a single index
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x) return x;

            //path compression 

            //we set parent of x as the node
            //that is parent of parent of x
            return parent[x] = find(parent[x]);
        }

        bool unite(int a, int b) {
            int parent_a = find(a);
            int parent_b = find(b);

            //already connected
            if (parent_a == parent_b) {
                //we do not want to add this connecting edge
                return false;
            }

            //rank comparison
            if (rank[parent_a] < rank[parent_b]) {
                parent[parent_a] = parent_b;
            } else if (rank[parent_a] > rank[parent_b]) {
                parent[parent_b] = parent_a;
            } else {
                parent[parent_b] = parent_a;
                rank[parent_a]++;
            }
            return true;
        }
    };

    struct Edge {
        int u;
        int v;
        int cost;

        bool operator < (const Edge& other) const {
            return cost < other.cost; 
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<Edge> edges;

        //generating all possible edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int cost = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({i, j, cost});
            }
        }

            //sort the edges in ascending order
        sort(edges.begin(), edges.end());
        
        DSU dsu(n);

        int totalCost = 0; 
        int edgesUsed = 0;

        for (auto& edge : edges) {
            if (dsu.unite(edge.u, edge.v)) {
                totalCost  += edge.cost;
                edgesUsed++;

                if (edgesUsed == n - 1) break;
            }
        }

        return totalCost;
    }
};