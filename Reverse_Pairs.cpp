/*
Reverse Pairs

Given an integer array nums. Return the number of reverse pairs in the array.



An index pair (i, j) is called a reverse pair if:



0 <= i < j < nums.length


nums[i] > 2 * nums[j]

Example 1

Input: nums = [6, 4, 1, 2, 7]

Output: 3

Explanation:

The reverse pairs are:

(0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1

(0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2

(1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

Example 2

Input: nums = [5, 4, 4, 3, 3]

Output: 0

Explanation:

No pairs satisfy both the conditons.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int>& nums, int low, int mid, int high) {
        int count = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++)
            nums[i] = temp[i - low];

        return count;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += mergeAndCount(nums, low, mid, high);

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {6, 4, 1, 2, 7};  

    Solution obj;
    cout << obj.reversePairs(nums) << endl;

    return 0;
}



