class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);

        for (char c : tasks) {
            mp[c - 'A']++;
        }

        priority_queue<int> pq;

        for (int f : mp) {
            if (f > 0) {
                pq.push(f);
            }
        }

        int time = 0;

        while (!pq.empty()) {
            
            vector<int> temp;

            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (auto& f : temp) {
                if (f > 0) pq.push(f);
            }

            if (pq.empty()) {
                time += temp.size();
            } else {
                time += n + 1;
            }
            
        }

        return time;
    }
};