class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
                // solve the edge case where if nums[m] == min,
                // and then r = m - 1, we don't record m, so 
                // we need min(res, nums[l]), 
                // then run fully log_2(n) till the end
                res = min(res, nums[l]); 
            if (nums[l] < nums[r]) {
                break;
            }

            int m = (l+r)/2;
            res = min(res, nums[m]);

            if (nums[m] < nums[r]) r = m - 1;
            else l = m + 1;
        }
        return res;
    }
};
