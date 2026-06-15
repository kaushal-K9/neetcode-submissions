class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, vector<int>& temp, int idx, int target) {
        if (target < 0) return; 
        
        if (idx >= candidates.size()) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }

        temp.push_back(candidates[idx]);
        solve(candidates, temp, idx, target - candidates[idx]);

        temp.pop_back();
        solve(candidates, temp, idx + 1, target);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        solve(candidates, temp, 0, target);

        return result;
    }
};