
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==2){
            if(target==nums[0]) return 0;
            if(nums[1]==target) return 1;
        }
       int i=0,k=nums.size()-1;
       while(i<=k){
           int mid=(i+k)/2;
           if(nums[mid]==target) return mid;
           if(nums[i]<nums[mid]){
               if(target>=nums[i] && nums[mid]>target){
                   k=mid-1;
               }else{
                   i=mid+1;
               }
           }else if(nums[mid]<nums[k]){
               if(target<=nums[k] && target>nums[mid]){
                   i=mid+1;
               }else{
                   k=mid-1;
               }
           }else{
               if(target<nums[mid] && target<=nums[k]){
                   i=mid+1;
               }else{
                   k=mid-1;
               }
           }
       }
       return -1; 
    }
};

The first line contains 'T', denoting the number of test cases.

Each test contains 3 lines:

a number 'n', denoting the number of elements.
n space-separated numbers denoting the array elements.
the target value.
Output Format
T lines, each containing a number denoting the index of the target value. -1 if the target value is not present.






4
7
4 5 6 7 0 1 2
4
4
3 4 1 2
5
5
5 1 2 3 4
2
4
5 6 3 4
4
