/*
Given an array arr of distinct elements, 
the task is to rearrange the elements of the array in a zig-zag fashion 
so that the converted array should be in the below form: 

arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

Note: Modify the given arr[] only, If your transformation is correct, 
the output will be "true" else the output will be "false". 

Examples:
    Input: arr[] = [4, 3, 7, 8, 6, 2, 1]
    Output: true
    Explanation:  After modification the array will look like 3 < 7 > 4 < 8 > 2 < 6 > 1, 
    the checker in the driver code will produce 1.

    Input: arr[] = [4, 7, 3, 8, 2]
    Output: true
    Explanation: After modification the array will look like 4 < 7 > 3 < 8 > 2 hence output will be 1.

    Input: arr[] = [2, 8, 1, 7, 5, 9]
    Output: true
Constraints:
    1 <= arr.size() <= 10^6
    0 <= arri <= 10^8
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


//Approach1 brute force O(n^logn) time and O(1) space. 
// We use sorting technique and swapping adjacent elements to make a < b > c
void approach1(vector<int>& arr){

    sort(arr.begin(), arr.end());

    for(int i = 1 ; i < arr.size() - 1 ; i = i + 2){
        swap(arr[i], arr[i +  1]);
    }
}


//Approach2 optimal approach O(n) time and O(1) space.
//We simply use a flag and arranging triplets we can achieve the conversion. if flag is true we check 
// a < b if not we swap and if flag is false a > b if not we swap then for each triplet it becomes a < b > c;
void approach2(vector<int>& arr){
    bool flag = true;
    int i = 0;
        
    while(i < arr.size()){
        if(flag){
            if(arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
            }
        }else{
            if(arr[i] < arr[i + 1]){
                swap(arr[i], arr[i + 1]);
            }
        }
            
        i = i + 1;
        flag = !flag;
    }

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

        approach1(arr);

        cout << "Conversion is : " << endl;
        for(auto it : arr){
            cout << it << " " ;
        }
        
    }
    return 0;
}