/*
Merge two sorted arrays without extra space

Medium

Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.



Merge both the arrays into a single array sorted in non-decreasing order.



The final sorted array should be stored inside the array nums1 and it should be done in-place.


nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.


nums2 has a length of n.

Examples:
Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]

Output: [-5, -3, -2, 1, 4, 5, 8]

Explanation:

The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2

Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]

Output: [-7, -3, -1, 0, 2, 7, 8]

Explanation:

The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,idx=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[idx]=nums1[i];
                idx--;
                i--;
            }
            else{
                nums1[idx]=nums2[j];
                idx--;
                j--;
            }
        }
        while(i>=0){
         nums1[idx]=nums1[i];
         idx--;
         i--; 
        }
        while(j>=0){
         nums1[idx]=nums2[j];
          idx--;
          j--;            
        }
    }
};


int main() {

vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0}; 
vector<int> nums2 = {-3, 1, 8};
int m = 4; 
int n = 3; 
Solution obj;
obj.merge(nums1, m, nums2, n);
for (int x : nums1) {
    cout << x << " ";
}
cout << endl;

return 0;
}