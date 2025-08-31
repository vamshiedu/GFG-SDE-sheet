/*
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
Note: You need to solve this problem without utilizing the built-in sort function.

Examples:

    Input: arr[] = [0, 1, 2, 0, 1, 2]
    Output: [0, 0, 1, 1, 2, 2]
    Explanation: 0s, 1s and 2s are segregated into ascending order.
    Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
    Explanation: 0s, 1s and 2s are segregated into ascending order.
    Follow up: Could you come up with a one-pass algorithm using only constant extra space?

Constraints:
    1 ≤ arr.size() ≤ 106
    0 ≤ arr[i] ≤ 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void approach1(vector<int>& arr){
    sort(arr.begin(), arr.end());
}

void approach2(vector<int> &arr) {
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;
    int mid = 0;
    while (mid <= hi) {
        if (arr[mid] == 0) {
            
            swap(arr[lo++], arr[mid++]);
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[hi--]);
        }
    }
}

int main() {
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();
    
    approach1(arr); 

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}