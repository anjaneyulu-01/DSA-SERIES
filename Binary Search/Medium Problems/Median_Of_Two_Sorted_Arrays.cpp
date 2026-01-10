/*
Median of Two Sorted Arrays of different sizes

Problem Statement:
Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays. The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the median is the average of the two middle elements.
*/

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size();
    int n = nums2.size();
    int low = 0, high = m;

    while(low <= high){
        int cut1 = (low + high) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((m + n) % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if(left1 > right2){
            high = cut1 - 1;
        }
        else{
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main() {
    vector<int> arr1 = {1, 3, 8};
    vector<int> arr2 = {7, 9, 10, 11};
  double median = findMedianSortedArrays(arr1, arr2);
   cout <<median;
   return 0;
}
