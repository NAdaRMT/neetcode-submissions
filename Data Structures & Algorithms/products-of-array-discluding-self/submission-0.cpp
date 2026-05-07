class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProdLeft(nums.size() + 1, 1);
        vector<int> prefixProdRight(nums.size() + 1, 1);
        for (int i = 1; i < nums.size(); i++) {
            prefixProdLeft[i] *= prefixProdLeft[i - 1] * nums[i - 1];
            prefixProdRight[i] *= prefixProdRight[i - 1] * nums[nums.size() - i];
        }
        
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int prodExceptSelf = prefixProdLeft[i] * prefixProdRight[nums.size() - 1 - i];
            res.push_back(prodExceptSelf);
        }
        return res;
    }
};
