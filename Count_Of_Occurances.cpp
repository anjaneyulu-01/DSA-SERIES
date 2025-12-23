/*
Count Occurrences in a Sorted Array

You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.



Return the count of occurrences of target in the array.


Example 1

Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1

Output: 3

Explanation: The number 1 appears 3 times in the array.

Example 2

Input: arr = [5, 5, 5, 5, 5, 5], target = 5

Output: 6

Explanation: All elements in the array are 5, so the target appears 6 times.
*/

#include <bits/stdc++.h>
using namespace std;

int countOccurrences(vector<int>& arr, int target) {
    int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int last  = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
    if (first == arr.size() || arr[first] != target)
        return 0;

    return last - first;
}

int main() {
    vector<int> arr = {0, 0, 1, 1, 1, 2, 3};
    int target = 1;

    cout << countOccurrences(arr, target) << endl;
    return 0;
}
