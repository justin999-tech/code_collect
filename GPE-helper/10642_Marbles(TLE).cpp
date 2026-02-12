//Uva10090
//高中畫圖用斜率分case 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    int c1,c2,n1,n2;
    
    while(cin>>num && num!=0){
        pair<int,int> ans; //<1th,2th>
        cin>>c1>>n1>>c2>>n2;
        bool flag = false;
        if(-((double)n1/n2)<=-((double)c1/c2)){  //case1
            for(int x=num/n1; x>=0; x--){
                if(((num-x*n1)%n2)!=0) continue;
                else{
                    ans={x,(num-x*n1)/n2};
                    cout<<ans.first<<" "<<ans.second<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag==false) cout<<"failed"<<endl;
        }
        else{
            for(int x=0; x<=num/n1; x++){
                if(((num-x*n1)%n2)!=0) continue;
                else{
                    ans={x,(num-x*n1)/n2};
                    cout<<ans.first<<" "<<ans.second<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag==false) cout<<"failed"<<endl;
        }
    }
    return 0;
}