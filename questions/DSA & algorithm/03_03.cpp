#include <iostream>
using namespace std;

typedef class list
{
    public:
        int num,score;
        char name[10];
        class list *next;
} node; //也可以用list就好，list node 等價，但習慣new node

int main(){
    list  *ptr, *delptr;   //宣告
    cout<<"請輸入5筆學生的資料:"<<endl;
    ptr = new node;
    if(!ptr){
        cout<<"[error!!記憶體分配失敗!]"<<endl;
        exit(1);
    }
    cout<<"請輸入座號:";
    cin>>ptr->num;
    cout<<"請輸入姓名:";
    cin>>ptr->name;
    cout<<"請輸入成績:";
    cin>>ptr->score;

    delptr=ptr;
    for(int i=1; i<5; i++){
        list *newptr = new node;  //建立新節點

        if(!newptr){
             cout<<"[error!!記憶體分配失敗!]"<<endl;
             exit(1);
        }

        cout<<"請輸入座號:";
        cin>>newptr->num;
        cout<<"請輸入姓名:";
        cin>>newptr->name;
        cout<<"請輸入成績:";
        cin>>newptr->score;

        newptr->next = NULL;
        ptr->next = newptr; //把newptr指到的東西給ptr->next指
        ptr = ptr->next;    //讓ptr保持在最前面
        //這邊不能加delete newptr;
        //因為這樣ptr就會突然沒有指到東西，變dangling pointer(懸空指標)
    }
    cout<<endl;
    cout << "   學  生  成  績   "<<endl;
    cout << " 座號   姓名   成績 "<<endl;
    cout<<  "======================"<<endl;

    ptr = delptr; //把ptr拉回來第一個
    while(ptr!=NULL){
        cout << ptr->num << "\t" << ptr->name << "\t" << ptr->score << endl;
        delptr = ptr;
        ptr = ptr->next;
        delete delptr;
    }
    return 0;
  
}