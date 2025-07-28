// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).



// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3



#include <bits/stdc++.h>
using namespace std;

void madePrefixSum(vector<int>& arr) {
    int n = arr.size();

    for(int i=1; i<n; i++) {
        arr[i] = arr[i] + arr[i-1];
    }
}

int sumRange(vector<int>& arr, int x, int y) {
    if(x == 0) return arr[y];

    return arr[y] - arr[x-1];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    madePrefixSum(arr);

    int query;
    cin >> query;

    while(query--) {
        int x, y;
        cin >> x >> y;

        cout << sumRange(arr, x, y) << endl;
    }

    return 0;
}