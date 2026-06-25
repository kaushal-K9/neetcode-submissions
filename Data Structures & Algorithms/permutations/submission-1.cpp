class Solution {
public:
    vector<vector<int>> result;
    int n;
    unordered_set<int> st;

    void permute(vector<int>& nums, vector<int>& temp) {

        //temp only reaches a size of n when all elements are inserted
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }

        //we always start from the first index on every permute call
        for (int i = 0; i < n; i++) {
            
            //check if element is absent in the current permutation
            if (st.find(nums[i]) == st.end()) {
                
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                permute(nums, temp);

                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        n = nums.size();

        vector<int> temp;

        permute(nums, temp);

        return result;
    }
};