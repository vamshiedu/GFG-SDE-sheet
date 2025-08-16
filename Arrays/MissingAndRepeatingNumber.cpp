/*
Given an unsorted array arr[] of size n, containing elements from the range 1 to n, 
it is known that one number in this range is missing, and another number occurs twice in the array, 
find both the duplicate number and the missing number.
Examples:

    Input: arr[] = [2, 2]
    Output: [2, 1]
    Explanation: Repeating number is 2 and the missing number is 1.

    Input: arr[] = [1, 3, 3] 
    Output: [3, 2]
    Explanation: Repeating number is 3 and the missing number is 2.
    Input: arr[] = [4, 3, 6, 2, 1, 1]
    Output: [1, 5]
    Explanation: Repeating number is 1 and the missing number is 5.

Constraints:
    2 ≤ n ≤ 106
    1 ≤ arr[i] ≤ n
*/

#include<iostream>
#include<vector>
using namespace std;

// Approach 1 with O(n) time and O(n) space complexity

/* This takes input array and count frequencies of the elements. if an index has freq 2 its repeating. 
if any index has zero frequency it is missing number.
*/
vector<int> approach1(vector<int> & arr){
    int n = arr.size();
    int missing = -1;
    int repeating = -1;

    vector<int> freq(n+1, 0);
    for(int num : arr){
        freq[num]++;
    }
    
    for(int i = 1 ; i <= n ; i++){
        if(freq[i] == 0){
            missing = i;
        }

        if(freq[i] == 2){
            repeating = i;
        }
    }
    return {missing, repeating};
}


//Appraoch 2 takes O(n) time and O(1) space complexity.

/*The main idea is to use the input array itself for tracking: it negates the value at the index corresponding to each element to mark it as visited. If it encounters a value that has already been negated, it identifies that number as the repeating one. In a second pass, it finds the index that remains positive, which corresponds to the missing number. */
vector<int> approach2(vector<int>& arr) {
    int missing = -1, repeating = -1;
    int n = arr.size();
       
    for(int i = 0 ; i < n ; i++){
        int num = abs(arr[i]);
           
        if(arr[num - 1] > 0){
            arr[num - 1] = -arr[num - 1];
        }else{
             repeating = num;
        }
    } 
       
    for(int i = 1 ; i <= n ; i++){
        if(arr[i - 1] > 0){
            missing = i;
        }
    }
       
    return {missing, repeating};
}

//Approach3 takes O(n) time and O(1) space complexity.

/*The idea is to use mathematical equations based on the sum and sum of squares of numbers from 1 to n. The difference between expected and actual sums will give us one equation, and the difference between expected and actual sum of squares will give us another equation. Solving these equations yields our missing and repeating numbers.
*/
vector<int> approach3(vector<int>& arr) {
    int repeating = -1, missing = -1;
    int n = arr.size();

    int actualSum = (n*(n + 1)) / 2;
    int actualSumOfPowers = (n*(n + 1)*(2*n + 1))/6;
    for(int i = 1 ; i <= arr.size() ; i++){
        actualSum -= arr[i - 1];
        actualSumOfPowers -= arr[i - 1] * arr[i - 1];
    }

    missing = (actualSum + actualSumOfPowers / actualSum) / 2;
    repeating = (missing  - actualSum);

    return {missing, repeating};
}

//Approach4 takes O(n) time and O(1) space complexity.
/*The idea is to use XOR operations to isolate the missing and repeating numbers. By XORing all array elements with numbers 1 to n, we get the XOR of our missing and repeating numbers. Then, using a set bit in this XOR result, we can divide all numbers into two groups, which helps us separate the missing and repeating numbers.*/



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

        vector<int> ans = approach3(arr);

        cout << "Missing is : " << ans[0] << endl;
        cout << "Repeating is : " << ans[1] << endl;
    }
    return 0;
}