
// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected 
// if they are adjacent cells connected horizontally or vertically.
#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isVal(int r,int c,int M,int N){
    if(r>=0 && r<M && c>=0 && c<N){
        return true;
    }
    return false;
}

vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,1,-1};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                vis[i][0]=1;
                q.push({i,0});
                board[i][0]='a';
                while(!q.empty()){
                    vector<int> cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        if(isVal(cur[0]+dx[k],cur[1]+dy[k],m,n) && vis[cur[0]+dx[k]][cur[1]+dy[k]]==0)                         {
                           vis[cur[0]+dx[k]][cur[1]+dy[k]]=1;
                            if(board[cur[0]+dx[k]][cur[1]+dy[k]]=='O'){
                                board[cur[0]+dx[k]][cur[1]+dy[k]]='a';
                                q.push({cur[0]+dx[k],cur[1]+dy[k]});
                            }
                        }
                       
                    }
                }
            }
    if(vis[i][n-1]==0 && board[i][n-1]=='O') {
                vis[i][n-1]=1;
                q.push({i,n-1});
                board[i][n-1]='a';
                while(!q.empty()){
                    vector<int> cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        if(isVal(cur[0]+dx[k],cur[1]+dy[k],m,n) && vis[cur[0]+dx[k]][cur[1]+dy[k]]==0)                         {
                           vis[cur[0]+dx[k]][cur[1]+dy[k]]=1;
                            if(board[cur[0]+dx[k]][cur[1]+dy[k]]=='O'){
                                board[cur[0]+dx[k]][cur[1]+dy[k]]='a';
                                q.push({cur[0]+dx[k],cur[1]+dy[k]});
                            }
                        }
                       
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[0][i]==0 && board[0][i]=='O'){
                vis[0][i]=1;
                q.push({0,i});
                board[0][i]='a';
                while(!q.empty()){
                    vector<int> cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        if(isVal(cur[0]+dx[k],cur[1]+dy[k],m,n) && vis[cur[0]+dx[k]][cur[1]+dy[k]]==0)                         {
                           vis[cur[0]+dx[k]][cur[1]+dy[k]]=1;
                            if(board[cur[0]+dx[k]][cur[1]+dy[k]]=='O'){
                                board[cur[0]+dx[k]][cur[1]+dy[k]]='a';
                                q.push({cur[0]+dx[k],cur[1]+dy[k]});
                            }
                        }
                       
                    }
                }
            }
    if(vis[m-1][i]==0 && board[m-1][i]=='O') {
                vis[m-1][i]=1;
                q.push({m-1,i});
                board[m-1][i]='a';
                while(!q.empty()){
                    vector<int> cur=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        if(isVal(cur[0]+dx[k],cur[1]+dy[k],m,n) && vis[cur[0]+dx[k]][cur[1]+dy[k]]==0)                         {
                           vis[cur[0]+dx[k]][cur[1]+dy[k]]=1;
                            if(board[cur[0]+dx[k]][cur[1]+dy[k]]=='O'){
                                board[cur[0]+dx[k]][cur[1]+dy[k]]='a';
                                q.push({cur[0]+dx[k],cur[1]+dy[k]});
                            }
                        }
                       
                    }
                }
            }
        }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='O'){
                board[i][j]='X';
            }else if(board[i][j]=='a'){
                board[i][j]='O';
            }
        }
      
    }
               
    }
};