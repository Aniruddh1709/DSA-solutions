You are stuck in a grid of shape MxN. You start at (1, 1) and the only exit from the maze is at (M, N). According to the rules, when you're standing at any (i, j), you can only jump to either (i+j, j) or (i, j+i). You have to escape as quickly as possible or else you'll be stuck forever. Determine the minimum number of jumps required to escape the maze. If you cannot exit the maze, print -1.

Input Format

First line contains a positive integer T denoting the number of test cases It is followed by T lines, each containing 2 positive integers Mi and Ni specifying the shape of the grid.

Constraints

1 <= T <= 100

Subtask 1 (30 points):

1 <= M, N <= 105

Subtask 2 (70 points):

1 <= M, N <= 1018

Output Format

Output consists of T lines, each line containing one integer as the minimum number of steps required to escape the maze, or -1 if that's not possible.

Sample Input 0

3
5 2
6 3
1 3
Sample Output 0

3
-1
2
Explanation 0

In the first example, the shortest path would be (1, 1) -> (1, 2) -> (3, 2) -> (5, 2), requiring 3 jumps

In the second example, escaping the maze is impossible

In the third example, the shortest path would be (1, 1) -> (1, 2) -> (1, 3), requiring 2 jumps



My Solution:


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

#include <algorithm>
using namespace std;

void Solve(unsigned long long int m,unsigned long long int n){
  vector<vector<unsigned long long int>> v;
   unsigned long long int ans=0;
 while(m>0 && n>0){
     if(m==1){
         ans+=n-1;
         n=1;
         break;
     }else if(n==1){
         ans+=m-1;
         m=1;
         break;
     }
     if(m>n){
         ans+=m/n;
         m=m%n;
     }else if(n>m){
         ans+=n/m;
         n=n%m;
     }else if(n==m){
         break;
     }
 }
if(m==n && m==1){
    cout<<ans<<endl;
}else{
    cout<<-1<<endl;
}   

    

    
    

    
}

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
       unsigned long long int M,N;
        cin>>M>>N;
     Solve(M,N);
        
    }
    return 0;
}
