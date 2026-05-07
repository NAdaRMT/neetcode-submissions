class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        std::unordered_map<int, int> map;

        int numsLength = nums.size();

        for (int i = 0; i < numsLength; i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < numsLength; i++) {
            int diff = target - nums[i];
            if (map.count(diff) && map[diff] != i) {
                result.push_back(i);
                result.push_back(map[diff]);
                return result;
            }
        }
        return result;
    }
};
