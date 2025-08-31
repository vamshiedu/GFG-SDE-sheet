/* Given an array of positive elements arr[] that is sorted and then rotated around an unknown point, 
the task is to check if the array has a pair with sum equals to a given target.

Examples:
    Input: arr[] = [7, 9, 1, 3, 5], target = 6
    Output: true
    Explanation: arr[2] and arr[4] has sum equals to 6 which is equal to the target.
    Input: arr[] = [2, 3, 4, 1], target = 3
    Output: true
    Explanation: arr[0] and arr[3] has sum equals to 3 which is equal to the target.
    Input: arr[] = [10, 7, 4, 1], target = 9
    Output: false
    Explanation: There is no such pair exists in arr[] which sums to target.
Constraints:
    2 <= arr.size() <=106
    1 <= arr[i] <= 106
    1 <= target <= 106

*/

// C++ code to check whether any pair exists
// whose sum is equal to the given target value

#include <iostream>
#include <vector>
#include <unordered_set>
#include<algorithm>
using namespace std;

bool approach1(vector<int> &arr, int target){
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        if (s.find(complement) != s.end())
            return true;
        s.insert(arr[i]);
    }
    return false;
}

bool approach2(vector<int>&arr, int target){
    sort(arr.begin(), arr.end());
        
    int i = 0 , j = arr.size() - 1;
        
    while(i < j){
        int num = arr[i] + arr[j];
        if(num == target){
            return true;
        }else if(num < target){
            i++;
         }else{
            j--;
        }
    }
    return false;
}

bool approach3(vector<int>&arr, int target){
    int n = arr.size();

    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;
    int l = (i + 1) % n;
    int r = i;
    while (l != r) {
        if (arr[l] + arr[r] == target)
            return true;
        if (arr[l] + arr[r] < target)
            l = (l + 1) % n;
        else
            r = (r - 1 + n) % n;
    }
    return false;
}

int main(){
    vector<int> arr = {11, 15, 6, 8, 9, 10};
    int target = 16;
    if (approach1(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}