class Solution {
public:
    int n;
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int idx, int target, vector<int> temp) {
        
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        if (target < 0 || idx >= n) return;

        temp.push_back(candidates[idx]);
        solve(candidates, idx, target - candidates[idx], temp);

        temp.pop_back();
        solve(candidates, idx + 1, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;

        solve(candidates, 0, target, temp);

        return result;
    }
};