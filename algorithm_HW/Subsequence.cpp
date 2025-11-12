#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    if(!(cin>>n))
        return 0;

    while(n--){
    string s,t;
    cin >> s >> t;
    int i=0;
    for(int j=0; j<t.size(); j++){
        if(s[i]==t[j])
            i++;
    }
    if(i==s.size())
        cout<<"Yes\n";
    else
        cout<<"No\n";
    }
        return 0;

}