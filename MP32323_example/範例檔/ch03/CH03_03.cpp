#include <iostream>
using namespace std;
class list
{
	public:
 	   int num,score;
	   char name[10];
	   class list *next;
};
typedef class list node;
typedef node *link;
int main()
{  
	link newnode,ptr,delptr; //�ŧi�T�Ӧ�C���c����
	cout<<"�п�J 5 ���ǥ͸�ơG"<<endl;
	delptr=new node;   //delptr�ȷ���C��
	if (!delptr)
	{  
		cout<<"[Error!!�O����t�m����!]"<<endl;
		exit(1);
	}
	cout<<"�п�J�y���G";
	cin>>delptr->num;
	cout<<"�п�J�m�W�G";
	cin>>delptr->name;
	cout<<"�п�J���Z�G";
	cin>>delptr->score;
	ptr=delptr;   //�O�d��C���A�Hptr���ثe�`�I����
	for (int i=1;i<5;i++)
	{  
		newnode=new node;  //�إ߷s�`�I
		if(!newnode)
		{  
			cout<<"[Error!!�O����t�m����!"<<endl;
			exit(1);
		}
		cout<<"�п�J�y���G";
		cin>>newnode->num;
		cout<<"�п�J�m�W�G";
		cin>>newnode->name;
		cout<<"�п�J���Z�G";
		cin>>newnode->score;
		newnode->next=NULL;
		ptr->next=newnode; //��s�`�I�[�b��C�᭱
		ptr=ptr->next;     //��ptr�O���b��C���̫᭱
	}
    cout<<"\n  ��  ��  ��  �Z"<<endl;
    cout<<" �y��\t�m�W\t���Z\n====================="<<endl;
	ptr=delptr;            //��ptr�^���C��
	while(ptr!=NULL)
	{  
		cout<<ptr->num<<"\t"<<ptr->name<<"\t"<<ptr->score<<endl;
	    delptr=ptr;
		ptr=ptr->next;     //ptr�̧ǩ��ᨫ�X��C
        delete delptr;     //���^�O����Ŷ�
	}
}
