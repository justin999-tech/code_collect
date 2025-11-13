#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
typedef class list
{
    public:
    int num , score;
    char name[10];
    class list *next;
} node;

node *findnode(node *head, int num){
    node *ptr;
    ptr=head;
    while(ptr!=NULL){
        if(ptr->num==num)
            return ptr;
        ptr=ptr->next;
    }
    return ptr;
}

void insertnode(node *head, node *ptr,int num,int score,char name[10]){
    node *Insertnode;
    Insertnode=new node;
    if(!Insertnode)
        return;
    Insertnode->num=num;
    Insertnode->score=score;
    strcpy(Insertnode->name,name);  //我們一開始是設字元陣列
    //所以沒辦法用=，除非一開始就用string name 就可以用Insertnode->name=name;
    Insertnode->next=NULL;
    if(ptr==NULL){  //Insert the first node
        Insertnode->next=head;
       // return Insertnode;
    }
    else{   //Insert the last node
        if(ptr->next==NULL){
            ptr->next=Insertnode;
        }
        else{   //Insert intermediate node
            Insertnode->next = ptr->next;
            ptr->next=Insertnode;
        }    
    }
   // return head;
}

int main(){
    node *head,*ptr,*newptr;
    int new_num,new_score;
    char new_name[10];
    int position=0,find,data[12][2];
    char namedata[12][10]={{"Allen"},{"Scott"},{"Marry"},{"John"}
    ,{"Mark"},{"Ricky"},{"Lisa"},{"Jasica"},
    {"Hanson"},{"Amy"},{"Bob"},{"Jack"}};

    srand((unsigned)time(NULL));    //成績用隨機生成的

    cout<<"座號  成績  座號  成績  座號  成績  座號  成績"<<endl;
	cout<<"=============================================="<<endl;

    for(int i=0;i<12;i++){
        data[i][0]=i+1; //座號
        data[i][1]=rand()%50+51;
    }
    for(int i=0;i<3;i++){   //print three row of datas
        for(int j=0;j<4;j++)
            cout<<"["<<data[j*3+i][0]<<"]  ["<<data[j*3+i][1]<<"]   ";
        cout<<endl;
        
    }

    head=new node;
    if(!head){
        cout<<"Error! memory allocation fail "<<endl;
        exit(1);
    }

    head->num=data[0][0];   //寫入第一個名字
    strcpy(head->name,namedata[0]);

    head->score=data[0][1];
    head->next=NULL;
    ptr=head;

    for(int i=1;i<12;i++){  //construct link list
        newptr=new node;
        newptr->next=NULL;
        newptr->num = data[i][0];
        strcpy(newptr->name,namedata[i]);
        newptr->score=data[i][1];
        ptr->next=newptr;
        ptr=ptr->next;
    }
    while(1){
        cout<<"請輸入要插入其後的學生座號，結束輸入-1:";
        cin>>position;
        if(position==-1)
            break;
        else{
            ptr=findnode(head,position);
            cout<<"請輸入新插入的學生座號:";
            cin>>new_num;
            cout<<"請輸入新插入的學生成績:";
            cin>>new_score;
            cout<<"請輸入新插入的學生姓名:";
            cin>>new_name;
            insertnode(head,ptr,new_num,new_score,new_name);
        }
    }

    ptr=head;
    cout<<"\n\t座號\t  姓名\t        成績\n";
    cout<<"\t============================\n";
    while(ptr!=NULL){
        cout << "\t[" << ptr->num << "]\t[" << ptr->name << "]" << setw(6) << "\t[" << ptr->score << "]\n";
        ptr=ptr->next;
    }
    delete head;
    return 0;
}