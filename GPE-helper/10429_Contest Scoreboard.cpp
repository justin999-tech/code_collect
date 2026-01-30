//1~100 contestant 1~9 question
//Uva 10258
#include<bits/stdc++.h>
using namespace std;
struct Team
{
    int id;
    vector<bool> whether_C;
    vector<int> number_I; //Can't write vector<int> number_I(10,0);
    int pass_number=0;
    int penalty=0;
    bool participate = false; //if a team didn't submit any answer, we don't care them.
    //Constructor
    Team(int _id):
    whether_C(10,false),number_I(10,0){
        id=_id;
    }
};

bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]>b[0];
    if(a[1]!=b[1]) return a[1]<b[1];
    return a[2]<b[2];
}

int main(){
    int cases;
    cin>>cases;
    string line;
    getline(cin,line);//eat enter right after cases, after this operation, line is \n.
    getline(cin,line);//eat the first blank line
    for(int i=0; i<cases; i++){
        vector<Team> team_list;
        //initialization
        for(int k=0; k<=100; k++){
            team_list.push_back(Team(k));
        }
        while(getline(cin,line) && line!=""){
            int number,question,time;
            char state;
            stringstream ss(line);
            ss>>number>>question>>time>>state;
            if(state=='I'){
                if(team_list[number].whether_C[question]==false){ //Once this question has already pass, ignore everything
                    team_list[number].participate = true;
                    team_list[number].whether_C[question] = false;
                    team_list[number].number_I[question]++;
                }
                else{
                    
                }
            }
            else if(state=='C'){
                if(team_list[number].whether_C[question]==false){ //Once this question has already pass, ignore everything
                    team_list[number].participate = true;
                    team_list[number].whether_C[question] = true;
                    team_list[number].penalty = 
                    team_list[number].penalty + time + team_list[number].number_I[question]*20;
                    team_list[number].pass_number++;
                }
                else{
                    
                }
            }
            else{
                team_list[number].participate = true;
            }
        }
        //deal with output -> put factors into vector to sort by our cmp
        vector<vector<int>> ranking;
        for(int i=1; i<=100; i++){
            if(team_list[i].participate==true){
                ranking.push_back({team_list[i].pass_number,team_list[i].penalty,team_list[i].id});
            }
        }
        sort(ranking.begin(),ranking.end(),cmp);
        for(auto& rank : ranking){
            cout<<rank[2]<<" "<<rank[0]<<" "<<rank[1]<<endl;
        }
        //each case separated by a blank line
        if(i!=cases-1) cout<<endl;
    }
    return 0;
}