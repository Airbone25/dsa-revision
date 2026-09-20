class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 0;
        int s = 1;
        int maxProfit = 0;

        while(s<prices.size()){
            if(prices[s]>prices[b]){
                int profit = prices[s]-prices[b];
                maxProfit = max(maxProfit,profit);
            }else{
                b = s;
            }
            s++;
        }

        return maxProfit;
    }
};
