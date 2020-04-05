# include <iostream>
using namespace std;
int station[100001];
int main ()
{
    ios_base::sync_with_stdio(false);
    int t,At,Bt,i,count,min_sum,max_station,j,sum;
    cin>>t;
    while(t--)
    {
        cin>>At>>Bt;
        for(i=0; i<At; ++i)
            cin>>station[i];
        i = j = min_sum = max_station = sum = count = 0;
        while(station[i] > Bt && i<At)
        	i++;
        if(i==At)
        {
        	cout<<"0 0\n";
        	continue;
        }
        j = i; //j is start variable
        min_sum = sum = station[i];
        max_station = count = 1;
        while(++i < At)
        {
        	if(sum + station[i] <= Bt)
        	{
        		sum += station[i];
        		count++;
        		if(count > max_station)
        		{
        			max_station = count;
        			min_sum = sum;
        		}
        		else if(count == max_station)
        		{
        			if(sum < min_sum)
        				min_sum = sum;
        		}
        	}
        	else
        	{
        		if(station[i]<=Bt)
        		{
        			sum+=station[i];
        			count++;
        			while(sum > Bt)
        			{
        				sum -= station[j++];
        				count--;
        			}
        			if(count == max_station)
        				if(sum < min_sum)
        					min_sum = sum;
        		}
        		else
        		{
        			while(station[i] >Bt && i < At)
        			{
        				i++;
        			}
        			if(i==At)
        			{
        				break;
        			}
        			j = i;
        			sum = station[i];
        			count = 1;
        			if(count == max_station)
        			{
        				if(sum < min_sum)
        					min_sum = sum;
        			}
        		}
        	}
        }
        cout<<min_sum<<' '<<max_station<<'\n';
    }
    return 0;
}
