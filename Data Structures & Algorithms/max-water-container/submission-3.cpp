class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int distance = r - l;
        int maxArea = min(heights[l], heights[r]) * distance;
        
        while (l < r) {
            if (heights[r] <= heights[l]) r--;
            else l++;

            if (l >= r) break;

            distance = r - l;
            int tempArea = min(heights[l], heights[r]) * distance;
            if (maxArea < tempArea) maxArea = tempArea;
        }

        
        return maxArea;
    }
};
