class Solution {
public:
    bool canEat(vector<int>& piles, int mid, int h) {

        int hoursTaken = 0;

        for (auto& p : piles) {
            hoursTaken += (p/ mid);

            if (p % mid != 0) hoursTaken++;
        }

        //letting higher rates of eating qualify
        return hoursTaken <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l < r) {
            int mid = l + (r - l)/ 2;
            
            if (canEat(piles, mid, h)) {
                //r inches closer to the lesser values possible
                r = mid;
            } else {
                //we have a hit a very low rate, go one step ahead
                l = mid + 1;
            }
        }

        //r locks at qualifying rates of mid
        //l advances from not qualifying rates by 1
        //at the end when l == r, we have arrived at our mid
        return r;
        //return l; also works

    }
};