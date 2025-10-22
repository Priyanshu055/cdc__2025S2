#include <bits/stdc++.h>
using namespace std;

void permute(string &s, int l, int r) {
    // Base case: if we've reached the end of string
    if (l == r) {
        cout << s << " ";
        return;
    }
    
    // Try all possible characters at current position
    for (int i = l; i <= r; i++) {
        // Place current char at position l
        swap(s[l], s[i]);
        // Recursively generate permutations for rest
        permute(s, l + 1, r);
        // Backtrack by restoring original string
        swap(s[l], s[i]);
    }
}

/*
Logic: For generating permutations:
1. Fix each character at current position
2. Recursively generate permutations of remaining chars
3. Backtrack by restoring original string
This generates all n! permutations.

Time Complexity: O(n!) as we generate all permutations
Space Complexity: O(n) for recursion depth
*/

int main() {
    // Test cases
    cout << "Test Case 1: abc" << endl;
    string s1 = "abc";
    cout << "All permutations: ";
    permute(s1, 0, s1.length() - 1);
    cout << endl;
    
    cout << "\nTest Case 2: xy" << endl;
    string s2 = "xy";
    cout << "All permutations: ";
    permute(s2, 0, s2.length() - 1);
    cout << endl;
    
    cout << "\nTest Case 3: a" << endl;
    string s3 = "a";
    cout << "All permutations: ";
    permute(s3, 0, s3.length() - 1);
    cout << endl;
    
    return 0;
}