class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        for (auto& num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;

        unordered_set<int> st;
        st.insert(0);

        for (int i = n - 1; i >= 0; i--) {
            
            unordered_set<int> temp = st;

            for(auto& k : st) {
                temp.insert(k + nums[i]);
            }

            st = temp;

            if (st.find(sum / 2) != st.end()) return true;

        }

        return false;

    }
};