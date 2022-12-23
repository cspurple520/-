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
char ch;
void input();                        
void bande();
void move();                        
int main()
{
	system("color A1");
	input();
	move();
    return 0; 
}

void bande()
{	
	printf("\n                    您建立的迷宫如下：\n\n");
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	if(a[i][j])
				printf("  ");
			else 
				printf("▇ ") ;
		}
	    printf("\n");			 
	}
	printf("\n   请输入迷宫的起点(横纵坐标用空格隔开):    ");
	scanf("%d%d",&bx,&by);
	a[bx][by]=6;
	while(bx<1||by>rows||bx<1||by>cols||!a[bx][by]) 
	{
	   printf("\n   您输入的起点坐标有误，请重新输入:");
	   scanf("%d%d",&bx,&by);
	   a[bx][by]=6;
    } 
    printf("\n   请输入迷宫的终点,不能与起点坐标相同(横纵坐标用空格隔开):     ");
	scanf("%d%d",&ex,&ey);
	a[ex][ey]=7;
    while(ex<1||ex>rows||ey<1||ey>cols||!a[ex][ey]||(bx==ex&&by==ey))
    {
	   printf("\n   您输入的终点坐标有误，请重新输入:    ");
	   scanf("%d%d",&ex,&ey);
	   a[ex][ey]=7;
    }
	printf("\n                    您建立的迷宫完整迷宫如下：\n\n");
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	if(a[i][j]==1)
				printf("  ");
			else if(a[i][j]==6)
				printf("●");
			else if(a[i][j]==7) 
				printf("▲");
			else
				printf("▇ ") ;
		}
	    printf("\n");			 
	}    
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
	int bbx,bby;
	bbx=bx,bby=by;
	while(1)
	{
		ch=getch();
		if(ch=='s')
		{
			if(a[bbx+1][bby]==7)
			{
				printf("你已到达终点，游戏结束！"); 
				break;
			}
			if(a[bbx+1][bby]==1)
			{
				a[bbx][bby]=1;
				bbx++;
				a[bbx][bby]=6;
			}
		}
		else if(ch=='a')
		{
			if(a[bbx][bby-1]==7)
			{
				printf("你已到达终点，游戏结束！"); 
				break;
			}
			if(a[bbx][bby-1]==1)
			{
				a[bbx][bby]=1;
				bby--;
				a[bbx][bby]=6;
			}
			
		}			
		else if(ch=='d')
		{
			if(a[bbx][bby+1]==7)
			{
				printf("你已到达终点，游戏结束！"); 
				break;
			}
			if(a[bbx][bby+1]==1)
			{
				a[bbx][bby]=1;
				bby++;
				a[bbx][bby]=6;
			}			
		}
		else if(ch=='w')
		{
			if(a[bbx-1][bby]==7)
			{
				printf("你已到达终点，游戏结束！"); 
				break;
			}
			if(a[bbx-1][bby]==1)
			{
				a[bbx][bby]=1;
				bbx--;
				a[bbx][bby]=6;
			}
		}
		system("cls");
	printf("\n                                              游戏进行中\n\n");
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	if(a[i][j]==1)
				printf("  ");
			else if(a[i][j]==6)
				printf("●");
			else if(a[i][j]==7) 
				printf("▲");
			else
				printf("▇ ") ;
		}
	    printf("\n");			 
	}    
		if(bbx==ex&&bby==ey)
		{
			break;
		}
	}
}
