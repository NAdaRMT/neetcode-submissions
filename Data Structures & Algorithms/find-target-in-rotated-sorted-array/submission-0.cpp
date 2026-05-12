class Solution {
private:
    int findOffset(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        int minNum = nums[0];
        int minIdx = 0;
        while (l <= r) {
            if (minNum > nums[l]) {
                minNum = nums[l];
                minIdx = l;
            }

            if (nums[l] < nums[r]) {
                break;
            }
            int m = (l+r)/2;
            if (minNum > nums[m]) {
                minNum = nums[m];
                minIdx = m;
            }
            if (nums[m] < nums[l]) { // 5 1 _2 3 4
                r = m - 1;
            } else {
                l = m + 1;
            } 
        }
        return minIdx;
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        
        int offset = findOffset(nums);

        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l+r)/2;
            int midOffset = (m + offset) % nums.size();

            if (nums[midOffset] == target) return midOffset;

            if (nums[midOffset] < target) l = m + 1;
            else r = m - 1;
        }
        
        return -1;
    }
};
