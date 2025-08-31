/*
Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.
Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

Examples:
    Input: arr[] = [1, 1, 2, 1, 3, 5, 1]
    Output: 1
    Explanation: Since, 1 is present more than 7/2 times, so it is the majority element.
    Input: arr[] = [7]
    Output: 7
    Explanation: Since, 7 is single element and present more than 1/2 times, so it is the majority element.
    Input: arr[] = [2, 13]
    Output: -1
    Explanation: Since, no element is present more than 2/2 times, so there is no majority element.

Constraints:
    1 ≤ arr.size() ≤ 105
    1 ≤ arr[i] ≤ 105
*/




#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& arr) {
    int n = arr.size();  
    for (int i = 0; i < n; i++) {
        int count = 0; 

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > n / 2) {
            return arr[i]; 
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    
    cout << majorityElement(arr) << endl;

    return 0;
}