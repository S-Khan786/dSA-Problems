// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

#include <bits/stdc++.h>
using namespace std;

// When we have sorted array then in that case we use two pointer technique
// When we have unsorted array then in that case we use hashing(hashmap) technique




// Two pointer technique for sorted array
// vector<int> twoSum(int* arr, int n, int target) {  
//     int start = 0, end = n - 1;

//     while(start < end) {
//         int sum = arr[start] + arr[end];

//         if(sum == target) {
//             return {start, end};
//         } else if(sum > target) {
//             end--;
//         } else {
//             start++;
//         }
//     }

//     return {};
// }




// hashmap technique when we have array, and it is not sorted
vector<int> twoSum(int* arr, int n, int target) {
    unordered_map<int, int> findMap;

    for(int i=0; i<n; i++) {
        if(findMap.find(target - arr[i]) != findMap.end()) {
            return {findMap[target - arr[i]], i};
        }
        findMap[arr[i]] = i;
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr[i] = x;
    }

    int target;
    cin >> target;

    vector<int> res = twoSum(arr, n, target);

    cout << "[";
    for(int i=0; i<res.size(); i++) {
        cout << res[i];
        if(i != (res.size() - 1)) {
            cout << ",";
        }
    }
    cout << "]" << endl;
 
    return 0;
}