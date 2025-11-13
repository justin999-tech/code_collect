#include <iostream>
using namespace std;

int main(){
    int *intptr = new int(50);
    float *floatptr = new float;
    cout<<"intptr 指向的資料夾："<<*intptr<<"\n";
    *floatptr=0.5;
    cout<<"floatptr 指向的資料夾："<<*floatptr<<"\n";

    delete intptr;
    delete floatptr;

    return 0;
}