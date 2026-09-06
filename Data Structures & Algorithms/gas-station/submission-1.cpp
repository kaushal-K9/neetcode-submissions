class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        
        int totalCharge = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalCharge < totalCost) return -1;

        int res = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {

            total += gas[i] - cost[i];

            if (total < 0) {
                res = i + 1;
                total = 0;
            }

        }

        return res;
    }
};