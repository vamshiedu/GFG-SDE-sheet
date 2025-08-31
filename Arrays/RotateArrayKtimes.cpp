/*
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, 
where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.
Examples :

    Input: arr[] = [1, 2, 3, 4, 5], d = 2
    Output: [3, 4, 5, 1, 2]
    Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
    Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
    Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
    Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
    Input: arr[] = [7, 3, 9, 1], d = 9
    Output: [3, 9, 1, 7]
    Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
Constraints:
    1 <= arr.size(), d <= 105
    0 <= arr[i] <= 105
*/



#include<iostream>
#include<vector>

using namespace std;

void approach1(vector<int>& arr, int d) {
    int n = arr.size();
    for (int i = 0; i < d; i++) {
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

void approach2(vector<int>&arr, int d){
    d = d % arr.size();

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d + 1, arr.end());
    reverse(arr.begin(), arr.end());
}
int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;
    approach1(arr, d);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}