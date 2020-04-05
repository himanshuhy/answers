#include <iostream>
#include <cstdio> //scanf("",);
#include <cmath>
using namespace std;
int main ()
{
    int n;
    float temp;
    scanf("%d",&n);
    while (n!= -1)
    {
        if(n%2)
        {
            n = n-1;
            if(n%3)
            {
                printf("N\n");
            }
            else
            {
                n = n/3;
                n = 4*n +1;
                temp = sqrt(n) - 1;
                temp=temp/2;
                if(temp - floor(temp)) //
                    printf("N\n");
                else
                    printf("Y\n");
            }
        }
        else
        {
            printf("N\n");
        }
        scanf("%d",&n);
    }
    return 0;
}
