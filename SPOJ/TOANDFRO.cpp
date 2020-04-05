#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char inp[200];
void change_order (int, int);
int main()
{
	int col,row,len,k;
	while(1)
	{
		scanf("%d",&col);
		if(col==0)
			break;
		else
		{
			scanf("%s",inp);
			len	= strlen(inp);
			row=len/col;
			int i;
			char matrix[row][col];
			for (i = col; i < len; i=i+2*col)
			{
				change_order(i,col);
			}
			k=0;
			for(int i=0;i<row;++i)
			{
				for(int j=0; j<col; ++j)
				{
					matrix[i][j]=inp[k];
					k++;
				}
			}
			for(int i=0; i<col; ++i)
			{
				for(int j= i ; j < len; j = j + col)
				{
					printf("%c",inp[j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
void change_order(int low,int col)
{
	int high=low + col -1;
	char temp;
	while(high>low)
	{
		temp=inp[low];
		inp[low]=inp[high];
		inp[high]=temp;
		low++;
		high--;
	}
}
