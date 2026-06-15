class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        if (nums.size() == 0) return 0;
        int longest = 1;

        for (int i : nums) {
            st.insert(i);
        }

        for (auto i : st) {
            if (st.find(i-1) == st.end()) {
                int x = i;
                int count = 1;
                while (st.find(x+1) != st.end()) {
                    x = x+1;
                    count = count+1;
                }

                longest = max(count, longest);
            }
        }

        return longest;
    }
};