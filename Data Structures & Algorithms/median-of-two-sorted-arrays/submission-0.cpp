class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0;
        int j = 0;
        int k = 0;

        int size = m + n;

        int idx1 = size/2;
        int elm1 = 0;

        int idx2 = size/2 - 1;
        int elm2 = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (k == idx1) {
                    elm1 = nums1[i];
                } 
                if (k == idx2) {
                    elm2 = nums1[i];
                }
                i++;
            } else {
                if (k == idx1) {
                    elm1 = nums2[j];
                } 
                if (k == idx2) {
                    elm2 = nums2[j];
                }
                j++;
            }
            k++;
        } 

        while (i < m) {
            if (k == idx1) {
                elm1 = nums1[i];
            }
            if (k == idx2) {
                elm2 = nums1[i];
            }
            i++;
            k++;
        } 

        while (j < n) {
            if (k == idx1) {
                elm1 = nums2[j];
            }
            if (k == idx2) {
                elm2 = nums2[j];
            }
            j++;
            k++;
        }

        if ((m + n)%2 == 1) {
            return elm1;
        } else {
            return (elm1 + elm2)/2.0;
        }
    }
};