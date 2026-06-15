class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> freq1(26, 0), freq2(26,0);

        for (auto c : s1) {
            freq1[c - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) { //match all zeroes of s1 to s2
            if (freq1[i] == freq2[i]) matches++;
        }

        int left = 0;
        int k = s1.size();

        for (int right = 0; right < s2.size(); right++) {

            int r = s2[right] - 'a';
            freq2[r]++;

            if (freq1[r] == freq2[r]) matches++; //an exisitng char in s1 added added to window from s2
            else if (freq2[r] == freq1[r] + 1) matches--; //unwanted char disturbs matching zero frequencies

            if (right - left + 1 > k) {

                int l = s2[left] - 'a';
                freq2[l]--; //remove from left of window in s2

                if (freq2[l] == freq1[l]) matches++; //if frequency matches for that index, we removed and unwanted char
                else if (freq2[l] == freq1[l] -1) matches --; //else we have removed a wanted char of s1 from window

                left++;
            }

            if (matches == 26) return true; //finally all frequencies should match
        }

        return false;

    }
};