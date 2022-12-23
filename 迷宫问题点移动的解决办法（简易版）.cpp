#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
char a[20][20]={"#    ######",
                "#o# ##   ##",
			    "# ## # ####",
			    "#      # ##",
			    "# # ## ####",
			    "#  ### ####",
			    "#   ## ####",};
int main()
{
	int x,y;
	x=1;y=1;
	char ch;
	for(int i=0;i<=7;i++)
	{
		puts(a[i]);
	}
	while(1)
	{
		ch=getch();
		if(ch=='s')
		{
			if(a[x+1][y]==' ')
			{
				a[x][y]=' ';
				x++;
				a[x][y]='o';
			}
		}
		else if(ch=='a')
		{
			if(a[x][y-1]==' ')
			{
				a[x][y]=' ';
				y--;
				a[x][y]='o';
			}
     	}
		else if(ch=='d')
		{
			if(a[x][y+1]==' ')
			{
				a[x][y]=' ';
				y++;
				a[x][y]='o';
			}
		}
		else if(ch=='w')
		{
			if(a[x-1][y]==' ')
			{
				a[x][y]=' ';
				x--;
				a[x][y]='o';
			}
		}
		system("cls");
		for(int i=0;i<=7;i++)
		{
			puts(a[i]);
		}
		if(x==6&&y==6)
		{
			break;
		}
	}
}
