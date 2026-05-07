class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int num : nums) {
            if (++map[num] == 2) return true;
        }
        return false;
    }
};