#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define Maxsize 101                  
using namespace std;
int a[Maxsize][Maxsize];
int walk[5000][2];
int rows,cols,n,summ=0,steps=0,minn=10001,want=-1;   //��������,�ϰ������,·������,��������ʾ��·�� 
int every; 
int bx,by,ex,ey;                      //�����Թ���ʼ�ĵط��;�ͷ; 
typedef struct            
{ 
    int x;
    int y;
    int k;
}point;                            //�����Ľṹ�� xΪ�����꣬yΪ�����꣬kΪ���� 
point path[10005];
int top=-1;                      //ջ��
int step=0;
char front;
const int CANT = 0;
const int CAN = 1;
const int UP = 2;
const int DOWN = 3;
const int LEFT = 4;
const int RIGHT = 5;
const int BEGIN = 6;
const int END = 7;
void input();                        
void bande();
void move(); 
void printmap();
void showpath();
void print_point(int front);
void printpath(); 
void printusermap();
void print_userpoint(int front);                      
int maze()
{
	system("color A1");
	input();
	move();
	showpath();
    return 0; 
}

void bande()
{	
	printf("\n                    ���������Թ����£�\n\n");
	printmap();
	printf("\n   �������Թ������(���������ÿո����):    ");
	scanf("%d%d",&bx,&by);
	a[bx][by]=BEGIN;
	while(bx<1||by>rows||bx<1||by>cols||!a[bx][by]) 
	{
	   printf("\n   ����������������������������:");
	   scanf("%d%d",&bx,&by);
	   a[bx][by]=BEGIN;
    } 
    printf("\n   �������Թ����յ�,���������������ͬ(���������ÿո����):     ");
	scanf("%d%d",&ex,&ey);
	a[ex][ey]=END;
    while(ex<1||ex>rows||ey<1||ey>cols||!a[ex][ey]||(bx==ex&&by==ey))
    {
	   printf("\n   ��������յ�������������������:    ");
	   scanf("%d%d",&ex,&ey);
	   a[ex][ey]=END;
    }
	printf("\n                    ���������Թ������Թ����£�\n\n");
	printmap();  
}

void input()
{
	int rad;
	printf("  ��ֱ������Թ����еĴ�С(100*100���ڣ��س�ȷ��):\n    ����:   ");
	scanf("%d",&rows);
	while(rows>100)
	{
		printf("\n  ��������������࣬����������!" );
		printf("\n\n  ����������:   ");
		scanf("%d",&rows);
	} 
	printf("\n    ����:   ");
	scanf("%d",&cols); 
	while(cols>100)
	{
		printf("\n  ��������������࣬����������!" );
		printf("\n\n  ����������:   ");
		scanf("%d",&cols);
	} 
	for(int i=1;i<=rows;i++)
	    for(int j=1;j<=cols;j++)
	        a[i][j]=1;
	printf("\n  �������ϰ���ĸ���: ");
	scanf("%d",&n);
	while(n>rows*cols)
	{
		printf("\n  ��������ϰ���������࣡");
		printf("\n  �����������ϰ���ĸ���: ");
		scanf("%d",&n);
	}
	default_random_engine e(time(0));    //����ÿ�������ͬ,��time���ṩ���� 
    uniform_int_distribution<int> r(1, rows),c(1, cols);
        int temp1,temp2;
        for(int i=0;i<n;i++)
        {
        	temp1=r(e);
        	temp2=c(e);
        	while(!a[temp1][temp2])
        	{
        	    temp1=r(e);
        	    temp2=c(e);
			}
			a[temp1][temp2]=0;
		}	
		bande();
 } 
 
void move()   //��¼��ǰ�ķ����ж��ܷ��ߣ��ж��Ƿ񵽴��յ� 
{
	int current_x,current_y;
	int i,j,present,next=BEGIN; 
	current_x=bx,current_y=by;
	while(1)
	{
		front=getch();
		if(front=='s')
		{
			i=1,j=0,present=DOWN;		
		}
		if(front=='a')
		{
			i=0,j=-1,present=LEFT;		
		}
		if(front=='d')
		{
			i=0,j=1,present=RIGHT;		
		}
		if(front=='w')
		{
			i=-1,j=0,present=UP;		
		}	
		if(a[current_x+i][current_y+j] == END)
		{
			step++;
			a[current_x][current_y]= present;
			a[current_x+i][current_y+j]= next;
			path[step].x=current_x;
			path[step].y=current_y;
			path[step].k=present;
			system("cls");
			printusermap(); 
			printf("���ѵ����յ㣬��Ϸ�������ܲ�����%d��\n",step); 
			break;
		}
		if(a[current_x+i][current_y+j]!= CANT)
		{
			step++;
			a[current_x][current_y]= present;
			if(i==1&&j==0)
				current_x++;
			if(i==0&&j==-1)
				current_y--;
			if(i==0&&j==1)
				current_y++;
			if(i==-1&&j==0)
				current_x--;
			a[current_x][current_y]= next;
			path[step].x=current_x-i;
			path[step].y=current_y-j;
			path[step].k=present;
		}
		system("cls");
		printf("\n                                              ��Ϸ������\n\n");
		printusermap(); 
		}
}

void printusermap() 
{
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	print_userpoint(a[i][j]);
		}
	    printf("\n");			 
	} 	
	
}

void print_userpoint(int front)    //	��siwtch ��ӡ�� �ĸ����ͼ��
{
	
	switch(front)
	{
		case CANT:
			printf("�~ ") ;
			break;
		case CAN:
			printf("  ") ;
			break; 
		case BEGIN:
			printf("��");
			break;
		case END:
			printf("��");
			break;
		default:
			printf("  ") ;
			break; 
			
	}
}


void printmap()
{
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	print_point(a[i][j]);
		}
	    printf("\n");			 
	} 
}

void print_point(int front)    //	��siwtch ��ӡ�� �˸����ͼ��
{     
	switch(front)
	{
		case CANT:
			printf("�~ ") ;
			break;
		case CAN:
			printf("  ") ;
			break; 
		case UP:
			printf("��") ;
			break;
		case DOWN:
			printf("��") ;
			break;
		case LEFT:
			printf("��") ;
			break;
		case RIGHT:
			printf("��") ;
			break;
		case BEGIN:
			printf("��");
			break;
		case END:
			printf("��");
			break;
	}
}



void printpath()
{
	printf("���ѵ����յ㣬��Ϸ�������ܲ�����%d��\n",step); 
	printf("������ߵ�·��Ϊ��\n") ;
	for(int i=1;i<=step;i++)
	{
		printf("(%d,",path[i].x);
		printf("%d,",path[i].y);
		printf("%d)->",path[i].k);		
	}
	printf("(%d,",ex);
	printf("%d)",ey);
}

void showpath()
{
	int n;
	printf("�Ƿ�ѡ��չʾ�û�����·����1.չʾ 2.��չʾ\n");
	scanf("%d",&n);
	while(n<1||n>2)
	{
		printf("���������д�����������!1.չʾ 2.��չʾ\n"); 
		scanf("%d",&n);
	}
	if(n==1)
	{
		for(int i=1;i<=rows;i++)
		{
			for(int j=1;j<=cols;j++)
			{
				if(a[i][j]>=2&&a[i][j]<=5)
				{
					a[i][j]=CAN;
				}
			}
		}
		for(int i=1;i<=step;i++)
		{
			a[path[i].x][path[i].y]=path[i].k;
			printf("\n                                              �������·��չʾ��\n\n");
			printmap();
			printf("������ߵ�·��Ϊ��\n") ;
			for(int j=1;j<=i;j++)
			{
				printf("(%d,",path[j].x);
				printf("%d,",path[j].y);
				printf("%d)->",path[j].k);
						
			}
			Sleep(500);
			system("cls");
		}
		printf("\n                                              չʾ����\n\n");
		printmap();
		printpath();
		system("pause");    			
	}
	else
	{
		printf("��Ϸ������ף����Ϸ��죡"); 
	}	
}


/*
   
20
20

1 
1 1
10 10

*/
