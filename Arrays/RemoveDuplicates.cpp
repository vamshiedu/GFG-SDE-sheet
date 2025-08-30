/*
you are given a sorted array arr[] containing positive integers. Your task is to remove all duplicate elements from this array such that each element appears only once. Return an array containing these distinct elements in the same order as they appeared.
Examples :

    Input: arr[] = [2, 2, 2, 2, 2]
    Output: [2]
    Explanation: After removing all the duplicates only one instance of 2 will remain i.e. [2] so modified array will contains 2 at first position and you should return array containing [2] after modifying the array.
    Input: arr[] = [1, 2, 4]
    Output: [1, 2, 4]
    Explation:  As the array does not contain any duplicates so you should return [1, 2, 4].

Constraints:
    1 ≤ arr.size() ≤ 105
    1 ≤ arr[i] ≤ 106
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;
// Approach1 O(n) time and O(n) space complexity
/* We simply store all elements in a set with discards duplicates by its nature in cpp and copy
 them into vector and return it.
*/
vector<int> approach1(vector<int> arr){
    set<int> st(arr.begin(), arr.end());
    vector<int> ans(st.begin(), st.end());
    return ans;
}

// Approach1 O(n) time and O(1) space complexity
/* We use 2 pointers approach to keep track of last unique element and go forward to put next unique element after it.
*/
vector<int> approach2(vector<int> arr){
    int j = 0;
    int n = arr.size();
    for(int i = 1 ; i < n ; i++){
        if(arr[i] != arr[j]){
            arr[j + 1] = arr[i];
            j++;
        }
    }
    vector<int> ans(arr.begin(), arr.begin() + j + 1);
    return ans;
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

        vector<int> ans = approach2(arr);

        for(int i = 0 ; i < ans.size() ; i++){
            cout << ans[i] << " ";            
        }
    }
    return 0;
}