/*
Book Allocation Problem

Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m representing the number of students, allocate all the books to the students so that each student gets at least one book, each book is allocated to only one student, and the allocation is contiguous.



Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized. If the allocation of books is not possible, return -1.


Example 1

Input: nums = [12, 34, 67, 90], m=2

Output: 113

Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2

Input: nums = [25, 46, 28, 49, 24], m=4

Output: 71

Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
*/

#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 bool isPossible(vector<int>& nums, int m, int maxPages) {
        int students = 1;
        int pages = 0;
     for(int i = 0; i < nums.size(); i++) {
            if(pages + nums[i] <= maxPages){
                pages += nums[i];
            }
            else{
                students++;
                pages = nums[i];
                if (students > m) return false;
            }
        }
        return true;
    }

int findPages(vector<int>& nums, int m){
        int n = nums.size();
        if(m > n) return -1;
   int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums, m, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
  vector<int>nums={25, 46, 28, 49, 24};
  int m=4;
  Solution obj;
  cout<<obj.findPages(nums,m);
  return 0;
}