/*
Union of two sorted arrays

Easy

Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.



The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.


Examples:
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation:

The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation:

The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<int> FindUnion(vector<int>& A, vector<int>& B) {
int i = 0, j = 0;
int n = A.size(), m = B.size();
vector<int> ans;

while (i < n && j < m) {
 if (A[i] < B[j]) {
    if (ans.empty() || ans.back() != A[i])
     ans.push_back(A[i]);
      i++;
 }
 else if (A[i] > B[j]) {
  if (ans.empty() || ans.back() != B[j])
      ans.push_back(B[j]);
  j++;
    }
else {  

 if (ans.empty() || ans.back() != A[i])
    ans.push_back(A[i]);
  i++;
  j++;
    }
}
while (i < n) {
    if (ans.empty() || ans.back() != A[i])
        ans.push_back(A[i]);
    i++;
}
while (j < m) {
  if (ans.empty() || ans.back() != B[j])
      ans.push_back(B[j]);
  j++;
  }

 return ans;
    }
};

int main() {
    vector<int>A = {3, 4, 6, 7, 9, 9};
    vector<int>B = {1, 5, 7, 8, 8};
    Solution obj;

    vector<int> ans = obj.FindUnion(A, B);
    for (auto val : ans) cout << val << " ";

    return 0;
}
