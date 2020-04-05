# include <iostream>
# include <cstdio>
using namespace std;
int n,m,yey[500][500],blo[500][500],ans[501][501];

int main ()
{
    scanf("%d %d",&n,&m);

    while(n!=0&&m!=0)
    {
        //yeyenum
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
            {
                scanf("%d",&yey[i][j]);
                if(j!=0)
                    yey[i][j]+=yey[i][j-1];
            }
        //bloggium
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
            {
                scanf("%d",&blo[i][j]);
                if(i!=0)
                    blo[i][j]+=blo[i-1][j];
            }
        //main calculations
        for(int i=0; i<=n; ++i)
            ans[i][0] = 0;
        for(int i=0; i<=m; ++i)
            ans[0][i] = 0;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                ans[i][j] = max(yey[i-1][j-1]+ans[i-1][j],blo[i-1][j-1]+ans[i][j-1]);
            }
        printf("%d\n",ans[n][m]);
        scanf("%d %d",&n,&m);
    }
    return 0;
}
