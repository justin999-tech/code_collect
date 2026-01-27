#include<bits/stdc++.h>
using namespace std;
int main(){
    string start;
    int end;
    long long ans=0;
    //map<locatino,delta_value>
    //map has already helped you sort !!
    map<int,int> delta;
    while(cin>>start && start!="."){
        // default value = 0 ! so we can directly ++
        cin>>end;
        int u=stoi(start);
        int v=end;
        int left=min(u,v);
        int right=max(u,v);
        delta[left]++;
        delta[right]--;
    } 
    // calculate a segment after a segment, not a unit
    long long overlap = 0; //times of overlapping
    int last_x = 0; //just given a random value
    int first = true;
    for(auto const& [loc,del] : delta){
        if(!first){
            int L=loc-last_x;
            last_x=loc;
            if(overlap>=2){
                ans+=L*(overlap*(overlap-1)/2);
            }
            overlap+=del;
        }
        else{
            last_x=loc;
            overlap=del;
            first = false;
        }
    }
    cout<<ans<<endl;
    return 0;
}