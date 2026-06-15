class Solution {
public:
    int partition(vector<int>& nums, int L, int R) {
        int pivot = nums[L];
        int i = L + 1; //we add 1 to make sure single element array is safe op
        int j = R;

        while (i <= j) {
            if (nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++; j--;
            }

            if (nums[i] >= pivot) i++;
            if (nums[j] <= pivot) j--;

        }

        swap(nums[L], nums[j]);

        return j;

    }
    int findKthLargest(vector<int>& nums, int k) {
        int L = 0;
        int R = nums.size() - 1;

        int pivot_idx = 0;

        while (true) {

            pivot_idx = partition(nums, L, R);

            if (pivot_idx == k - 1) break;
            else if (pivot_idx > k - 1) {
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
        }

        return nums[pivot_idx];
    }
};