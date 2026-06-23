class Solution {
public:
    vector<vector<int>> combinations;

    void getCombo(vector<int>& candidates, int i, int target, vector<int>& temp) {

        if (target == 0) {
            combinations.push_back(temp);
            return;
        } else if (target < 0 || i >= candidates.size()) {
            return;
        }

        //keep pushing the current element until target is achieved
        temp.push_back(candidates[i]);
        getCombo(candidates, i, target - candidates[i], temp);

        //do not take this element and move ahead instead
        temp.pop_back();
        getCombo(candidates, i + 1, target, temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> temp;

        getCombo(candidates, 0, target, temp);

        return combinations;
    }
};