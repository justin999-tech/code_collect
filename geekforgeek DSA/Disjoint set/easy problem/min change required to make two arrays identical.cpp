#include <bits/stdc++.h>
using namespace std;

#define N 100010
vector<int> id(N),sz(N);

//id:store parent of a node i.e parent[]
//sz:store size of a DSU tree
//DSU:disjoint set union
int root(int idx){
    int i=idx;
    while(id[i]!=i)
        id[i]=id[id[i]], i=id[i];
    return i;
}
void Union(int a, int b){
    int i=root(a),j=root(b);
    if(i!=j){
        if(sz[i]>=sz[j]){
            id[j]=i, sz[i]+=sz[j];
            sz[j]=0;
        }
        else{
            id[i]=j,sz[j]+=sz[i];
            sz[i]=0;
        }
    }
}
int min_change(int n, vector<int>& a, vector<int>& b){
    //sets as single elements
    for(int i=0; i<N; i++){
       id[i]=i;
       sz[i]=1;
    }
    for(int i=0; i<n; i++){
        if(root(a[i])!=root(b[i]))
            Union(a[i],b[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(id[i]==i)
            ans+=(sz[i]-1);
    }
    return ans;
}
int main(){
    string line;
    vector<int> a,b;
    if(getline(cin, line)){
        stringstream ss(line);
        int x;
        while(ss >> x){
            a.push_back(x);
        }
    }
    if(getline(cin, line)){
        stringstream ss(line);
        int x;
        while (ss >> x){
            b.push_back(x);
        }
    }

    int n=a.size();
    cout<<min_change(n,a,b);
    return 0;
}