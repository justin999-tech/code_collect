#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>> table;
bool is_pal(int x){ //deal with removing leading zero and check palindromic
    int h=x/60;
    int m=x%60;
    int t = h*100+m; //notice 12:01 這種
    string s = to_string(t);
    string s_ori = s;
    reverse(s.begin(),s.end());
    string s_rev = s;
    if(s_ori==s_rev) return true;
    return false;

}
void precalculate(){ 
    //計算從0~1439
    int begin=0;
    for(int i=1; i<=1439; i++){
        if(is_pal(i)){
            table.push_back({{begin,i-1},i});
            begin=i;
        }
    }
    

}
int main(){
    int t;
    cin>>t;
    precalculate();
    while(t--){
        int h,m;
        char ch; //讀':'
        cin>>h>>ch>>m;
        //轉分->查table->將答案轉時分
        if((h==23 && m>=32 && m <=59)){
            cout<<"00:00"<<endl;
            continue;
        }
        if(h==0&&m==0){
            cout<<"00:01"<<endl;
            continue;
        }
        int tmp =h*60+m;
        bool flag = false;
        for(int i=0; i<table.size(); i++){
            if(tmp>=table[i].first.first && tmp<=table[i].first.second){
                int ans = table[i].second;
                int ans_h = ans/60;
                int ans_m = ans%60;
                printf("%02d:%02d\n",ans_h,ans_m);
                flag =true;
                break;
            }
            if(flag==true) break;
        }
    }
    return 0;
}