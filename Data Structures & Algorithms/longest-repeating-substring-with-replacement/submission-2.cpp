class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = 0;

        int l = 0, r = 0;
        vector<int> freq(26, 0);
        int maxfreq = 0;
        int maxlen = 0;

        while (r < s.length()) {
            
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            //move left to accomodate max recorded window size
            //along with the valid equation
            if ((r - l + 1) - maxfreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
        
            res = max(res, (r - l + 1));
            r++;
        }

        return res;
    }
};