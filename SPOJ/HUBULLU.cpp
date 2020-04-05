# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
	int t,start;
	scanf("%d",&t);
	for (int i=0 ; i<t ; ++i)
	{
		scanf("%*d %d",&start);
		if(start == 0)
		{
			printf("Airborne wins.\n");
		}
		else
		{
			printf("Pagfloyd wins.\n");
		}
	}
	return 0;
}
