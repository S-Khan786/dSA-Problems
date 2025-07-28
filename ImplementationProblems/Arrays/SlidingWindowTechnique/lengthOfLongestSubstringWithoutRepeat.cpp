// Important Question must practice


// Given a string s, find the length of the longest substring without duplicate characters.

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

#include <bits/stdc++.h>
using namespace std;

// int lengthOfLongestSubstring(string s) {
//     int n = s.size();

//     int maxSum = 0;
//     for(int i=0; i<n; i++) {
//         unordered_set<int> seen;
//         for(int j=i; j<n; j++) {
//             if(seen.count(s[j])) break;

//             seen.insert(s[j]);
//             maxSum = max(maxSum, j - i + 1);
//         }
//     }

//     return maxSum;
// }


// Most important one -> Time Complexity -> O(n)
int lengthOfLongestSubstring(string s) {
    int n = s.size();
    unordered_map<char,int> lastIndex;

    int maxLen = 0;
    int left = 0;

    for(int right=0; right<n; right++) {
        char c = s[right];

        if(lastIndex.count(c) and lastIndex[c] >= left) {
            left = lastIndex[c] + 1;
        }

        lastIndex[c] = right;
        maxLen = max(maxLen, right - left + 1);
    }


    return maxLen;
}


int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}