// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.


// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

int maxSubarray(vector<int>& arr) {
    int n = arr.size();

    int maxmSum = 0, currSum = 0;
    for(int i=0; i<n; i++) {
        currSum += arr[i];

        if(currSum < 0) {
            currSum = 0;
        }

        maxmSum = max(currSum, maxmSum);
    }

    return maxmSum;
}


int main() {
    int n;
    cin >> n;
    vector<int> arr;
    
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }


    cout << maxSubarray(arr) << endl;

    return 0;
}