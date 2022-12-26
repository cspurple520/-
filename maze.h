#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#define Maxsize 101                  
using namespace std;
int a[Maxsize][Maxsize];
int walk[5000][2];
int rows,cols,n,summ=0,steps=0,minn=10001,want=-1;   //定义行列,障碍点个数,路径个数,步数和显示的路径 
int every; 
int bx,by,ex,ey;                      //定义迷宫开始的地方和尽头; 
typedef struct            
{ 
    int x;
    int y;
    int k;
}point;                            //定义点的结构体 x为横坐标，y为纵坐标，k为方向 
point path[10005];
int top=-1;                      //栈顶
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
	printf("\n                    您建立的迷宫如下：\n\n");
	printmap();
	printf("\n   请输入迷宫的起点(横纵坐标用空格隔开):    ");
	scanf("%d%d",&bx,&by);
	a[bx][by]=BEGIN;
	while(bx<1||by>rows||bx<1||by>cols||!a[bx][by]) 
	{
	   printf("\n   您输入的起点坐标有误，请重新输入:");
	   scanf("%d%d",&bx,&by);
	   a[bx][by]=BEGIN;
    } 
    printf("\n   请输入迷宫的终点,不能与起点坐标相同(横纵坐标用空格隔开):     ");
	scanf("%d%d",&ex,&ey);
	a[ex][ey]=END;
    while(ex<1||ex>rows||ey<1||ey>cols||!a[ex][ey]||(bx==ex&&by==ey))
    {
	   printf("\n   您输入的终点坐标有误，请重新输入:    ");
	   scanf("%d%d",&ex,&ey);
	   a[ex][ey]=END;
    }
	printf("\n                    您建立的迷宫完整迷宫如下：\n\n");
	printmap();  
}

void input()
{
	int rad;
	printf("  请分别输入迷宫行列的大小(100*100以内，回车确定):\n    行数:   ");
	scanf("%d",&rows);
	while(rows>100)
	{
		printf("\n  您输入的行数过多，请重新输入!" );
		printf("\n\n  请输入行数:   ");
		scanf("%d",&rows);
	} 
	printf("\n    列数:   ");
	scanf("%d",&cols); 
	while(cols>100)
	{
		printf("\n  您输入的列数过多，请重新输入!" );
		printf("\n\n  请输入列数:   ");
		scanf("%d",&cols);
	} 
	for(int i=1;i<=rows;i++)
	    for(int j=1;j<=cols;j++)
	        a[i][j]=1;
	printf("\n  请输入障碍点的个数: ");
	scanf("%d",&n);
	while(n>rows*cols)
	{
		printf("\n  您输入的障碍点个数过多！");
		printf("\n  请重新输入障碍点的个数: ");
		scanf("%d",&n);
	}
	default_random_engine e(time(0));    //避免每次随机相同,加time，提供种子 
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
 
void move()   //记录当前的方向，判断能否走，判断是否到达终点 
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
			printf("你已到达终点，游戏结束！总步数：%d步\n",step); 
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
		printf("\n                                              游戏进行中\n\n");
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

void print_userpoint(int front)    //	用siwtch 打印出 四个点的图形
{
	
	switch(front)
	{
		case CANT:
			printf("▇ ") ;
			break;
		case CAN:
			printf("  ") ;
			break; 
		case BEGIN:
			printf("●");
			break;
		case END:
			printf("▲");
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

void print_point(int front)    //	用siwtch 打印出 八个点的图形
{     
	switch(front)
	{
		case CANT:
			printf("▇ ") ;
			break;
		case CAN:
			printf("  ") ;
			break; 
		case UP:
			printf("↑") ;
			break;
		case DOWN:
			printf("↓") ;
			break;
		case LEFT:
			printf("←") ;
			break;
		case RIGHT:
			printf("→") ;
			break;
		case BEGIN:
			printf("●");
			break;
		case END:
			printf("▲");
			break;
	}
}



void printpath()
{
	printf("你已到达终点，游戏结束！总步数：%d步\n",step); 
	printf("玩家所走的路径为：\n") ;
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
	printf("是否选择展示用户行走路径：1.展示 2.不展示\n");
	scanf("%d",&n);
	while(n<1||n>2)
	{
		printf("您的输入有错，请重新输入!1.展示 2.不展示\n"); 
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
			printf("\n                                              玩家所走路径展示中\n\n");
			printmap();
			printf("玩家所走的路径为：\n") ;
			for(int j=1;j<=i;j++)
			{
				printf("(%d,",path[j].x);
				printf("%d,",path[j].y);
				printf("%d)->",path[j].k);
						
			}
			Sleep(500);
			system("cls");
		}
		printf("\n                                              展示结束\n\n");
		printmap();
		printpath();
		system("pause");    			
	}
	else
	{
		printf("游戏结束，祝您游戏愉快！"); 
	}	
}


/*
   
20
20

1 
1 1
10 10

*/
