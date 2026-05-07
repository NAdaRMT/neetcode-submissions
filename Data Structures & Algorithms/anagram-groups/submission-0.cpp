class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        std::unordered_map<string, vector<string>> map;

        vector<string> sortedString;

        for (string s : strs) {
            string tempString = s;
            sort(tempString.begin(), tempString.end());
            map[tempString].push_back(s);
        }

        for(auto entry : map) {
            result.push_back(entry.second);
        }

        return result;
    }
};
