class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> unique(nums.begin(), nums.end());

        int maxSeq = 0;

        for (int num : unique) {
            if (!unique.contains(num - 1)) {
                int length = 1;
                while (unique.contains(num + length)) length++;
                maxSeq = max(length, maxSeq);
            }
        }

        return maxSeq;
    }
};
