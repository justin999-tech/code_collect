#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while(getline(cin,s1) && getline(cin,s2)){
        vector<vector<int>> table(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                if(s1[i-1]==s2[j-1]) table[i][j]=table[i-1][j-1]+1;
                else table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
        cout<<table[s1.size()][s2.size()]<<endl;
    }
    return 0;
}