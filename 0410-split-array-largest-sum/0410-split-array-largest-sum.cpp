class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid) {
        int sum = 0;
        int count = 1; // At least one subarray

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) return false;

            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                sum = nums[i];
                count++;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int first = *max_element(nums.begin(), nums.end());
        int last = accumulate(nums.begin(), nums.end(), 0);
        int ans = last; 

        while (first <= last) {
            int mid = first + (last - first) / 2;

            if (isPossible(nums, k, mid)) {
                ans = mid;
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return ans;
    }
};
