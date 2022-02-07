/*
Leetcode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Time Complexity: O(n) 
Space Complexity: O(1)
*/

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int mini = prices[0], profit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < mini) {
            //buy
            mini = prices[i];
        }
        else {
            //check profit and sell if it's maximum
            profit = max(profit, prices[i] - mini);
        }
    }
    return profit;
}
