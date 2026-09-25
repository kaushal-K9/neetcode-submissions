class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int req = t.length();

        unordered_map<int, int> mp;

        //initialize the map with required chars in t
        //this lets us count duplicates as well
        for (auto& c : t) {
            mp[c - 'A'] += 1;
        }

        int i = 0, j = 0, startIdx = 0;
        int windowSize = INT_MAX;

        while (j < n) {
            
            //increment j until we reduce required to zero
            //we reduce to zero only if we encounter
            //a key with value greater than zero
            while (req > 0 && j < n) {

                int letter = s[j] - 'A';    

                //stumble upon a non-required character from s
                //make their count negative
                //else decrement count of required and also 
                //the variable req

                if (mp[letter] > 0) {
                    req--;
                }
                mp[letter]--;
                j++;
            }

            //try to shrink window from left and increment required count
            while (req == 0) {

                if (j - i < windowSize) {
                    windowSize = j - i;
                    startIdx = i;
                }

                int letter = s[i] - 'A';

                //increment the current requirement as we are about
                //to remove it from window on the left
                mp[letter] += 1;

                //detect letters that are now required since they
                //will be out of the window
                if (mp[letter] > 0) req++;

                i++;

            }

        }   

        return windowSize == INT_MAX? "" : s.substr(startIdx, windowSize);
    }
};