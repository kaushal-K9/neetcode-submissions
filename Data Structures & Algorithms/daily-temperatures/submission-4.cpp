class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        vector<int> answer(n, 0);

        if (n == 1) {
            answer[0] = 0;
            return answer;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++){
                if (temperatures[j] > temperatures[i]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }

        return answer;
    }
};