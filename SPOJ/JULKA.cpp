	# include <stdio.h>
	# include <string.h>
	void subtract (char*, char*);
	void correct (char* , int);
	int main()
	{
		char total[111],diff[111],temp;
		int start, end;
		for(int q=0 ; q<10 ; ++q)
		{
			int i;
			scanf("%s",total);
			scanf("%s",diff);
			//reversing the strings 
			start = 0;
			end =strlen(total) -1;
			while(start < end)
			{
				temp = total[start];
				total[start] = total[end];
				total[end] = temp;
				start ++;
				end --;
			}
			start = 0;
			end =strlen(diff) -1;
			while(start < end)
			{
				temp = diff[start];
				diff[start] = diff[end];
				diff[end] = temp;
				start ++;
				end --;
			}
			subtract(total,diff);
			//puts(total);
			start = 0;
			end =strlen(total) -1;
			while(start < end)
			{
				temp = total[start];
				total[start] = total[end];
				total[end] = temp;
				start ++;
				end --;
			}
			char K[111]="",N[111]="";
			int carry,k,j=0,div,len = strlen(total);
			for(i=0 ; i<len ; ++i)
			{
				div=int(total[i])-48;
				if(i==0 && div == 1)
				{
					total[i+1] = char (10 + int(total[i+1]) );
				}
				else
				{				
					K[j]=char( 48 + div/2 );
					if(div%2==1)
					{
						total[i+1] = char (10 + int(total[i+1]) );
					}
					j++;
				}
			}
			start = 0;
			end =strlen(K) -1;
			while(start < end)
			{
				temp = K[start];
				K[start] = K[end];
				K[end] = temp;
				start ++;
				end --;
			}
			i=strlen(K);
			j=strlen(diff);
			k=0;
			carry=0;
			if(i>=j)
			{
				for(k=0; k<j; ++k)
				{
					div = int(K[k])-48 + int(diff[k]) -48 + carry;
					N[k]= char( div%10 +48);
					carry=div/10;
				}
				for(k=j; k<i; ++k)
				{
					div = int(K[k])-48 + carry;
					N[k]= char( div%10 +48);
					carry=div/10;
				}
			}
			else
			{
				for(k=0; k<i; ++k)
				{
					div = int(K[k])-48 + int(diff[k]) -48 + carry;
					N[k]= char( div%10 +48);
					carry=div/10;
				}
				for(k=i; k<j; ++k)
				{
					div = int(diff[k]) -48 + carry;
					N[k]= char( div%10 +48);
					carry=div/10;
				}
			}
			if(carry !=0)
				N[k]=char(carry + 48);
			start = 0;
			end =strlen(N) -1;
			while(start < end)
			{
				temp = N[start];
				N[start] = N[end];
				N[end] = temp;
				start ++;
				end --;
			}
			start = 0;
			end =strlen(K) -1;
			while(start < end)
			{
				temp = K[start];
				K[start] = K[end];
				K[end] = temp;
				start ++;
				end --;
			}
			puts(N);
			//putchar('\n');
			puts(K);
			//putchar('\n');
		}
		return 0;
	}
	void subtract(char* total, char* diff)
	{
		int i,len = strlen(total);
		//printf("%d\n",len );
		for(i=0; i<len ; ++i)
		{
			if( int( total[i] ) >= int( diff[i] ) )
			{
				total[i] = char( int(total[i]) - int(diff[i]) +48 );
			}
			else
			{		
				total[i] = char( int(total[i]) + 10 );
				total[i+1] = char( int(total[i+1]) - 1 );
				if(int(total[i+1]) <48 )
				{
					correct(total,i+1);
				}
				total[i] = char( int(total[i]) - int(diff[i]) +48 );
			}
			if(diff[i+1]=='\0')
			{
				break;
			}
		}
		i=strlen(total)-1;
		while(total[i]=='0' && i!=0)
		{
			total[i]='\0';
			i--;
		}
	}
void correct(char * total, int i)
{
	total[i] = char( int(total[i]) + 10 );
	total[i+1] = char( int(total[i+1]) - 1 );
	if(int(total[i+1]) <48 )
		{
			correct(total,i+1);
		}
	else
		return;
}