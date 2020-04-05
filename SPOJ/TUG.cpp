# include <iostream>
# include <cstring>

using namespace std;
int str[1000000];
int main ()
{
    ios_base::sync_with_stdio(false);
    int t,n,i,sum,flag,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum = 0;
        for(i =0; i<n; ++i)
        {
            cin>>str[i];
            sum+=str[i];
        }
        if(n>100)
        {
            cout<<"YES\n";
            continue;
        }
        //constructing the subset matrix.
        int subsetsum[n+1][sum+1];
        for(i=0;i<=n;++i)
            subsetsum[i][0] = 0;
        for(i=0;i<=sum;++i)
            subsetsum[0][i] = 0;
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=sum; ++j)
            {
                if(str[i-1] == j)
                {
                    subsetsum[i][j] = 1;
                }
                else if(str[i-1] < j)
                    subsetsum[i][j] = max(subsetsum[i-1][j], subsetsum[i-1][j-str[i-1]]);
                else
                    subsetsum[i][j] = subsetsum[i-1][j];
            }
        }
        flag =0;
        for(i=n;i>1 && flag==0;--i)
        {
            for(j=sum;j>0;--j)
            {
                if(subsetsum[i][j] && str[i-1]<j)
                {
                    if(subsetsum[i-1][j] && subsetsum[i-1][j-str[i-1]])
                    {
                        flag = 1;
                        break;
                    }
                }
                if(subsetsum[i][j] && str[i-1]==j)
                {
                    if(subsetsum[i-1][j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
