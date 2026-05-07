class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        std::unordered_map<int, vector<string>> map;

        for (string s : strs) {
            vector<int> freqVector(26, 0);
            for (char c : s) {
                freqVector[c - 'a']++;
            }
            int freqRepresentation = 0;
            for (int freq : freqVector) {
                freqRepresentation *= 10;
                freqRepresentation += freq;
            }
            map[freqRepresentation].push_back(s);
        }

        for (auto entry : map) {
            result.push_back(entry.second);
        }

        return result;
    }
};
