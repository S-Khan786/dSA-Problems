// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]


// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.
 

// When we look at arr[mid]:

// If it's 0 → put it in the 0’s section

// Swap with arr[low]

// Move low++ and mid++

// If it's 1 → it's already in the right place

// Just move mid++

// If it's 2 → put it in the 2’s section

// Swap with arr[high]

// Move high-- (don’t move mid yet, because we need to check the swapped element)


// [ 0s ] [ 1s ] [ unprocessed ] [ 2s ]
//    ↑        ↑             ↑        ↑
//   low      mid                   high

#include <bits/stdc++.h>
using namespace std;

void swapppp(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(vector<int>& arr) {
    int n = arr.size();

    int l = 0, mid = 0, h = n-1;
    while(mid <= h) {
        if(arr[mid] == 0) {
            swapppp(&arr[l], &arr[mid]);
            l++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swapppp(&arr[mid], &arr[h]);
            h--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }


    sortColors(arr);

    cout << "[";
    for(int i=0; i<n; i++) {
        cout << arr[i];
        if(i != n-1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}