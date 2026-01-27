// #disjoint set
//Uva 793
#include<bits/stdc++.h>
using namespace std;
//path compression
int find(int i, vector<int>& parent){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i],parent);
}
//union by rank
void Union(int a, int b, vector<int>& parent, vector<int>& size){
    int rootA = find(a,parent);
    int rootB = find(b,parent);
    if(size[a]>=size[b]){
        size[rootA]+=size[rootB];
        size[rootB]=0;
        parent[rootB]=rootA;
    }
    else if(size[a]<size[b]){
        size[rootB]+=size[rootA];
        size[rootA]=0;
        parent[rootA]=rootB;
    }
}
int main(){ 
    int cases;
    cin>>cases;
    string line;
    getline(cin,line); //吃掉換行
    getline(cin,line); //吃掉空白
    while(cases--){
        int n;
        cin>>n;
        getline(cin,line); //吃到電腦數量後面的換行
        int successful=0;
        int unsuccessful=0;
        vector<int> parent(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
        vector<int> size(n+1,1);
        //讀取每一行直到有空行或EOF
        while(getline(cin,line) && line!=""){
            //先解析line裡面的3個參數
            char type;
            int i,j;
            stringstream ss(line);
            ss>>type>>i>>j;
            if(type=='c'){
                if(find(i,parent)!=find(j,parent)) Union(i,j,parent,size);
            }
            else if(type=='q'){
                if(find(i,parent)==find(j,parent)) successful++;
                else if(find(i,parent)!=find(j,parent)) unsuccessful++;
            }
        }
        cout<<successful<<","<<unsuccessful<<endl;
        //要注意最後一行不用再空行，否則會presentation error
        if(cases>0){
            cout<<endl;
        }
    }
    return 0;
    }

/*
1. cin >> s (你原本熟悉的用法)
行為：它把「空白鍵」、「Tab」、「換行」都當作切斷點。
結果：它只能讀取 一個單字 (Word)。
輸入：Hello World
讀到：Hello
殘留： World\n 還留在緩衝區裡。

2. getline(cin, s) (這題要用的)
行為：它只把「換行符號 (\n)」當作切斷點。中間的空白它會照單全收。
結果：它可以讀取 整句句子 (Sentence)
輸入：Hello World
讀到：Hello World
殘留：沒有殘留（這很重要！）。
*/