class Solution {
public:
    vector<vector<int>> combinations;

    void getCombo(vector<int>& candidates, int idx, int target, vector<int>& temp) {

        if (target == 0) {
            combinations.push_back(temp);
            return;
        } else if (target < 0 || idx >= candidates.size()) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            //how do we land on this condition?
            if (i > idx && candidates[i] == candidates[i - 1]) {
                //this happens when a call has been made using this element 
                //at this index, and the elements ahead which are 
                //same should get added to the 
                //combinations on their own calls, at their own index
                // not on similar elements call before it
                //as this would allow duplicacy from that index 
                continue;
            }

            //i am taking the current index
            temp.push_back(candidates[i]);

            //call with next index to include it
            getCombo(candidates, i + 1, target - candidates[i], temp);

            //remove the element and try other combination 
            //classic backtracking strategy
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        getCombo(candidates, 0, target, temp);

        return combinations;
    }
};