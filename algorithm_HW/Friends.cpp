#include<bits/stdc++.h>
using namespace std;
int Root(vector<int>& parent,int index){
    if(parent[index]!=index){
        return parent[index]=Root(parent,parent[index]); //同時回傳又整理
    }
    else{
        return index;
    }
}
void Union (vector<int>& parent, vector<int>& size, int i, int j){
    if(size[i]>=size[j]){
        parent[j]=i;
        size[i]+=size[j];
        size[j]=0;
    }
    else if(size[i]<size[j]){
        parent[i]=j;
        size[j]+=size[i];
        size[i]=0;
    }
}
int main(){
    int num_case;
    cin>>num_case;
    for(int i=0; i<num_case; i++){
        int num_villager;
        int num_pair;
        cin>>num_villager;
        cin>>num_pair;

        vector<int> parent(num_villager);
        for(int j=0; j<num_villager; j++)
            parent[j]=j;
        
        vector<int> size(num_villager);
        for(int j=0; j<num_villager; j++)
            size[j]=1;

        for(int j=0; j<num_pair; j++){
            int a,b;
            cin>>a>>b;
            //convert to 0-based
            a--;
            b--;
            if(Root(parent,a)!=Root(parent,b))
                Union(parent,size,Root(parent,a),Root(parent,b));
        }
        
        int max=size[0];
        for(int j=1; j<num_villager; j++){
            if(size[j]>max){
                max=size[j];
            }
        }
        cout<<max<<endl;
    }
    return 0;
}