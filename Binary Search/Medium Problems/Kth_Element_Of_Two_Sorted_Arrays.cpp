/*
K-th Element of two sorted arrays

Problem Statement: Given two sorted arrays a and b of size m and n respectively. Find the kth element of the final sorted array.
*/

#include <bits/stdc++.h>
using namespace std;

int kthElement(int a[], int b[], int m, int n, int k){
    int i = 0, j = 0, count = 0;

    while(i < m && j < n){
        count++;
        if(a[i] < b[j]){
            if(count == k) return a[i];
            i++;
        }
        else{
            if(count == k) return b[j];
            j++;
        }
    }

    while(i < m){
        count++;
        if(count == k) return a[i];
        i++;
    }
 while(j < n){
        count++;
        if(count == k) return b[j];
        j++;
    }

    return -1;
}

int main() {
    int a[] = {2, 3, 6, 7, 9};
    int b[] = {1, 4, 8, 10};
  int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
 int k = 5;

    cout <<kthElement(a, b, m, n, k);

    return 0;
}
