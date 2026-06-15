class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {
        int hourstaken = 0;

        for (auto& i : piles) {
            hourstaken += i/mid;

            if (i % mid != 0) hourstaken++;
        }

        return hourstaken <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; 
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r-l)/2;

        
            if (canEat(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
            

        }

        return l;
    }
};