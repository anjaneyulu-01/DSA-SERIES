/*
Quick Sorting

Easy

Given an array of integers called nums, sort the array in non-decreasing order using the quick sort algorithm and return the sorted array.



A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.


Examples:
Input: nums = [7, 4, 1, 5, 3]

Output: [1, 3, 4, 5, 7]

Explanation: 1 <= 3 <= 4 <= 5 <= 7.

Thus the array is sorted in non-decreasing order.

Input: nums = [5, 4, 4, 1, 1]

Output: [1, 1, 4, 4, 5]

Explanation: 1 <= 1 <= 4 <= 4 <= 5.

Thus the array is sorted in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high]; 
        int i = low - 1;      
 for (int j = low; j < high; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]); 
        return i + 1;
    }

  
void quickSort(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);

   
      quickSort(nums, low, pi - 1);
      quickSort(nums, pi + 1, high);
        }
    }
vector<int> quickSortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution s;
    vector<int> nums = {7, 4, 1, 5, 3};

    vector<int> sorted = s.quickSortArray(nums);

    for (int x : sorted)
        cout << x << " ";
    cout << endl;

    return 0;
}
