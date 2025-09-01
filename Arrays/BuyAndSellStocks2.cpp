/*
The cost of stock on each day is given in an array price[]. 
Each day you may decide to either buy or sell the stock i at price[i], 
you can even buy and sell the stock on the same day. Find the maximum profit that you can get.
Note: A stock can only be sold if it has been bought previously 
and multiple stocks cannot be held on any given day.
Examples:
    Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
    Output: 865
    Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210.
    Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.
    Input: prices[] = [4, 2, 2, 2, 4]
    Output: 2
    Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2. Maximum Profit = 2.

Constraints:
    1 <= prices.size() <= 105
    0 <= prices[i] <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> &price, int start, int end) {
    int res = 0;
    for (int i = start; i < end; i++) {
        for (int j = i + 1; j <= end; j++) {
            if (price[j] > price[i]) {
                int curr = (price[j] - price[i]) + 
                            helper(price, start, i - 1) + 
                  			helper(price, j + 1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}
int approach1(vector<int> &prices) {
    return helper(prices, 0, prices.size()-1);
}



int approach2(vector<int>&prices){
    int n = prices.size();
    int maxProfit = 0;
        
    for(int i = 1 ; i < n ; i++){
        if(prices[i] > prices[i - 1]){
            maxProfit += prices[i] - prices[i - 1];
        }
    }
        
    return maxProfit;
}



int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << approach1(prices);
    return 0;
}