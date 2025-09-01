/*
You are given an integer array arr[]. You need to find the maximum
sum of a subarray (containing at least one element) in the array arr[].

Note : A subarray is a continuous part of an array.
Examples:
    Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
    Output: 11
    Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
    Input: arr[] = [-2, -4]
    Output: -2
    Explanation: The subarray [-2] has the largest sum -2.
    Input: arr[] = [5, 4, 1, 7, 8]
    Output: 25
    Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
Constraints:
    1 ≤ arr.size() ≤ 10^5
    -10^4 ≤ arr[i] ≤ 10^4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int approach1(vector<int> &arr) {
    int res = arr[0];
  	for(int i = 0; i < arr.size(); i++) {
    	int currSum = 0;
        for(int j = i; j < arr.size(); j++) {
        	currSum = currSum + arr[j];
            res = max(res, currSum);
        }
    }
    return res;
}

int approach2(vector<int>& arr){
    int sum = arr[0];
    int n = arr.size();
    int currSum = arr[0];
        
    for(int i = 1 ; i < n ; i++){
        currSum = max(arr[i], currSum + arr[i]);
        sum = max(sum, currSum);
    }
        
    return sum;
}

int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << approach1(arr);
    return 0;
}