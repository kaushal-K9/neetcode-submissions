class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;

        unordered_set<int> st;
        int longest = 1;

        for (int& i : nums) {
            st.insert(i);
        }

        for (auto& i : st) {
            
            if (st.find(i-1) == st.end()) {
                int x = i;
                int count = 1;
                while (st.find(x+1) != st.end()) {
                    x += 1;
                    count += 1;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
