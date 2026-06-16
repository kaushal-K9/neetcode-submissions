class Solution {
public:

    //how to prove if there exists a duplicate in the nums?
    //we calculate n(n+1)/2 for the range, if sum is more than it
    //a duplicate number exists that is increasing the sum

    int findDuplicate(vector<int>& nums) {
        
        //l1 = distance before loop entry
        //l2 = distance after loop entry to meeting point
        //slow = l1 + l2 
        //fast = l1 + l2 + nK (K = length of circle)
        // 2(l1 + l2) = l1 + l2 + nK
        // l1 = nK - l2

        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        //fast moves at 2x speed of slow
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];    
        }

        slow = nums[0];

        //fast and slow move by one
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};