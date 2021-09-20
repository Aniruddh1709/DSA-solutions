
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

// Follow up: Your solution should run in O(log n) time and O(1) space.












int Solve(int lo,int hi,int n,vector<int> a){
        if(a.size()==1){
            return a[0];
        }
          int mid=(hi+lo)/2;
        if(hi==lo){
            return a[mid];
        }

      
     
        if((n-mid-1)%2==0){
            if(a[mid+1] && a[mid]==a[mid+1]){
                return Solve(mid+1,hi,n,a);
            }else{
                return Solve(lo,mid,n,a);
            }
        }else if((n-mid-1)%2!=0){
            if(a[mid+1] && a[mid]==a[mid+1]){
                return Solve(lo,mid,n,a);
            }else{
                return Solve(mid+1,hi,n,a);
            }
        }
        
        return 0;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        int ans=Solve(lo,hi,n,nums);
        return ans;
    }