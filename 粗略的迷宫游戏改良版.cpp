#include<bits/stdc++.h>
#include<conio.h>
#define Maxsize 101                  
using namespace std;
int x[4]={0,-1,0,1},y[4]={-1,0,1,0};     //�������� 
bool had[Maxsize][Maxsize];              //��ͼ�����Ƿ��߹� 
int a[Maxsize][Maxsize];
struct 
{
    int a;                        //����� �Ƿ� 
	int d;                       //���� 
}ans[Maxsize][Maxsize];
int walk[5000][2];
int rows,cols,n,summ=0,steps=0,minn=10001,want=-1;   //��������,�ϰ������,·������,��������ʾ��·�� 
int every; 
int bx,by,ex,ey;                      //�����Թ���ʼ�ĵط��;�ͷ; 
typedef struct
{ 
    int x;
    int y;
    int k;
}point;                            //�����Ľṹ�� 
point path[10005],sp[10005];
int top=-1;                      //ջ��
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
	printf("\n                    ���������Թ����£�\n\n");
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	if(a[i][j])
				printf("  ");
			else 
				printf("�~ ") ;
		}
	    printf("\n");			 
	}
	printf("\n   �������Թ������(���������ÿո����):    ");
	scanf("%d%d",&bx,&by);
	a[bx][by]=6;
	while(bx<1||by>rows||bx<1||by>cols||!a[bx][by]) 
	{
	   printf("\n   ����������������������������:");
	   scanf("%d%d",&bx,&by);
	   a[bx][by]=6;
    } 
    printf("\n   �������Թ����յ�,���������������ͬ(���������ÿո����):     ");
	scanf("%d%d",&ex,&ey);
	a[ex][ey]=7;
    while(ex<1||ex>rows||ey<1||ey>cols||!a[ex][ey]||(bx==ex&&by==ey))
    {
	   printf("\n   ��������յ�������������������:    ");
	   scanf("%d%d",&ex,&ey);
	   a[ex][ey]=7;
    }
	printf("\n                    ���������Թ������Թ����£�\n\n");
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	if(a[i][j]==1)
				printf("  ");
			else if(a[i][j]==6)
				printf("��");
			else if(a[i][j]==7) 
				printf("��");
			else
				printf("�~ ") ;
		}
	    printf("\n");			 
	}    
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
				printf("���ѵ����յ㣬��Ϸ������"); 
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
				printf("���ѵ����յ㣬��Ϸ������"); 
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
				printf("���ѵ����յ㣬��Ϸ������"); 
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
				printf("���ѵ����յ㣬��Ϸ������"); 
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
	printf("\n                                              ��Ϸ������\n\n");
	for(int i=0;i<=rows+1;i++)
	{     
		printf("                               ");
	    for(int j=0;j<=cols+1;j++)
	    {
	    	if(a[i][j]==1)
				printf("  ");
			else if(a[i][j]==6)
				printf("��");
			else if(a[i][j]==7) 
				printf("��");
			else
				printf("�~ ") ;
		}
	    printf("\n");			 
	}    
		if(bbx==ex&&bby==ey)
		{
			break;
		}
	}
}
