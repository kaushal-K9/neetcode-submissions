class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> deq;

        vector<int> result;

        for (int i = 0; i < n; i++) {

            //make space for nums[i]
            while (!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            //make sure the largest element index remains in the front of
            //deq, but we pop from back first
            while (!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            //push the larger element, which should now be at the front
            //upon insertion
            deq.push_back(i);

            //record the front of deq as soon as we hit a valid window size
            if (i >= k - 1) {
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};