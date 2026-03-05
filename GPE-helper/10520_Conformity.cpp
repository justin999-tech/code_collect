//Uva 11286
//map's key can be a vector !!
//map is sort according to keys
#include<bits/stdc++.h>
using namespace std;
int main(){
    int s;
    while(cin>>s && s!=0){
        map<vector<int>,int> m;
        for(int i=0; i<s; i++){
            vector<int> combination;
            for(int j=0; j<5; j++){
                int c;
                cin>>c;
                combination.push_back(c);
            }
            sort(combination.begin(),combination.end());
            m[combination]++;
        }
        int max=0;
        int total=0;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second==max){
                total+=it->second;
            }
            if(it->second>max){
                total=0;
                total+=it->second;
                max=it->second;
            }
        }
        cout<<total<<endl;
    }
    return 0;
}