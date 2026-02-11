#include<bits/stdc++.h>
using namespace std;
char bases[]={'A','U','C','G'};
vector<vector<int>> adj(55);
char assignment[55];
bool visited[55];
bool is_valid(char a, char b){
    if (a == 'A' && b == 'U') return true;
    if (a == 'U' && b == 'A') return true;
    if (a == 'C' && b == 'G') return true;
    if (a == 'G' && b == 'C') return true;
    if (a == 'G' && b == 'U') return true;
    if (a == 'U' && b == 'G') return true;
    return false;
}
long long backtrack(int idx, vector<int>& component){
    if(idx==component.size()) return 1; //not 0 !!
    int u=component[idx];
    long long count = 0; //this node as root
    for(int i=0; i<4; i++){
        char current_base = bases[i];
        bool ok = true;
        // 檢查當前填入的鹼基，是否與connected component已經填好的「鄰居」衝突
        for(int v : adj[u]){
            if(assignment[v]!='N'){ // 鄰居已經填過字元了
                if(!is_valid(current_base,assignment[v])){
                    ok = false;
                    break;
                }
            } 
        }

        if(ok){
            assignment[u]=current_base;
            count+=backtrack(idx+1,component); //強迫以idx當作決定traverse順序
        }
    }
    assignment[u]='N';
    return count;

}
void solve(int casenum, int n){
    //use string to read n lines
    vector<string> structure(n);
    int L;
    for(int i=0; i<n; i++){
        cin>>structure[i];
        L=structure[i].size();
    }
    //initialization
    for(int i=0; i<L; i++){
        adj[i].clear();
        visited[i]=false;
        assignment[i]='N';
    }
    // 1. 解析點括號並建圖
    for(int i=0; i<n; i++){
        stack<int> s;
        for(int j=0; j<L; j++){
            if(structure[i][j]=='('){
                s.push(j);
            }
            if(structure[i][j]==')'){
                int left = s.top();
                s.pop();
                adj[left].push_back(j);
                adj[j].push_back(left);
            }
        }
    }
    long long total_ans = 1; //global variable
    // 2. 尋找connected component並計算方案數
    for(int i=0; i<L; i++){
        if(!visited[i]){
            vector<int> component;
            queue<int> q;
            q.push(i);
            visited[i]=true;
            component.push_back(i);
            while(!q.empty()){
                int source = q.front();
                q.pop();
                for(int v : adj[source]){
                    if(!visited[v]){
                        visited[v]=true;
                        q.push(v);
                        component.push_back(v);
                    }
                }
            }

            // 3. 針對這個connected component計算方案數
            total_ans*=backtrack(0,component); //0:calaulate from component's index 0
            if (total_ans==0){
                break; //finish earlier
            }
        } 
    }
    cout<<"Case"<<" "<<casenum<<": "<<total_ans<<endl;
}
int main(){
    int n, casenum=1;
    while(cin>>n && n!=0){
        solve(casenum,n);
        casenum++;
    }
    return 0;
}