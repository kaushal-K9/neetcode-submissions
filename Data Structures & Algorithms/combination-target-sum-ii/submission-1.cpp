class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, vector<int>& temp, int idx, int target) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

       for (int i = idx; i < candidates.size(); i++) {

            if (i> idx && candidates[i] == candidates[i-1]) continue;

            if (candidates[i] > target) continue;

            temp.push_back(candidates[i]);
            solve(candidates, temp, i + 1, target - candidates[i]);
            temp.pop_back();
       }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        
        sort(candidates.begin(), candidates.end());
        vector<int> temp;

        solve(candidates, temp, 0, target);

        return result;
    }
};