

//Code for string compression leetcode



class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        int c=1;
        int n=chars.size();
        char cur=chars[0];
        for(int i=1;i<chars.size();i++){
            if(i==n){
                
                break;
            }
            if(chars[i]==cur){
                c++;
            }else if(chars[i]!=cur){
                if(c==1){
                    chars.push_back(cur);
                }else{
                    chars.push_back(cur);
                    string l=to_string(c);
                    for(int j=0;j<l.length();j++){
                        chars.push_back(l[j]);
                    }
                }
                cur=chars[i];
                c=1;
            }
            if(i==n-1){
                   if(c==1){
                    chars.push_back(cur);
                }else{
                    chars.push_back(cur);
                    string l=to_string(c);
                    for(int j=0;j<l.length();j++){
                        chars.push_back(l[j]);
                    }
                }
            }
        }
        for(int i=n;i<chars.size();i++){
            chars[i-n]=chars[i];
        }
        return chars.size()-n;
    }
};
