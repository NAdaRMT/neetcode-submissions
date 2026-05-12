class Solution {
private:
    int countHour(int pile, int& hourlyRate) {
        int count = pile/hourlyRate;
        if (pile % hourlyRate != 0) count++;

        return count;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int maxPile = piles[0];
        for (int i = 1; i < n; i++) {
            if (piles[i] > maxPile) maxPile = piles[i];
        }

        int rate = maxPile;
        int minPile = 1;

        while (minPile <= maxPile) {
            int tempRate = (maxPile + minPile)/2;
            int hourCount = 0;
            for (int pile : piles) hourCount += countHour(pile, tempRate);

            if (hourCount > h) {    // rate too low
                minPile = tempRate + 1;
            } else {                // keep looping for lower rate
                rate = tempRate;
                maxPile = tempRate - 1;
            }
        }

        return rate;
    }
};
