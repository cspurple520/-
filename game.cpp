#include"admin.h"
#include"maze.h"
using namespace std;

const int ADMIN = 1;
const int MAZE = 2;
int main()
{
	int type;
	printf("case:%d进入admin模式\n",ADMIN);
	printf("case:%d进入maze\n",MAZE);
	scanf("%d",&type);
	if (type == ADMIN)
		admin();
	else if (type == MAZE)
		maze();
	return 0;
}
