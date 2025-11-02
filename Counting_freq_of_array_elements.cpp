/*
Counting Frequencies of Array Elements
Easy

Hints
Given an array nums of size n which may contain duplicate elements, return a list of pairs where each pair contains a unique element from the array and its frequency in the array.



You may return the result in any order, but each element must appear exactly once in the output.


Examples:
Input: nums = [1, 2, 2, 1, 3]

Output: [[1, 2], [2, 2], [3, 1]]

Explanation:

- 1 appears 2 times

- 2 appears 2 times

- 3 appears 1 time

Order of output can vary.

Input: nums = [5, 5, 5, 5]

Output: [[5, 4]]

Explanation:

- 5 appears 4 times.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> countFrequencies(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> ans;
        for (auto& [num, count] : freq) {
            ans.push_back({num, count});
        }

        return ans; 
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 1, 3};
    Solution obj;
    vector<vector<int>> ans = obj.countFrequencies(nums);
    
    for (auto& pair : ans) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
    return 0;
}
