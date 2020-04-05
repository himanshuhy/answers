# include <iostream>
# include <cstdio>

#define scd(x) scanf("%d",&x);
#define maximum(a,b) (a>b)?a:b
using namespace std;

int cost[105];
int fun[105];
int bud,n,pres_bud,pres_fun;
int ans[505][105];

void calculate_and_print();

int main ()
{
    scd(bud);
    scd(n);
    while(bud && n)
    {
        for(int i =0; i<n ; ++i)
        {
            scd(cost[i]);
            scd(fun[i]);
        }

        calculate_and_print();
        scd(bud);
        scd(n);
    }
    return 0;
}

void calculate_and_print()
{
    pres_bud = 0;
    int i,j;
    for(i=0; i<= bud; ++i)
    {
        for(j=0 ; j<= n ; ++j)
        {
            if(i==0 || j==0)
                ans[i][j] = 0;
            else
            {
                if(cost[j-1] <= i )
                    ans[i][j] = maximum( ans[i][j-1] , fun[j-1] + ans[i-cost[j-1]][j-1] );
                else
                    ans[i][j] = ans[i][j-1];
            }
        }
    }
    int max = ans[bud][n] ;
    for(i=1;i<=bud && pres_bud ==0;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(ans[i][j] == max)
            {
                pres_bud = i;
                break;
            }
        }
    }
    printf("%d %d \n",pres_bud,ans[bud][n]);
    return ;
}
