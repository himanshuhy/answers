# include <iostream>
# include <cstdio>
using namespace std;
int A2[5000]={0,1},A1[10000000]={0,1};
int main()
{
	int t,inp,count=1,num,den,diff;
	scanf("%d",&t);
	for(int i=0; i < t ; ++i)
	{
		scanf("%d",&inp);
		//cin>>inp;
		/*num=0;
		den=0;*/
		while(A1[inp]==0)
		{
			count++;
			A2[count] = A2[count-1] + count;
			for(int k= A2[count-1]+1; k<= A2[count] ; ++k)
			{
				A1[k] = count;
			}
		}
		diff = inp - A2[A1[inp] - 1]-1;
		//cout<<"diff = "<<diff<<endl;
		if(A1[inp]%2 == 0)//even
		{
			num = 1 + diff;
			den = A1[inp] -diff;
		}
		else
		{
			den = 1 + diff;
			num = A1[inp] -diff;
		}
		printf("TERM %d IS %d/%d\n",inp,num,den);
	}
	return 0;
}
