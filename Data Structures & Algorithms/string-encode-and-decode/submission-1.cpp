class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for (string str : strs) {
            encoded_string += to_string(str.length()) + "#" + str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int idx = 0;
        while (idx < s.length()) {
            int strLength = 0;
            while (s[idx] != '#') {
                strLength *= 10;
                strLength += s[idx] - '0';
                idx++;
            }
            idx++;

            string str = "";
            for (int i = 0; i < strLength; i++) {
                str += s[idx];
                idx++;
            }

            decoded.push_back(str);
        }
        return decoded;
    }
};
