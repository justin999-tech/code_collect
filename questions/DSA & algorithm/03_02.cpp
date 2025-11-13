#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int num;
    cout<<"要輸入計算的個數為：";
    cin>>num;
    int *pointer = new int[num];
    cout << "\n";
    for(int i=0; i<num;i++){
        cout<<"輸入pointer["<<i<<"]:";
        cin>>pointer[i];
    }

    cout<<"-------------------------------"<<endl;
     int total=0;    
    for(int i=0; i<num; i++){
        total+=pointer[i];
    }

    cout<<num<<"個數的總和="<<total;

    //remember
    delete[]pointer;
    pointer=NULL;
}