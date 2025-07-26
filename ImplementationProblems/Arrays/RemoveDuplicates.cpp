// Given an array, remove all duplicates and return the array with only unique elements.

// We'll handle:
// 1. Unsorted Array
// 2. Sorted Array


#include <bits/stdc++.h>
using namespace std;

// For unsorted Array -> Brute Force Approach
// vector<int> removeDuplicates(vector<int>& arr) {
//     int n = arr.size();

//     vector<int> res;
//     for(int i=0; i<n; i++) {
//         bool found = false;

//         for(int j=0; j<res.size(); j++) {
//             if(arr[i] == res[j]) {
//                 found = true;
//                 break;
//             }
//         }

//         if(found == false) res.push_back(arr[i]);
//     }

//     return res;
// }


// For unsorted Array -> Optimal Approach
// vector<int> removeDuplicates(vector<int>& arr) {
//     int n = arr.size();
//     unordered_set<int> unique;
//     vector<int> res;

//     for(int i=0; i<n; i++) {
//         if(unique.find(arr[i]) == unique.end()) {
//             unique.insert(arr[i]);
//             res.push_back(arr[i]);
//         }
//     }

//     return res;
// }

// For sorted Array -> Optimal Approach using extra space
// vector<int> removeDuplicates(vector<int>& arr) {
//     set<int> unique(arr.begin(), arr.end());

//     return vector<int>(unique.begin(), unique.end());
// }

// For sorted Array -> Optimal Approach using extra space
vector<int> removeDuplicates(vector<int>& arr) {
    int n = arr.size();
    if(n < 2) return {};

    vector<int> res;

    int i=0, j=1;
    while(i < n-1 || j < n-1) {
        if(arr[i] == arr[j]) {
            res.push_back(arr[i]);
            i=j+1;
            j=i+1;
        } else {
            res.push_back(arr[i]);
            i++;
            j++;
        }
    }

    return res;
}

void printResult(vector<int>& arr) {
    int n = arr.size();
    cout << '[';
    for(int i=0; i<n; i++) {
        cout << arr[i];
        if(i != (n-1)) {
            cout << ",";
        }
    }
    cout << ']' << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }

    vector<int> res = removeDuplicates(arr);

    printResult(res);

    return 0;
}