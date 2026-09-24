class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        //initialize both with frequencies
        //by scanning until length of s1 in both strings
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        //take a count of matches upto now
        int match = 0;

        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i]) match++;
        }

        int l = 0;
        //now we slide a fixed length window over s2
        //and at the end, match should equal 26
        for (int i = s1.length(); i < s2.length(); i++) {

            //preliminary check for early exit
            if (match == 26) return true;


            int idx = s2[i] - 'a';
            //increment the window and check frequency match
            freq2[s2[i] - 'a']++;
            //do we equal the frequency now
            if (freq1[idx] == freq2[idx]) match++;
            //have we disrupted equality by adding one extra
            else if (freq1[idx] + 1 == freq2[idx]) match--;

            //decrement the window from left
            idx = s2[l] - 'a';
            //update the frequency in freq2
            freq2[idx]--;
            if (freq1[idx] == freq2[idx]) match++;
            //have we disrupted equality by removing one more
            else if (freq1[idx] - 1 == freq2[idx]) match--;
            
            //increment left 
            l++;
        }

        return match == 26;
    }
};