class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> result;

        sort (points.begin(), points.end(),
        [](auto& a, auto& b) {
            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];

            return distA < distB;
        });

        for (int i = 0; i < k; i++) {
            result.push_back(points[i]);
        }

        return result;

    }
};