class Solution {
public:
    
    vector<int> temp;

    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = (left + right) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        // already sorted optimization
        if (nums[mid] <= nums[mid + 1]) return;

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            temp[k++] = (nums[i] <= nums[j]) ? nums[i++] : nums[j++];
        }

        while (i <= mid)
            temp[k++] = nums[i++];

        while (j <= right)
            temp[k++] = nums[j++];

        for (int p = left; p <= right; p++)
            nums[p] = temp[p];
    }

    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size());

        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};