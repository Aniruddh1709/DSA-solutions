
// Problem Statement
// Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
// Input Format :
// The first line contains a single integer ‘T’ denoting the number of test cases.

// The first line of each test case contains two integers ‘N’ and ‘K’ denoting the number of elements in the array/list and the number of aggressive cows.

// The second line contains ‘N’ single space-separated integers denoting the elements of the array.
// Output Format :
// For each test case, print the majority element in a separate line.
// Note :
// You do not need to print anything; it has already been taken care of.
// Constraints :
// 1 <= T <= 5
// 2 <= N <= 20000
// 2 <= C <= N
// 0 <= ARR[i] <= 10 ^ 9

// Where ‘T’ is the number of test cases, 'N' is the length of the given array and, ARR[i] denotes the i-th element in the array.

// Time Limit: 1 sec.
// Sample Input 1 :
// 2
// 3 2
// 1 2 3
// 5 2
// 4 2 1 3 6
// Sample Output 1 :
// 2
// 5
// Explanation To Sample Input 1 :
// In the first test case, the largest minimum distance will be 2 when 2 cows are placed at positions {1, 3}.

// In the second test case, the largest minimum distance will be 5 when 2 cows are placed at positions {1, 6}.
// Sample Input 2 :
// 2
// 6 4
// 0 3 4 7 10 9
// 6 3
// 0 4 3 7 10 9
// Sample Output 2 :
// 3
// 5
// Explanation To Sample Input 2 :
// In the first test case, the largest minimum distance will be 3 when 4 cows are placed at positions {0, 3, 7, 10}.

// In the second test case, the largest minimum distance will be 4 when 3 cows are placed at positions {0, 4, 10}.







#include<bits/stdc++.h>
using namespace std;
int Solve(int mid,int N,vector<int> &b,int m){
        int p=1;
        int s=b[0];
        for(int i=1;i<N;i++){
            if(b[i]-s>=mid){
                s=b[i];
                p++;
                if(p==m){return 1;}
            }
        }
        return 0;
    }

int aggressiveCows(vector<int> &bloom, int m)
{
        sort(bloom.begin(),bloom.end());
        int n=bloom.size();
        int sum=bloom[n-1];
        int lo=0;
        int hi=sum;
        int ans=-1;
        while(lo<hi){
            int mid=(lo+hi)/2;
            int bou=Solve(mid,n,bloom,m);
            if(bou){
                lo=mid+1;
                ans=max(ans,mid);
            }else{
                 hi=mid;
            }
        }

        return ans;
}