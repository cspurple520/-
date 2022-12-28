#include <bits/stdc++.h>
#define Maxsize 101
typedef struct User
{
	char name[20];
	int score; 
	User* next;	
}User;
User* head;
int CNT=0;
int in;
const int ADD = 1;
const int GET = 2;
const int UPDATE = 3;
const int DELETE = 4;
const int RETURN = 5;
const int RANK = 6;
const int EXIT = -1;
const char ADMIN_PWD[20] = "ctgu666";
void print_info();
void add_user();
void choice(int in);
void delete_user();
void get_user();
void update_user();
void rank_user();
void PWD(); 
int admin()
{
//	PWD(); 
	head=NULL;
	while(1)
	{
		print_info();
		scanf("%d",&in);
		if(in==EXIT)
			break;
		if(in==RETURN)
		{
			break; 
		}
		choice(in);
	}
	return 0;
}

void get_user()
{
	User *temp=(User*)malloc(sizeof(User));
	temp= head;
	{
		printf("��Ұ��շ����ɴ����������£�\n");
		while(temp!=NULL)
		{
			printf("�û�����%s\n",temp->name);
			printf("����%d\n",temp->score);
			temp=temp->next;
		}
	}
}

void add_user()
{
	User* user=(User*)malloc(sizeof(User));
	printf("��������ӵ��û���Ϣ :\n"); 
	printf("�û���:"); 
	scanf("%s",user -> name);
	printf("���� :"); 
	scanf("%d",&user -> score);
	User *temp=(User*)malloc(sizeof(User));
	temp=head;
	
	// HEAD -> user1 -> user2 -> user3
	
	if(temp==NULL)  //ͷָ�������Ϊ�գ���ͷ�巨�����û���Ϣ 
	{
		user -> next = head;
		head=user;
		printf("����û��ɹ�\n");
		CNT++;		
		return;				
	}
	if(temp->next==NULL)//temp(1��λ)���ָ���ָ�룬���ݷ�����С��ͷ�巨����β�巨�����û���Ϣ 
	{
		if(user->score>=temp->score)
		{
			user -> next = head;
			head=user;	
			printf("����û��ɹ�\n");
			CNT++;
			return;						
		}
		else
		{
			user->next==NULL;
			temp->next=user;						
		}
	}
	else //temp(1��λ)���ָ��Ĳ��ǿ�ָ�� 
	{
		if(user->score>=temp->score)  //�����ҷ����ϴ���ͷ�巨���� 
		{
			user -> next = temp;
			head=user;	
			printf("����û��ɹ�\n");
			CNT++;
			return;
		}
		while(temp->next->next!=NULL) //���temp�����¸�ָ�벻�ǿ�ָ�룬��Ƚϴ�С��������ط����� 
		{
			temp=temp->next;
			if(user->score<=temp->score&&user->score>=temp->next->score)
			{
				user->next=temp->next;
				temp->next=user;
				printf("����û��ɹ�\n");
				CNT++;		
				return;
			}		
		}
		temp=temp->next;  //ֱ��temp���¸�ָ���ǿ�ָ�룬����β�巨����
		user->next=NULL;
		temp->next=user;
		printf("����û��ɹ�\n");
		CNT++;	
	}		
}

void delete_user()
{
	// cnt = 0ʱ��head = NULL 
	User *temp1=(User*)malloc(sizeof(User));
	temp1=head;
	User *temp2=(User*)malloc(sizeof(User));
	if (!temp1){
		printf("��ǰ���κ��û�!\n");
		return;
	}
	temp2=temp1->next;  
	// temp2 ָ���ǵ�һ��real ���û��ڵ� 
	char deletename[10];
	int count=1;
	int c;
//	if(CNT!=0)
	{
		printf("����ɾ���û���username��");
		scanf("%s",deletename);
		while(temp1!=NULL)
		{
			if(strcmp(deletename,temp1->name)==0)
			{
				break;
			}
			count++;
			if(count>CNT)
			{
				printf("û���ҵ����û������������룡"); 
				return;
			}
			temp1=temp1->next;
		}
		temp1=head;
		if(count==1)
		{
			head=temp1->next;
			printf("ɾ���û��ɹ���\n");
			CNT--;
			return; 
		}
		else
		{
			printf("ɾ���û��ɹ���");
			CNT--;
			for(int i=0;i<count-2;i++)
			{
				temp1=temp1->next;
			}
			temp2=temp1->next;
		    temp1->next=temp2->next;
		}
	}
}

void choice(int in)
{
	switch(in)
	{
		case ADD:
			add_user();
			break;
		case DELETE:
			delete_user();
			break;	
		case GET:
			get_user();
			break;
		case UPDATE:
			update_user();
			break;
		case RANK:
			rank_user();
			break;			
	}
	printf("\n");
	//system("pause");
}

void print_info()
{
	//system("cls");
	printf("��ǰ�û��� : %d\n",CNT);
	printf("case:%d����û�\n",ADD);
	printf("case:%d��ȡ�û���Ϣ\n",GET);
	printf("case:%d����ĳ���û�\n",UPDATE);
	printf("case:%dɾ��ĳ�û�\n",DELETE);
	printf("case:%d������һ��\n",RETURN);
	printf("case:%d�������\n",RANK);
	printf("case:%d�˳�\n",EXIT);
	printf("������case����: ");
}

void update_user()
{
	char findname[20];
	char rename[20];
	User *temp=(User*)malloc(sizeof(User));
	temp=head;
	int rescore,choice,renamelen;
	int i;
	if(CNT==0)
	{
		printf("��ǰ���κ��û�!\n"); 
	}
	if(CNT!=0)
	{
		printf("��������û���username��");
		scanf("%s",findname);
		while(temp!=NULL)
		{
			
			if(strcmp(findname,temp->name)==0)
			{ 
			    // ���������if ,���������Ѿ��ҵ����û� 
				printf("��ѡ�������Ϣ��1.�û���  2.����\n"); 
				scanf("%d",&choice);
				if(choice==2)
				{
					printf("�������޸ĺ�ķ�����");
					scanf("%d",&rescore);
					temp->score=rescore;
				}
				if(choice==1)
				{
					printf("��������ĺ���û�����"); 
					scanf("%s",rename);
					renamelen=strlen(rename);
					for(i=0;i<renamelen;i++)
					{
						temp->name[i]=rename[i];
					}
					temp->name[i]='\0';
				}
				return;
			}
			temp=temp->next;	
		}
//		count CNT
		printf("û���ҵ����û������������룡"); 
	}
}

void PWD()
{
	char password[20];
	printf("���������룺"); 
	for(int i=1;i<=5;i++)
	{
		scanf("%s",password);
		if(strcmp(password,ADMIN_PWD)==0)
		{
			printf("������ȷ��\n");
			system("pause");
			break;
		}
		else
		{
			printf("�������������%d�˻���!\n",(5-i)); 
			if(i==5)
			{
				printf("�����������������࣬�˳�����!\n");
				exit(0) ; 
			}
		} 		
	}
}

void rank_user()
{
	User *temp=(User*)malloc(sizeof(User));
	temp=head;
	if(CNT==0)
	{
		printf("��ǰ���κ��û���"); 
	} 
	else
	{
		for(int i=1;i<=CNT;i++)
		{
			printf("��%d��:",i);
			printf("�û�����%s        ",temp->name);
			printf("����%d\n",temp->score);
			temp=temp->next;	 
		}	
	}
}
/*
1
a
72
1
b
99
1
c
36
1
d
638
1
e
66
1
f
70
1
g
639
1
h
666
1
i
12
*/

