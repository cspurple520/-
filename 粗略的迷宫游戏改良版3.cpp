#include<bits/stdc++.h>
#include<conio.h>
#define Maxsize 101                  
using namespace std;
int x[4]={0,-1,0,1},y[4]={-1,0,1,0};     //左上右下 
bool had[Maxsize][Maxsize];              //地图各点是否走过 
int a[Maxsize][Maxsize];
struct 
{
    int a;                        //坐标点 是否 
	int d;                       //方向 
}ans[Maxsize][Maxsize];
int walk[5000][2];
int rows,cols,n,summ=0,steps=0,minn=10001,want=-1;   //定义行列,障碍点个数,路径个数,步数和显示的路径 
int every; 
int bx,by,ex,ey;                      //定义迷宫开始的地方和尽头; 
typedef struct
{ 
    int x;
    int y;
    int k;
}point;                            //定义点的结构体 
point path[10005],sp[10005];
int top=-1;                      //栈顶
char front;

const int CANT = 0;
const int CAN = 1;
const int UP = 2;
const int DOWN = 3;
const int LEFT = 4;
const int RIGHT = 5;
const int BEGIN = 6;
const int END = 7;

int step=0;
void input();                        
void bande();
void move(); 
void printmap();

void print_point(int front);
void printpath();                       
int main()
{
	system("color A1");
	input();
	move();
	printpath();
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
 
void move()
{
//	所有的变量都设为有意义的名称   curren_x 

//   func(char front) :   记录当前的方向，判断能否走，判断是否到达终点 
	int current_x,current_y;
	current_x=bx,current_y=by;
	while(1)
	{
		front=getch();
		if(front=='s')
		{
			step++;
			if(a[current_x+1][current_y] == END)
			{
				a[current_x][current_y]= DOWN;
				a[current_x+1][current_y]= BEGIN;
				system("cls");
				printmap(); 
				printf("你已到达终点，游戏结束！总步数：%d步\n",step); 
				break;
			}
			if(a[current_x+1][current_y]== CAN)
			{
				a[current_x][current_y]= DOWN;
				current_x++;
				a[current_x][current_y]= BEGIN;
				path[step].x=current_x;
				path[step].y=current_y;
			}
		}
		else if(front=='a')
		{
			step++;
			if(a[current_x][current_y-1]==END)
			{
				a[current_x][current_y] = LEFT;
				a[current_x][current_y-1]=BEGIN;
				system("cls");
				printmap(); 
				printf("你已到达终点，游戏结束！总步数：%d步\n",step); 
				break;
			}
			if(a[current_x][current_y-1]==CAN)
			{
				a[current_x][current_y]= LEFT;
				current_y--;
				a[current_x][current_y]=BEGIN;
				path[step].x=current_x;
				path[step].y=current_y;
			}
			
		}			
		else if(front=='d')
		{
			step++;
			if(a[current_x][current_y+1]==END)
			{
				a[current_x][current_y]=RIGHT;
				a[current_x][current_y+1]=BEGIN;
				system("cls");
				printmap(); 
				printf("你已到达终点，游戏结束！总步数：%d步\n",step); 
				break;
			}
			if(a[current_x][current_y+1]==CAN)
			{
				a[current_x][current_y]=RIGHT;
				current_y++;
				a[current_x][current_y]=BEGIN;
				path[step].x=current_x;
				path[step].y=current_y;
			}			
		}
		else if(front=='w')
		{
			step++;
			if(a[current_x-1][current_y]==END)
			{
				a[current_x][current_y]=UP;
				a[current_x-1][current_y]=BEGIN;
				system("cls");
				printmap(); 
				printf("你已到达终点，游戏结束！总步数：%d步\n",step);
				break;
			}
			if(a[current_x-1][current_y]==CAN)
			{
				a[current_x][current_y]=UP;
				current_x--;
				a[current_x][current_y]=BEGIN;
				path[step].x=current_x;
				path[step].y=current_y;
			}
		}
		system("cls");
	printf("\n                                              游戏进行中\n\n");
	printmap();   
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


void print_point(int front){
	
//	用siwtch 打印出 八个点的图形
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
	printf("玩家所走的路径为：\n") ;
	printf("(%d,",bx);
	printf("%d)->",by);
	for(int i=1;i<step;i++)
	{
		printf("(%d,",path[i].x);
		printf("%d)->",path[i].y);
	}
	printf("(%d,",ex);
	printf("%d)",ey);
}

