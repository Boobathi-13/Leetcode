#include <algorithm> // For std::max
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(auto price : prices){
            if(price<minPrice) minPrice = price;
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};