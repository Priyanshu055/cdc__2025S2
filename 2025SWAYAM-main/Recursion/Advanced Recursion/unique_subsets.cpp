#include <bits/stdc++.h>
using namespace std;

void uniqueSubsetsHelper(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& res) {
    // Add current subset to result
    res.push_back(curr);
    
    // Try including each remaining number
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates to ensure uniqueness
        if (i > index && nums[i] == nums[i - 1]) continue;
        
        // Include current number
        curr.push_back(nums[i]);
        // Recursively generate subsets with next index
        uniqueSubsetsHelper(nums, i + 1, curr, res);
        // Backtrack by removing current number
        curr.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(vector<int>& nums) {
    // Sort to handle duplicates
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> curr;
    uniqueSubsetsHelper(nums, 0, curr, res);
    return res;
}

/*
Logic: To generate unique subsets with duplicates:
1. Sort array to group duplicates together
2. Skip duplicates during subset generation
3. Use iterative approach with backtracking

Time Complexity: O(2^n) where n is array length
Space Complexity: O(n) for recursion stack
*/

// Helper function to print vector of vectors
void printSubsets(const vector<vector<int>>& subsets) {
    cout << "{ ";
    for (const auto& subset : subsets) {
        cout << "{";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) cout << ",";
        }
        cout << "} ";
    }
    cout << "}" << endl;
}

int main() {
    // Test cases
    cout << "Test Case 1: [1,2,2]" << endl;
    vector<int> nums1 = {1, 2, 2};
    cout << "Unique subsets: ";
    auto result1 = uniqueSubsets(nums1);
    printSubsets(result1);
    
    cout << "\nTest Case 2: [1,1,1]" << endl;
    vector<int> nums2 = {1, 1, 1};
    cout << "Unique subsets: ";
    auto result2 = uniqueSubsets(nums2);
    printSubsets(result2);
    
    cout << "\nTest Case 3: [1,2,3]" << endl;
    vector<int> nums3 = {1, 2, 3};
    cout << "Unique subsets: ";
    auto result3 = uniqueSubsets(nums3);
    printSubsets(result3);
    
    return 0;
}