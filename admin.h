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
	printf("当前用户数 : %d\n",CNT);
	printf("case:%d添加用户\n",ADD);
	printf("case:%d获取用户信息\n",GET);
	printf("case:%d更新某个用户\n",UPDATE);
	printf("case:%d删除某用户\n",DELETE);
	printf("case:%d退出\n",EXIT);
	printf("请输入case操作: ");
}
void add_user()
{
	CNT++;
	printf("请输入用户信息\n");
	printf("用户名：");
	scanf("%s",user[CNT].name);
	printf("请输入分数：");
	scanf("%d",&user[CNT].score);	
}

void delete_user()
{
	char deletename[10];
	int i,j;
	int find,record,userlenpre,userlennext;
	if(CNT==0)
		printf("当前无任何用户"); 
	else
	{
		printf("输入删除用户的ID：");
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
				printf("没有找到此用户,请重新输入！\n");
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
		printf("当前无任何用户!\n"); 
	}	
	else
	{
		printf("请输入查询方式：1.查看单个用户用户信息 2.查看所有用户"); 
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("输入用户的ID：");
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
				printf("没有找到此用户,请重新输入！\n");
			}
			if(find==1)	
			{
				printf("已找到用户！\n"); 
				printf("用户名:%s\n",user[record].name);
				printf("分数:%d\n",user[record].score);
			}				 
		}
		if(choice==2)
		{
			for(int i=1;i<=CNT;i++)
			{
				printf("用户名：%s\n",user[i].name);
				printf("分数：%d\n",user[i].score);
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
		printf("当前无任何用户!\n"); 
	}
	else
	{
		printf("输入更改用户的ID：");
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
				printf("没有找到此用户,请重新输入！\n");
			}
			if(find==1)	
			{
				printf("请选择更改信息：1.用户名  2.分数\n"); 
				scanf("%d",&choice);
				if(choice==2)
				{
					printf("请输入修改后的分数：");
					scanf("%d",&rescore);
					user[record].score=rescore;
				}
				if(choice==1)
				{
					printf("请输入更改后的用户名："); 
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
