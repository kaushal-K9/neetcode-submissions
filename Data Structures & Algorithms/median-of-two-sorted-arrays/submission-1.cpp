class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        //assign for the lower sized array
        int low = 0, high = n1;

        //count the number of elements needed on left of symmetry
        //if total is odd, left half has more elements
        //ex. n1 = 5, n2 = 4, then left = 5 elements
        //and median = max(l1, l2); the 5th element on left
        int left = (n1 + n2 + 1)/ 2;

        //total size to get median calculation
        int n = n1 + n2;

        while (low <= high) {
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;

            //initially smaller if not present
            int l1 = INT_MIN, l2 = INT_MIN;
            //initially larger if not present
            int r1 = INT_MAX, r2 = INT_MAX;

            //we cannot pick more elements from a vector than it has
            //mid1 represnts the index that is one greater than
            //the elements of nums1 on the left
            //ex. (elements of nums1 on left | mid1)
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];

            //if mid1 falls so far to the left in iteration
            //that mid1 - 1 < 0, we cant pick any left elements
            //from nums1
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            //have we satisfied the condition?
            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2))/2.0;
            } else {
                if (l1 > r2) {
                    high = mid1 - 1;
                } else {
                    low = mid1 + 1;
                }
            }
        }

        //dummy return 
        return 0;
    }
};