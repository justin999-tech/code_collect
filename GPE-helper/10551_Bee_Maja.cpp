#include<bits/stdc++.h>
using namespace std;
int calculate_n (int a){
    long long count=0;
    for(int i=1; i<10000; i++){
        count = count + i;
        if(count-1>=a){
            return i+1;
        }
    }
}
int main(){
    int ask;
    while(cin>>ask){
        //先算在第n圈
        int k=ask-2;
        if(ask==1){
            cout<<"0 0"<<endl;
            continue;
        }
        if(ask==2){
            cout<<"0 1"<<endl;
            continue;
        }
        if(ask==3){
            cout<<"-1 1"<<endl;
            continue;
        }
        if(ask==4){
            cout<<"-1 0"<<endl;
            continue;
        }
        if(ask==5){
            cout<<"0 -1"<<endl;
            continue;
        }
        if(ask==6){
            cout<<"1 -1"<<endl;
            continue;
        }
        if(ask==7){
            cout<<"1 0"<<endl;
            continue;
        }
        int n = calculate_n(k/6);
        int n_starting = 3*(n-1)*(n-2)+2;
        if(n_starting+(n-2)>=ask && ask>=n_starting){
            int x=(n_starting+(n-2))-ask;
            int y=(n-1)-x;
            cout<<x<<" "<<y<<endl;
        }
        else if(n_starting+(2*n-3)>=ask && ask>=n_starting+(n-2)){
            int x=(n_starting+(n-2))-ask;
            int y=n-1;
            cout<<x<<" "<<y<<endl;
        }
        else if(n_starting+(3*n-4)>=ask && ask>=n_starting+(2*n-3)){
            int x=-(n-1);
            int y=(n_starting+(3*n-4))-ask;
            cout<<x<<" "<<y<<endl;
        }
        else if(n_starting+(4*n-5)>=ask && ask>=n_starting+(3*n-4)){
            int x=ask-(n_starting+(4*n-5));
            int y=-(n-1)-x;
            cout<<x<<" "<<y<<endl;
        }
        else if(n_starting+(5*n-6)>=ask && ask>=n_starting+(4*n-5)){
            int x=ask-(n_starting+(4*n-5));
            int y=-(n-1);
            cout<<x<<" "<<y<<endl;
        }
        else if(n_starting+(6*n-7)>=ask && ask>=n_starting+(5*n-6)){
            int x=n-1;
            int y=ask-(n_starting+(6*n-7));
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}