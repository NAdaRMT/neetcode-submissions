class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        // temp, index
        stack<pair<int, int>> st;

        for (size_t i = 0; i < temperatures.size(); i++) {
            // the first st.top() has temperatures[i-1]
            // the rest st.top() always has the lowest 
            // temperature that hasn't found next higher day 
            // because if in the stack it's not the lowest, 
            // it would have been poped already.
            // so we keep checking if the current temp[i] 
            // is higher than any before and pop() them and update

            while (!st.empty() && temperatures[i] > st.top().first) {
                pair<int, int> tempPair = st.top();
                st.pop();
                res[tempPair.second] = i - tempPair.second;
            }

            st.push(pair<int, int> (temperatures[i], i));
        }

        return res;
    }
};
