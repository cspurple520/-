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
		printf("玩家按照分数由大到下排名如下：\n");
		while(temp!=NULL)
		{
			printf("用户名：%s\n",temp->name);
			printf("分数%d\n",temp->score);
			temp=temp->next;
		}
	}
}

void add_user()
{
	User* user=(User*)malloc(sizeof(User));
	printf("请输入添加的用户信息 :\n"); 
	printf("用户名:"); 
	scanf("%s",user -> name);
	printf("分数 :"); 
	scanf("%d",&user -> score);
	User *temp=(User*)malloc(sizeof(User));
	temp=head;
	
	// HEAD -> user1 -> user2 -> user3
	
	if(temp==NULL)  //头指针是如果为空，用头插法插入用户信息 
	{
		user -> next = head;
		head=user;
		printf("添加用户成功\n");
		CNT++;		
		return;				
	}
	if(temp->next==NULL)//temp(1号位)如果指向空指针，根据分数大小用头插法或者尾插法输入用户信息 
	{
		if(user->score>=temp->score)
		{
			user -> next = head;
			head=user;	
			printf("添加用户成功\n");
			CNT++;
			return;						
		}
		else
		{
			user->next==NULL;
			temp->next=user;						
		}
	}
	else //temp(1号位)如果指向的不是空指针 
	{
		if(user->score>=temp->score)  //如果玩家分数较大，用头插法插入 
		{
			user -> next = temp;
			head=user;	
			printf("添加用户成功\n");
			CNT++;
			return;
		}
		while(temp->next->next!=NULL) //如果temp的下下个指针不是空指针，则比较大小，从任意地方插入 
		{
			temp=temp->next;
			if(user->score<=temp->score&&user->score>=temp->next->score)
			{
				user->next=temp->next;
				temp->next=user;
				printf("添加用户成功\n");
				CNT++;		
				return;
			}		
		}
		temp=temp->next;  //直到temp下下个指针是空指针，则用尾插法插入
		user->next=NULL;
		temp->next=user;
		printf("添加用户成功\n");
		CNT++;	
	}		
}

void delete_user()
{
	// cnt = 0时，head = NULL 
	User *temp1=(User*)malloc(sizeof(User));
	temp1=head;
	User *temp2=(User*)malloc(sizeof(User));
	if (!temp1){
		printf("当前无任何用户!\n");
		return;
	}
	temp2=temp1->next;  
	// temp2 指的是第一个real 的用户节点 
	char deletename[10];
	int count=1;
	int c;
//	if(CNT!=0)
	{
		printf("输入删除用户的username：");
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
				printf("没有找到此用户，请重新输入！"); 
				return;
			}
			temp1=temp1->next;
		}
		temp1=head;
		if(count==1)
		{
			head=temp1->next;
			printf("删除用户成功！\n");
			CNT--;
			return; 
		}
		else
		{
			printf("删除用户成功！");
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
	printf("当前用户数 : %d\n",CNT);
	printf("case:%d添加用户\n",ADD);
	printf("case:%d获取用户信息\n",GET);
	printf("case:%d更新某个用户\n",UPDATE);
	printf("case:%d删除某用户\n",DELETE);
	printf("case:%d返回上一级\n",RETURN);
	printf("case:%d玩家排名\n",RANK);
	printf("case:%d退出\n",EXIT);
	printf("请输入case操作: ");
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
		printf("当前无任何用户!\n"); 
	}
	if(CNT!=0)
	{
		printf("输入更改用户的username：");
		scanf("%s",findname);
		while(temp!=NULL)
		{
			
			if(strcmp(findname,temp->name)==0)
			{ 
			    // 进入了这个if ,代表我们已经找到了用户 
				printf("请选择更改信息：1.用户名  2.分数\n"); 
				scanf("%d",&choice);
				if(choice==2)
				{
					printf("请输入修改后的分数：");
					scanf("%d",&rescore);
					temp->score=rescore;
				}
				if(choice==1)
				{
					printf("请输入更改后的用户名："); 
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
		printf("没有找到此用户，请重新输入！"); 
	}
}

void PWD()
{
	char password[20];
	printf("请输入密码："); 
	for(int i=1;i<=5;i++)
	{
		scanf("%s",password);
		if(strcmp(password,ADMIN_PWD)==0)
		{
			printf("密码正确！\n");
			system("pause");
			break;
		}
		else
		{
			printf("密码错误！您还有%d此机会!\n",(5-i)); 
			if(i==5)
			{
				printf("密码输入错误次数过多，退出程序!\n");
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
		printf("当前无任何用户！"); 
	} 
	else
	{
		for(int i=1;i<=CNT;i++)
		{
			printf("第%d名:",i);
			printf("用户名：%s        ",temp->name);
			printf("分数%d\n",temp->score);
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

