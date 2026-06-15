class Solution {
public:
    typedef pair<int, int> P;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto &num : nums) {
            mp[num]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto &it : mp) {
            int freq = it.second;
            int value = it.first;

            pq.push({freq, value});

            if (pq.size() > k) pq.pop();
        }

        vector<int> result;
        
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};