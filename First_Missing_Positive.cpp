// Given an unsorted integer array nums, return the 
// smallest missing positive integer.

// You must implement an algorithm that runs in O(n) 
// time and uses constant extra space.


// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1

// Not_Optimal_solution 


 int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==1){
            if(nums[0]==1){
                return 2;
            }else{
                return 1;
            }
        }
        unordered_map<long long,int>m;
        long long int m2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
               m[nums[i]]++; 
            }
            m2=max(m2,(long long int)nums[i]);
        }
        if(m2<=0){
            return 1;
        }
        for(long long int i=1;i<=m2+1;i++){
            if(m.find(i)==m.end()){
                return i;
            }
        }
        return 0;
    }