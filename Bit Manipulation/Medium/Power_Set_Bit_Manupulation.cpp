/*
Power Set Bit Manipulation

Given an array of integers nums of unique elements. Return all possible subsets (power set) of the array.



Do not include the duplicates in the answer.


Example 1

Input : nums = [1, 2, 3]

Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

Example 2

Input : nums = [1, 2]

Output : [ [ ] , [1] , [2] , [1, 2] ]
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> powerSet(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;
        
        vector<vector<int>> result;

        for(int mask = 0; mask < total; mask++) {
            vector<int> subset;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            result.push_back(subset);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution obj;
    vector<vector<int>> ans = obj.powerSet(nums);

    cout << "Power Set:\n";
    for(auto subset : ans) {
        cout << "[ ";
        for(auto x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}