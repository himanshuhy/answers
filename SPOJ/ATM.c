#include<stdio.h>
#include<stdlib.h>
int main()
{
	int out;
	float bal;
	scanf("%d",&out);
	scanf("%f",&bal);
	if(out <= (bal - 0.50) )
	{
		if(out%5==0)
		{
			bal = bal - (out+0.5);
		}
	}
	printf("%.2f\n",bal);
	return 0;
}