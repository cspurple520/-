#include"admin.h"
#include"maze.h"

using namespace std;

const int ADMIN = 1;
const int MAZE = 2;
int main()
{
	while(1)
	{
		int type;
		system("cls");
		printf("case:%d����adminģʽ\n",ADMIN);
		printf("case:%d����maze\n",MAZE);
		scanf("%d",&type);
		if (type == ADMIN)
		{	
		system("cls");
			admin();
			if(in==RETURN) 
			{
				continue;
			}
		}		
		else if (type == MAZE)
		{
			system("cls");
			maze(); 
		}
	}	
}
