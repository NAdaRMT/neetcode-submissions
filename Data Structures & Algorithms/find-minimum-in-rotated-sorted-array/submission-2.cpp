class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l+r)/2;
            if (nums[l] < nums[r]) return nums[l];  
            else {
                if (m + 1 < nums.size() && nums[m] > nums[m+1]) return nums[m+1];
                if (m - 1 > 0 && nums[m] < nums[m-1]) return nums[m];
                
                if (nums[m] < nums[r]) r = m - 1;
                else l = m + 1;
            }
        }
        return 0;
    }
};
