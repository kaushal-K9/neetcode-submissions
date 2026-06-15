class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);

        for (char& ch : tasks) {
            mp[ch - 'A']++;
        }

        sort(mp.begin(), mp.end());

        int maxFreq = mp[25];
        int slots = maxFreq - 1;
        int blanks = slots * n;

        for (int i = 24; i >= 0; i--) {
                blanks -= min(mp[i], slots);
        }

        //if we check whether all blanks were utilised, we are not considering 
        //if the blanks became negative in the for loop
        //sometimes blanks > 0 but later subtraction makes them negative
        //which means that, we need to check if they are greater than zero
        //instead of checking if they have become zero

        // if (blanks == 0) return tasks.size();
        // else return blanks + tasks.size();


        if (blanks > 0) {
           return  blanks + tasks.size();
        } 

        return tasks.size();

    }
};