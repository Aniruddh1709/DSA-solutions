// There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length of the garden is n).

// There are n + 1 taps located at points [0, 1, ..., n] in the garden.

// Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

// Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

 

// Example 1:


// Input: n = 5, ranges = [3,4,1,1,0,0]
// Output: 1
// Explanation: The tap at point 0 can cover the interval [-3,3]
// The tap at point 1 can cover the interval [-3,5]
// The tap at point 2 can cover the interval [1,3]
// The tap at point 3 can cover the interval [2,4]
// The tap at point 4 can cover the interval [4,4]
// The tap at point 5 can cover the interval [5,5]
// Opening Only the second tap will water the whole garden [0,5]
// Example 2:

// Input: n = 3, ranges = [0,0,0,0]
// Output: -1
// Explanation: Even if you activate all the four taps you cannot water the whole garden.
// Example 3:

// Input: n = 7, ranges = [1,2,1,0,2,1,0,1]
// Output: 3
// Example 4:

// Input: n = 8, ranges = [4,0,0,0,0,0,0,0,4]
// Output: 2
// Example 5:

// Input: n = 8, ranges = [4,0,0,0,4,0,0,0,4]
// Output: 1
 

// Constraints:

// 1 <= n <= 104
// ranges.length == n + 1
// 0 <= ranges[i] <= 100


// Nlog(N) Solution

#include<bits/stdc++.h>
using namespace std;

static bool compare(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            return a[1]<=b[1];
        }
        return a[0]<b[0];
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> r;
        int flag=0;
        for(int i=0;i<ranges.size();i++){
            if(ranges[i]>0) flag=1;
            r.push_back({i-ranges[i],i+ranges[i]});
        }
        sort(r.begin(),r.end(),compare);
        if(flag==0) return -1;
        stack<vector<int>> s;
        s.push(r[0]);
        for(int i=1;i<r.size();i++){
            if(r[i][0]==s.top()[0]){
                if(r[i][1]<=s.top()[1]){
                    continue;
                }else{
                   s.pop();
                    s.push(r[i]);
                }
            }else{
                if(r[i][0]>s.top()[0]){
                     if(r[i][0]<=0){
                       if(r[i][1]>s.top()[1] && s.top()[1]<n){
                           s.pop();
                     s.push(r[i]);
                        continue;
                    }else if(s.top()[1]>=n){
                         break;
                    }  
                     }
                    if(r[i][1]>s.top()[1] && s.top()[1]<n){
                        auto y=s.top();
                        while(!s.empty() && r[i][1]> s.top()[1] && s.top()[1]<n && r[i][0]>s.top()[0] &&s.top()[1]>=r[i][0]){     
                            auto x=s.top();
                            s.pop();
                                                                                                                                y=x;
                        }
                        s.push(y);
                        s.push(r[i]);
                        continue;
                    }else if(s.top()[1]>=n){
                        break;
                    }
                }else if(r[i][0]<s.top()[0]){
                    if(r[i][1]>=s.top()[1]){
                        s.pop();
                        s.push(r[i]);
                        continue;
                    }
                }
                 }}
        stack<vector<int>> ans=s;
        auto v=ans.top();
        ans.pop();
        if(v[1]<n){return -1;}
        while(!ans.empty()){
            if(v[0]>ans.top()[1]) return -1;
             v=ans.top();
             ans.pop();       
        }
        if(v[0]>0) return -1;
             return s.size();
    }