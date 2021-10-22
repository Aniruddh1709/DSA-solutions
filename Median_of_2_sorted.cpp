// Given two sorted arrays nums1 and nums2 of size m and n respectively, 
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
// Example 3:

// Input: nums1 = [0,0], nums2 = [0,0]
// Output: 0.00000

//Not So Optimal Solution //
#include<bits/stdc++.h>
using namespace std;

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int mid=(m+n)/2;
        vector<int> p;
        int i=0;
        int j=0;
         double k=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                p.push_back(nums1[i]);
                if(mid==p.size()-1) break;
                i++;
            }else{
                p.push_back(nums2[j]);
                if(mid==p.size()-1) break;
                j++;
            }
            // cout<<p[p.size()-1]<<" "<<mid<<endl;
        }
        if(i==m){
            while(p.size()-1!=mid){
                p.push_back(nums2[j]);
                j++;
            }
        }else if(j==n){
            while(p.size()-1!=mid){
                p.push_back(nums1[i]);
                i++;
            }
        }
         if((m+n)%2==0){
                    k=(double)p[p.size()-2]+(double)p[p.size()-1];
                    k=k/2;
                
            }else{
                    k=(double)p[p.size()-1];
            }
       
        return k;
    }
