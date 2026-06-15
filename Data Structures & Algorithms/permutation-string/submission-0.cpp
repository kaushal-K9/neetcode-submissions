class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);
        int k = s1.size();

        // count frequency of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s2.size(); right++) {
            // add current character to window
            freq2[s2[right] - 'a']++;

            // maintain fixed window size
            if (right - left + 1 > k) {
                freq2[s2[left] - 'a']--;
                left++;
            }

            // check permutation
            if (freq1 == freq2) return true;
        }

        return false;
    }
};
