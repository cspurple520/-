#include <bits/stdc++.h>
#define Maxsize 101
using namespace std;

typedef struct
{
	char name[10];
	int score;
}User;
User user[100];
const int ADD = 1;
const int GET = 2;
const int UPDATE = 3;
const int DELETE = 4;
const int EXIT = -1;

int CNT=0;
void print_info();
void add_user();
void choice(int in);
void delete_user();
void get_users();
void update_user(); 
int admin()
{
	int in;
	while(1)
	{
		print_info();
		scanf("%d",&in);
		if(in==EXIT)
			break;
		choice(in);
	}
}

void print_info()
{
		system("cls");
	printf("��ǰ�û��� : %d\n",CNT);
	printf("case:%d����û�\n",ADD);
	printf("case:%d��ȡ�û���Ϣ\n",GET);
	printf("case:%d����ĳ���û�\n",UPDATE);
	printf("case:%dɾ��ĳ�û�\n",DELETE);
	printf("case:%d�˳�\n",EXIT);
	printf("������case����: ");
}
void add_user()
{
	CNT++;
	printf("�������û���Ϣ\n");
	printf("�û�����");
	scanf("%s",user[CNT].name);
	printf("�����������");
	scanf("%d",&user[CNT].score);	
}

void delete_user()
{
	char deletename[10];
	int i,j;
	int find,record,userlenpre,userlennext;
	if(CNT==0)
		printf("��ǰ���κ��û�"); 
	else
	{
		printf("����ɾ���û���ID��");
		scanf("%s",deletename);
		{
			for(i=0;i<=CNT;i++)
			{
				find=0;
				if(strcmp(deletename,user[i].name)==0)
				{
					find=1;
					record=i;
					break;
				}
			}
			if(find==0)
			{
				printf("û���ҵ����û�,���������룡\n");
			}
			if(find==1)	
			{
				if(record==CNT)
				{
					CNT--;
				}
				else
				{
					CNT--;
					for(i=record;i<=CNT;i++)
					{
						userlennext=strlen(user[i+1].name);
						user[i].score=user[i+1].score;
						for(j=1;j<=userlennext;j++)
						{
							user[i].name[j]=user[i+1].name[j];
						}
						user[i].name[j]	='\0';					
					}
				}
			}		
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
			get_users();
			break;
		case UPDATE:
			update_user();
			break;		
	}
	cout<<endl;
	system("pause");
}

void get_users()
{
	char findname[10];
	int find,record;
	int i;
	int choice;
	if(CNT==0)
	{
		printf("��ǰ���κ��û�!\n"); 
	}	
	else
	{
		printf("�������ѯ��ʽ��1.�鿴�����û��û���Ϣ 2.�鿴�����û�"); 
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("�����û���ID��");
			scanf("%s",findname);
			for(i=0;i<=CNT;i++)
			{
				find=0;
				if(strcmp(findname,user[i].name)==0)
				{
					find=1;
					record=i;
					break;
				}
			}
			if(find==0)
			{
				printf("û���ҵ����û�,���������룡\n");
			}
			if(find==1)	
			{
				printf("���ҵ��û���\n"); 
				printf("�û���:%s\n",user[record].name);
				printf("����:%d\n",user[record].score);
			}				 
		}
		if(choice==2)
		{
			for(int i=1;i<=CNT;i++)
			{
				printf("�û�����%s\n",user[i].name);
				printf("������%d\n",user[i].score);
			}
		}

	} 
}

void update_user()
{
	char findname[10];
	char rename[10];
	int find,record,rescore,choice,renamelen;
	int i;
	if(CNT==0)
	{
		printf("��ǰ���κ��û�!\n"); 
	}
	else
	{
		printf("��������û���ID��");
		scanf("%s",findname);
		{
			for(i=0;i<=CNT;i++)
			{
				find=0;
				if(strcmp(findname,user[i].name)==0)
				{
					find=1;
					record=i;
					break;
				}
			}
			if(find==0)
			{
				printf("û���ҵ����û�,���������룡\n");
			}
			if(find==1)	
			{
				printf("��ѡ�������Ϣ��1.�û���  2.����\n"); 
				scanf("%d",&choice);
				if(choice==2)
				{
					printf("�������޸ĺ�ķ�����");
					scanf("%d",&rescore);
					user[record].score=rescore;
				}
				if(choice==1)
				{
					printf("��������ĺ���û�����"); 
					scanf("%s",rename);
					renamelen=strlen(rename);
					for(i=1;i<=renamelen;i++)
					{
						user[record].name[i]=rename[i];
					}
					user[record].name[i]='\0';
				}
			}		
		} 
	} 	
}


/*
1
a
0
1
abc
100
1
abcd
99
1
abcde
98
1
abcdef
97
*/
