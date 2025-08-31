/* Given an array, arr of positive integers. Find the third largest element in it.
 Return -1 if the third largest element is not found.

Examples:

    Input: arr[] = [2, 4, 1, 3, 5]
    Output: 3
    Explanation: The third largest element in the array [2, 4, 1, 3, 5] is 3.

    Input: arr[] = [10, 2]
    Output: -1
    Explanation: There are less than three elements in the array, so the third largest element cannot be determined.

    Input: arr[] = [5, 5, 5]
    Output: 5
    Explanation: In the array [5, 5, 5], the third largest element can be considered 5, as there are no other distinct elements.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
    1 ≤ arr.size ≤ 105
    1 ≤ arr[i] ≤ 105 */

    
#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;


//Brute force : O(nlogn) time complexity and O(1) space complexity.
int approach1(vector<int> &arr) {
    int n = arr.size(); 
    sort(arr.begin(), arr.end());
    return arr[n-3];
}

// Optimal 1 : O(n) time complexity and O(1) space complexity.
int approach2(vector<int>& arr){
    int n = arr.size();
    int first = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > first){
            first = arr[i];
        }
    }

    int second = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > second && arr[i] < first){
            second = arr[i];
        }
    }

    int third = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > third && arr[i] < second){
            third = arr[i];
        }
    }

    return third;

}

// Optimal 2 : O(n) time complexity and O(1) space complexity.
int approach3(vector<int>& arr){
    int n = arr.size();
    if (n < 3) return -1;
        
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        
    for(int i = 0 ; i < n ; i++){
            
        if(arr[i] > first){
                third = second;
                second = first;
                first = arr[i];
        }else if(arr[i] > second){
                third = second;
                second = arr[i];
        }else if(arr[i] > third){
                third = arr[i];
        }
     }

    return (third == INT_MIN) ? -1 : third;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }

        int ans = approach1(arr);

        cout << "Third element is : " << ans << endl;
        
    }
    return 0;
}