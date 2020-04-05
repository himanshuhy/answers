# include <iostream>
# include <cstdio>
using namespace std;
int main()
{
    int half=0,quarter=0,three_quarter=0;
    int total=1;
    int n;
    int a,b;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %*c %d",&a,&b);
        if(b==2)
            half++;
        else if(a==1)
            quarter++;
        else
            three_quarter++;
    }
    if(three_quarter > 0)
    {
        if(quarter >= three_quarter)
        {
            quarter-=three_quarter;
            total+=three_quarter;
            //three_quarter=0;
        }
        else
        {
            total+= three_quarter;
            quarter =0;
        }
    }
    if(half)
    {
        total += half/2;
        half=half%2;
        if(half)
        {
            if(quarter)
            {
                quarter-=2;
            }
            total++;
        }
    }
    if(quarter>0)
    {
        total += quarter/4;
        if(quarter%4)
            total++;
    }
    /*while(three_quarter)
    {
        if(quarter)
        {
            three_quarter--;
            quarter--;
            total++;
        }
        else
        {
            total += three_quarter;
        }
    }
    while(half)
    {
        if(half>=2)
        {
            total += half/2;
            half=half%2;
        }
        else
        {
            if(quarter)
            {
                quarter--;
                half--;
                total++;
            }
        }
    }
    if(quarter)
    {
        total += quarter/4;
        if(quarter%4)
            total++;
    }*/
    printf("%d\n",total);
    return 0;
}
