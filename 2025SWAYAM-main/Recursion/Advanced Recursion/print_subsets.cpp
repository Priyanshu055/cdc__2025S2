#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all subsets
void generateSubsets(string &s, string curr, int index) {
    // Base case: when we reach end of string
    if (index == s.size()) {
        // Print empty subset as "{}" for clarity
        if (curr.empty()) {
            cout << "{} ";
        } else {
            cout << curr << " ";
        }
        return;
    }
    
    // Include current char
    generateSubsets(s, curr + s[index], index + 1);
    // Exclude current char
    generateSubsets(s, curr, index + 1);
}

/*
Logic: For each character in the string, we have two choices:
1. Include it in current subset
2. Exclude it from current subset
This leads to 2^n total subsets where n is string length.

Time Complexity: O(2^n) as we generate all possible subsets
Space Complexity: O(n) for recursion stack depth
*/

int main() {
    // Test cases
    cout << "Test Case 1: abc" << endl;
    string s1 = "abc";
    cout << "All subsets: ";
    generateSubsets(s1, "", 0);
    cout << endl;
    
    cout << "\nTest Case 2: xy" << endl;
    string s2 = "xy";
    cout << "All subsets: ";
    generateSubsets(s2, "", 0);
    cout << endl;
    
    cout << "\nTest Case 3: a" << endl;
    string s3 = "a";
    cout << "All subsets: ";
    generateSubsets(s3, "", 0);
    cout << endl;
    
    return 0;
}