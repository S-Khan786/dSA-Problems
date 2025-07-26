// What is a Palindrome?
// A palindrome is a string that reads the same forward and backward.

// Examples:
// String	Palindrome?
// "madam"	✅ Yes
// "racecar"	✅ Yes
// "hello"	❌ No
// "121"	✅ Yes
// "12321"	✅ Yes


#include <bits/stdc++.h>
using namespace std;

// Uses extra space
// bool checkPalindrome(string& s) {
//     int n = s.size();

//     string rev = s;
//     reverse(rev.begin(), rev.end());

//     return s == rev;
// }

// not uses extra space
bool checkPalindrome(string& s) {
    int n = s.size();

    int i=0, j=n-1;
    while(i < j) {
        if(s[i] != s[j]) {
            return false;
        } 
        i++;
        j--;
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    string res = checkPalindrome(s) ? "Yes" : "No";

    cout << res << endl;

    return 0;
}