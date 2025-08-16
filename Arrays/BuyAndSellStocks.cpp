/*
Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.
Examples:
    Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
    Output: 8
    Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.
    Input: prices[] = [7, 6, 4, 3, 1]
    Output: 0 
    Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.
    Input: prices[] = [1, 3, 6, 9, 11]
    Output: 10 
    Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].
Constraint:
    1 <= prices.size()<= 10^5
    0 <= prices[i] <=10^4 
*/
#include<iostream>
#include<vector>
using namespace std;
    
//Approach1 brute force O(n^2) time and O(1) space. Gives TLE cause n size is 10^5 and 10^5 * 10^5 is 10^25 needs O(n) solutions;
// by checking all the pairs;

int approach1(vector<int> arr){
    int maxprofit = 0;
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            maxprofit = max(maxprofit, arr[j] - arr[i]);
        }
    }

    return maxprofit;
}

//Approach2 takes O(n) time and O(1) space complexity.
/*we just iterate from 1 to n and keep track of last minimum and substract it with current number to get maxProfit,
we simply minimize the spend and maximize the profit by buying on minimum possible value and selling on max value Greedy approach*/
int approach2(vector<int> arr){
    int maxprofit = 0;
    int currentMin = arr[0];
    int n = arr.size();
    
    for(int i = 1 ; i < n ; i++){
        currentMin = min(currentMin, arr[i]);
        maxprofit = max(maxprofit, arr[i] - currentMin);
    }

    return maxprofit;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr;
        for(int i = 0 ; i < n ; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        int maxProfit = approach1(arr);

        cout << "Max profit is : " << maxProfit << endl;
    }
    return 0;
}