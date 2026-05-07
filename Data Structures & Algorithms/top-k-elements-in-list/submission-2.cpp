class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        int mapSize = nums.size();
        
        vector<vector<int>> buckets(mapSize + 1);

        for (auto entry : map) {
            buckets[entry.second].push_back(entry.first);
        }

        vector<int> result;

        for (int i = buckets.size() - 1; i >= 0; i--){
            while (!buckets[i].empty() && result.size() < k) { 
                result.push_back(buckets[i].back()); 
                buckets[i].pop_back();
            }
            if (result.size() == k) break;
        }

        return result;
    }
};
