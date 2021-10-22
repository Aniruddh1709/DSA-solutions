// Consider a binary tree of N nodes (1 Root and N-1 descendants). A node in this tree is called a Magic parent if the sum of one subtree (either left or right) of the node is even, and the sum of the other is odd. The nodes having only one or no child nodes can never be magic parents. The tree is represented as a series of relationships of each node to the Root node such as L, R, LL, LR.. and so on, where each node is left (L) to Root or left-left (LL) or right-left (RL) to Root and so on. Write a program to find all the Magic parents in the tree, and print their sum as the output.

// Input Format: The first line of input contains an integer, N number of nodes 
// in the tree The second line of input contains an Integer root which is the root of the tree.

// The next N-1 lines of input contain a string, S, and an integer, X separated by
//  a single white space where X is a node in the tree and S is the relation between 
//  Root and X.

// Output Format: The output contains the sum of all the Magic parent
//  nodes in the tree

// Sample Input:

// 9
// 11
// L 23
// R 44
// LL 13
// LR 9
// RL 22
// RR 7
// RLL 6
// RLR 15

// Sample Output:
// 33



#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<unordered_map>
int ans=0;
int trav(string s,unordered_map<string,int> &map){
    if(map.find(s)!=map.end()){
        int l=trav(s+"L",map);
        int r=trav(s+"R",map);
        
        if((l+r)%2!=0){
            ans+=map[s];
        }
        return l+r+map[s];
    }else{
        return 0;
    }
}
int main() {
    int R=11;
    int N=9;
    unordered_map<string,int> m;
    vector<string> p{"L","RL","RLL","R","RR","RLR","LR","LL"};
    vector<int> r{23,22,6,44,7,15,9,13,};
    m[""]=R;
    for(int i=0;i<p.size();i++){
        m[p[i]]=r[i];
    }
    trav("",m);
    cout<<ans;
    return 0;
}