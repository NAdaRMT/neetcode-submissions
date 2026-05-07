class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.length() - 1;
        while (front <= back) {
            while (front < back && !isalnum(s[front])) front++;
            while (back > front && !isalnum(s[back])) back--;
            if (towupper(s[front]) != towupper(s[back])) return false;
            front++;
            back--;
        }
        return true;
    }
};
