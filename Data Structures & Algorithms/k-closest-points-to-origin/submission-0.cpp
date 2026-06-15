class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for (auto& p : points) {
            int a = p[0];
            int b = p[1];

            int dist = a*a + b*b;

            pq.push({dist, p});

            if (pq.size() > k) pq.pop(); //farthest distance bubbles to the top
        }

        vector<vector<int>> ans;
        
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};