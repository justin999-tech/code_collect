//Uva 10125
//a+b+c=d => a+b=d-c
#include<bits/stdc++.h>
using namespace std;
struct pair_sum
{
    long long sum;
    long long i,j;
};

bool compare(const pair_sum& a, const pair_sum& b){
    return a.sum < b.sum;
}

int main(){
    int num;
    while(cin>>num){
        if(num==0) return 0;
        vector<long long> s;
        for(int i=0; i<num; i++){
            int input;
            cin>>input;
            s.push_back(input);
        }
        sort(s.begin(),s.end());
        vector<pair_sum> table;
        for(int i=0; i<s.size()-1; i++){
            for(int j=i+1; j<s.size(); j++){
                table.push_back({s[i]+s[j],i,j});
            }
        }
        //sort table
        sort(table.begin(),table.end(),compare);
        long long target; //a+b = target = d-c
        bool found = false; //to get out of two-layer for-loop
        for(int i = s.size()-1 ; i>=0 ; i--){ // s[i] stand for d, and we want the max d so increasely traverse i
            for(int j = s.size()-1 ; j>=0 ; j--){ //s[j] stand for c
                target=s[i]-s[j];
                if(s[i]==s[j]) continue;
                auto range = equal_range(table.begin(),table.end(),pair_sum{target,0,0},compare);
                // "range" is the pair{first_meet_target_iterator,last__meet_target_iterator}，左閉右開
                //如果沒有找到符合蒐尋對象的話，first_it, second_it 會指向同一個地方
                for(auto it = range.first ; it != range.second ; it++){ //因為左閉右開用!=
                    if(it->i != i && it->j != j && it->i != j && it->j != i){
                        found = true;
                        cout<<s[i]<<endl;
                        break;
                    }
                }
                if(found) break;
            }
            if (found) break;
        }
        if(!found)
            cout<<"no solution"<<endl;
    }
    return 0;
}