class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> unique;
        
        for (int num : nums) {
            unique.insert(num);
        }

        int maxSeq = 0;

        for (int num : nums) {
            if (unique.contains(num - 1)) continue;

            int length = 1;
            while (unique.contains(num + length)) length++;
            maxSeq = max(length, maxSeq);
        }

        return maxSeq;
    }
};
