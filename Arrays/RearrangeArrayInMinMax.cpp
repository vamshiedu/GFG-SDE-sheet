/* Given an array of positive integers. Your task is to rearrange the array elements alternatively i.e. 
first element should be the max value, the second should be the min value, the third should be the second max, 
the fourth should be the second min, and so on.
Note: Modify the original array itself. Do it without using any extra space. You do not have to return anything.

Examples:

    Input: arr[] = [1, 2, 3, 4, 5, 6]
    Output: [6, 1, 5, 2, 4, 3]
    Explanation: Max element = 6, min = 1, second max = 5, second min = 2, and so on... The modified array is: [6, 1, 5, 2, 4, 3]
    Input: arr[]= [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110]
    Output: [110, 10, 100, 20, 90, 30, 80, 40, 70, 50, 60]
    Explanation: Max element = 110, min = 10, second max = 100, second min = 20, and so on... Modified array is : [110, 10, 100, 20, 90, 30, 80, 40, 70, 50, 60]
    Input: arr[]= [1]
    Output: [1]
Constraints:
    1 ≤ arr.size ≤ 106
    1 ≤ arr[i] ≤ 106
*/


// C++ program to rearrange an array in minimum
// maximum form

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>
#include<queue>
using namespace std;
void appraoch2WithSpace(vector<int>&arr, int n){
    priority_queue<int, vector<int>, greater<int>>minHeap(arr.begin(), arr.end());
    priority_queue<int> maxHeap(arr.begin(), arr.end());
    for(int i = 0 ; i < n ; i = i + 2){
        arr[i] = maxHeap.top();
        maxHeap.pop();
    }
    for(int i = 1 ; i < n ; i = i + 2){
        arr[i] = minHeap.top();
        minHeap.pop();
    }
}


void approach1WithoutSpace(vector<int>& arr, int n)
{
    int max_idx = n - 1, min_idx = 0;
    long long M = arr[n - 1] + 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            arr[i] += (arr[max_idx] % M) * M;
            max_idx--;
        }
        else {
            arr[i] += (arr[min_idx] % M) * M;
            min_idx++;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / M;
}

int main()
{
    vector<int>arr =  { 1, 2, 3, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    approach1WithoutSpace(arr, n);

    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
