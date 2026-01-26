//Uva 10000
#include<bits/stdc++.h>
using namespace std;
int main(){
    int case_count = 0;
    int node_quantity;
    int starting_point;
    while(cin>>node_quantity && node_quantity!=0){
        cin>>starting_point;
        int from,to;
        vector<vector<int>> adjacent(node_quantity+1);
        while(cin>>from>>to && from!=0 && to!=0){
            adjacent[from].push_back(to);
        }
        //從starting point做BFS->queue
        queue<int> ready;
        vector<int> length(node_quantity+1,-1);
        length[starting_point]=0;
        ready.push(starting_point);
        int finishing_point;
        int ans_length=-1;
        while(!ready.empty()){
            int source = ready.front();
            ready.pop();
            for(auto adj : adjacent[source]){
                if(length[source]+1 > length[adj]){
                    length[adj]=length[source]+1;
                    ready.push(adj);
                }
            }
        }
        //If there are several path with max length
        //print the node of the least number
        for(int i=1; i<=node_quantity; i++){
            if(length[i] > ans_length){
                finishing_point = i;
                ans_length=length[i];
            }
        }
        case_count++;
        cout<<"Case "<<case_count<<": The longest path from "<<starting_point<<" has length "<<ans_length<<", finishing at "<<finishing_point<<".\n";
    }
    return 0;
}