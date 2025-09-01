/*
Given an array of integers arr[] representing a permutation,
 implement the next permutation that rearranges the numbers into the lexicographically 
 next greater permutation. If no such permutation exists, 
 rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
Note:  A permutation of an array of integers refers to a specific arrangement of its elements
 in a sequence or linear order.

Examples:
    Input: arr[] = [2, 4, 1, 7, 5, 0]
    Output: [2, 4, 5, 0, 1, 7]
    Explanation: The next permutation of the given array is [2, 4, 5, 0, 1, 7].
    Input: arr[] = [3, 2, 1]
    Output: [1, 2, 3]
    Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
    Input: arr[] = [3, 4, 2, 5, 1]
    Output: [3, 4, 5, 1, 2]
    Explanation: The next permutation of the given array is [3, 4, 5, 1, 2].
Constraints:
    1 ≤ arr.size() ≤ 10^5
    0 ≤ arr[i] ≤ 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<vector<int>> &res, vector<int> &arr, int idx) {
    if (idx == arr.size() - 1) {
        res.push_back(arr);
        return;
    }
    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        helper(res, arr, idx + 1);
        swap(arr[idx], arr[i]);
    }
}
void approach1(vector<int>& arr) {
    vector<vector<int>> res;
    helper(res, arr, 0);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == arr) {
            if (i < res.size() - 1) {
                arr = res[i + 1];
            }
            else {
                arr = res[0];
            }
            break;
        }
    }
}


void approach2(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end());
}



void approach3(vector<int> &arr) {
    int n = arr.size(); 
    int pivot = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            pivot = i;
            break;
        }
    }
    if (pivot == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]);
            break;
        }
    }
    reverse(arr.begin() + pivot + 1, arr.end());
}


int main() {
    vector<int> arr = {2, 4, 1, 7, 5, 0};
    approach1(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}