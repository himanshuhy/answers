# include <iostream>
# include <cstdio> //scanf("",);
using namespace std;
int SEQ[8];//answer to all the 8 sequence for all the answers
char str[40];
int main ()
{
	int p;
	int flag;//this flag has four(4) values
	scanf("%d",&p);
	for(int i=0;i<p;++i)
	{
		scanf("%*d %s",str);
		if(str[0]=='T')//T
		{
			if(str[1] == 'T')//TT
			{
				if(str[2]=='T')//TTT
				{
					flag =0;
					SEQ[0]++;
				}
				else//TTH
				{
					flag =1;
					SEQ[1]++;
				}
			}
			else//TH
			{
				if(str[2]=='T')//THT
				{
					flag =2;
					SEQ[2]++;
				}
				else//THH
				{
					flag =3;
					SEQ[3]++;
				}
			}
		}
		else//H
		{
			if(str[1] == 'T')//HT
			{
				if(str[2]=='T')//HTT
				{
					flag =0;
					SEQ[4]++;
				}
				else//HTH
				{
					flag =1;
					SEQ[5]++;
				}
			}
			else//HH
			{
				if(str[2]=='T')//HHT
				{
					flag =2;
					SEQ[6]++;
				}
				else//HHH
				{
					flag =3;
					SEQ[7]++;
				}
			}
		}
		for(int j=3;j<40;j++)
		{
			if(str[j]=='T')
			{
				if(flag==0)
				{
					SEQ[0]++;
				}
				else if(flag==1)
				{
					flag=2;
					SEQ[2]++;
				}
				else if(flag==2)
				{
					flag=0;
					SEQ[4]++;
				}
				else if(flag==3)
				{
					flag =2;
					SEQ[6]++;
				}
			}
			else
			{
				if(flag==0)
				{
					flag=1;
					SEQ[1]++;
				}
				else if(flag==1)
				{
					flag=3;
					SEQ[3]++;
				}
				else if(flag==2)
				{
					flag=1;
					SEQ[5]++;
				}
				else if(flag==3)
				{
					SEQ[7]++;
				}
			}
			//cout<<"j="<<j<<" "<<flag<<endl;
		}
		printf("%d",i+1);
		for(int j=0;j<8;j++)
		{
			printf(" %d",SEQ[j]);
			SEQ[j]=0;
		}
		printf("\n");
	}
	return 0;
}
