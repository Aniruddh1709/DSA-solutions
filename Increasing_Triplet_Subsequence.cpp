

// Problem Statement

// Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
// such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, 
// return false.

// My Solution

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2){
            return false;
        }
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(s.size()<=2){
            return false;
        }
        bool ans=false;
        for(int i=0;i<nums.size()-2;i++){
            if(ans){break;}
            int j=i+1;
            while(j<nums.size()-1 && nums[j]<=nums[i]){
                j++;
            }
            if(j==nums.size()-1){
                ans=false;
                continue;
            }
            while(j<nums.size()-1){
                
            int k=nums.size()-1;
            while(k>j && nums[k]<=nums[j]){
                k--;
            }
            if(k<=j){
                ans=false;
                j++;
                while(j<nums.size()-1 && nums[j]<=nums[i]){
                    j++;
                }
            }else{
                ans=true;
                break;
            }
            }
            
        }
        return ans;
    }
};


// A more optimized solution




   bool increasingTriplet(vector<int>& nums) {
    
    int n=nums.size();
    if(n<3)return false;       //if size of array is less than 3 we can't make triplate
    int low=INT_MAX, mid=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(nums[i]>mid) return true;
        else if(nums[i]<low) low=nums[i];
        else if(nums[i]> low and nums[i]<mid) mid=nums[i];
    }
                return false;
    
}