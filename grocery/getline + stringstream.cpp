#include <bits/stdc++.h>
using namespace std;
//用來處理有很多行資料但不知道有幾個 element per each line
//the first line means following have n lines
// each line doesn't have fixed number of interger
//sum up interger of each line and print them respectively
int main(){
    stringstream ss;
    int n;
    int in; //用來存放string轉乘int的資料
    while (cin>>n){
        cin.ignore();//避免吃到cin>>n的換行
        string line;//把每行資料當作string讀取
        for(int i=0; i<n; i++){
            getline(cin,line);//跟cin不同的點是他不會遇到空格就停，預設是遇到換行才停
            int sum=0;
            ss.clear();//清除緩存
            ss<<line;
            //also ss.str(line);
            while(true){
                ss>>in; //寫入interger
                if(ss.fail())
                    break;
                sum+=in;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}