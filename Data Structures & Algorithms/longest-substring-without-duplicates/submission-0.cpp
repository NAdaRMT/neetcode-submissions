class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n < 2) return n;
        int maxLength = 1;

        int l = 0;
        int r = 0;

        unordered_set<char> substring;

        while (r < n) {
            if (!substring.count(s[r])) {
                substring.insert(s[r]);
                maxLength = max(maxLength, r - l + 1);
                r++;
            } else {
                substring.erase(s[l]);
                l++;
            } 
        }

        return maxLength;
    }
};
