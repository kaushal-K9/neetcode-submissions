class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto& i : nums) {
            mp[i]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);

        for (auto& i : mp) {
            int value = i.first;
            int freq = i.second;

            bucket[freq].push_back(value);
        }

        vector<int> result;

        for (int i = n; i >= 0; i--) {

            if (bucket[i].size() == 0) continue;

            while (bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }

        return result;
    }
};
