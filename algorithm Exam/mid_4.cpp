#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_case;
    cin>>num_case;
    for(int i=0; i<num_case; i++){
        int num_interval,count=0;
        cin>>num_interval;
        int start, finish;
        map<int,int> mp;//"map" base on hash, doesn't set size
        map<int,int> reverse_mp;
        for(int j=0; j<num_interval; j++){
            cin>>start>>finish;
            mp[start]=finish;
            reverse_mp[finish]=start;
        }
        //greedy
        int last_finish=reverse_mp.begin()->first;
        count++;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->first >= last_finish){
                last_finish = it->second;
                count++;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}