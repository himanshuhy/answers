#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char stack[400];
int top=-1;
void push (char );
char pop ();
int priority (char );
int main (void)
{
	int t;
	char temp,inp[400];
	scanf("%d",&t);
	for (int i = 0; i < t ; ++i) // check power condition also
	{
		scanf("%s",inp);
		for (int j = 0; j < strlen(inp) ; ++j)
		{
			if(inp[j] >= 97 && inp[j]<= 122)
				printf("%c",inp[j]);
			else if(inp[j] =='(')
			{
				push(inp[j]);
			}
			else if(inp[j]== ')')
			{
				while(1)
				{
					temp=pop();
					if(temp=='(')
						break;
					else
					{
						printf("%c",temp);
					}
				}
			}						
			else if ( top >= 0)
			{
				if(priority(inp[j]) > priority(stack[top]))
					push(inp[j]);
				else if (priority (inp[j]) < priority(stack[top]) )
				{
					while (priority (inp[j]) < priority(stack[top]) && top>=0)
					{
						temp = pop();
						printf("%c",temp);
					}
					push(inp[j]);
				}
			}
			else
				push(inp[j]);
		}
		while(top>=0)
		{
			temp=pop();
			printf("%c",temp);
		}
		printf("\n");
	}
	return 0;
}
void push(char x)
{
	if(top<399) // int this question we actually dont need this as we control the size of input
	{
		top++;
		stack[top] = x;
	}
}
char pop ()
{
	if(top > -1)
	{
		top--;
		return stack[top+1];
	}
}
int priority(char x)
{
	if (int (x) == 43 )
		return 0;
	else if (int (x)== 45 )
		return 1;
	else if (int (x) == 42 )
		return 3;
	else if (int (x) == 47 )
		return 4;
	else if (int (x) == 94 )
		return 5;
	/*else if (int (x) == 40 )
		return 6;
	else if (int (x) == 41 )
		return 7;*/
	else
		return -1;
}
