class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for (auto& i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto& i : mp) {
            int value = i.first;
            int freq = i.second;

            pq.push({freq, value});

            if (pq.size() > k) pq.pop();
        
        }

        vector<int> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};