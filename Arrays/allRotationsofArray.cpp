/*
Given an integer array arr[]. Find the maximum value of the sum of i*arr[i]
 for all 0 ≤ i ≤ arr.size()-1. The only operation allowed is to rotate(clockwise or counterclockwise) the array any number of times.

Examples :
    Input: arr[] = [8, 3, 1, 2]
    Output: 29
    Explanation: Out of all the possible configurations by rotating the elements: arr[] = [3, 1, 2, 8] here (3*0) + (1*1) + (2*2) + (8*3) = 29 is maximum.
    Input: arr[] = [1, 2, 3]
    Output: 8
    Explanation: Out of all the possible configurations by rotating the elements: arr[] = [1, 2, 3] here (1*0) + (2*1) + (3*2) = 8 is maximum.
    Input: arr[] = [4, 13]
    Output: 13
Constraints:
    1 ≤ arr.size() ≤ 104
    1 ≤ arr[i] ≤ 20
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int approach1(vector<int> &arr) {
    int n = arr.size();
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int index = (i + j) % n;
            sum += j * arr[index];
        }
        res = max(res, sum);
    }

    return res;
}


int approach2(vector<int> &arr) {
    
    int n = arr.size();
    int curSum = 0;
    for (int i = 0; i < n; i++)
        curSum += arr[i];
    int currVal = 0;
    for (int i = 0; i < n; i++)
        currVal += i * arr[i] ;
    int res = currVal ;
    for (int i = 1; i < n; i++) {
        int nextVal = currVal - (curSum - arr[i - 1]) + 
                        arr[i - 1] * (n - 1);

        currVal = nextVal;
        res = max(res, nextVal);
    }

    return res;
}


int main() {
    vector<int> arr = {8, 3, 1, 2};
    cout << approach1(arr);
    return 0;
}