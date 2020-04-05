# include <iostream>
# include <cstdio> //scanf() AND printf()
# include <vector>
# include <algorithm>

using namespace std;

int main ()
{
    int t,n,c;
    int i,j,temp_c,piv;
    int lo,hi,mid;
    vector <int> x(100008,0);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&c);
        for(i = 0 ;  i < n ; ++i)
        {
            scanf("%d",&x[i]);
        }
        sort(x.begin(),x.begin()+n);
        lo = 1;
        hi = *(x.begin()+n-1)-*x.begin();
        int round = 0;
        while(lo < hi)
        {
            mid = lo + (hi-lo+1)/2; //is this correct for this application?
            piv = x[0];
            temp_c = c-1;
            for(j=1 ; (j < n)&& temp_c ; j++)
            {
                if(x[j] - piv >= mid)
                {
                    temp_c--;
                    piv = x[j];
                }
            }
            if(!temp_c) //temp_c == 0
            {
                lo = mid;
            }
            else
            {
                hi = mid-1;//sure?
            }
        }
        printf("%d\n",hi);
        //every question will have an answer.
    }
    return 0;
}
