/*
Himanshu Yadav
2K13 DTU
*/
# include <iostream>
# include <cstring>
# include <stack>
using namespace std;
char a[100],b[100],ans[100][100];
int m,n,i,j,dp[101][101];
void printlcs(int,int);
int main ()
{
    //dp[i][j] stores LCS upto a[i] and b[j]
    //ans[i][j] stores where the max value is. l==left,t==top,d==diagonal
    //stack to implement recursion
    while(cin>>a&&cin>>b)
    {
        m = strlen(a);
        n = strlen(b);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans[i-1][j-1] = 'd';
                }
                else
                {
                    if(dp[i-1][j]>=dp[i][j-1])
                    {
                        dp[i][j] = dp[i-1][j];
                        ans[i-1][j-1] = 't';
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1];
                        ans[i-1][j-1] = 'l';
                    }
                }
            }
        }
        printlcs(m,n);
        cout<<"\n";
    }
    return 0;
}
void printlcs(int p,int q)
{
    if(p==0&&q==0)
        return;
    if(p==0)
    {
        printlcs(p,q-1);
        cout<<b[q-1];
    }
    else if(q==0)
    {
        printlcs(p-1,q);
        cout<<a[p-1];
    }
    else
    {
        if(ans[p-1][q-1]=='d')
        {
            printlcs(p-1,q-1);
            cout<<a[p-1];
        }
        else if(ans[p-1][q-1]=='l')
        {
            printlcs(p,q-1);
            cout<<b[q-1];
        }
        else
        {
            printlcs(p-1,q);
            cout<<a[p-1];
        }
    }
}
