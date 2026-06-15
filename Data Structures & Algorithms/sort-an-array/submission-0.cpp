class Solution {
public:

    void merge(vector<int>& nums, int s, int e){

        int mid = s + (e - s)/2;

        //copy left array to a new one
        int l1 = mid - s + 1;
        int* left = new int[l1];  
        int mainArrayIndex = s;

        for (int i = 0; i < l1; i++) {
            left[i] = nums[mainArrayIndex++];
        }

        //copy right array to a new one
        int l2 = e - mid;
        int* right = new int[l2];
        mainArrayIndex = mid + 1;

        for (int i = 0; i < l2; i++) {
            right[i] = nums[mainArrayIndex++];
        }

        //merge both sorted arrays into one
        int indexLeft = 0;
        int indexRight = 0;
        mainArrayIndex = s;

        while (indexLeft < l1 && indexRight < l2) {
            if (left[indexLeft] < right[indexRight]) {
                nums[mainArrayIndex++] = left[indexLeft++];
            } else {
                nums[mainArrayIndex++] = right[indexRight++];
            }
        }

        //fill with remaining elements from any of the arrays
        while (indexLeft < l1) {
            nums[mainArrayIndex++] = left[indexLeft++];
        }

        while (indexRight < l2) {
            nums[mainArrayIndex++] = right[indexRight++];
        }
    }


    void mergeSort(vector<int>& nums, int s, int e) {
        
        //base case, only one element remaining in the array
        if (s >= e) return;

        //find the index to split the array
        int mid = s + (e-s)/2;

        //call mergesort on left half
        mergeSort(nums, s, mid);

        //call mergesort on right half
        mergeSort(nums, mid + 1, e);

        //merge the sorted arrays
        merge(nums, s, e);
    }


    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        mergeSort(nums, s, e);

        return nums;
    }
};