# include <iostream>
# include <algorithm>
using namespace std;
int calculate(int, int*, int);
int find(int* ,int ,int, int);
int main ()
{
	ios_base::sync_with_stdio(false);
	int t,n1,n2,temp;
	//int alt1[1001],alt2[1001],ans[1001];
	cin>>t;
	while(t--)
	{
		int alt1[10009],alt2[10009],ans[10009];
		cin>>n1;
		for(int i=0;i<n1;++i)
			cin>>alt1[i];
		cin>>n2;
		for(int i=0;i<n2;++i)
			cin>>alt2[i];
		sort(alt1,alt1+n1);
		sort(alt2,alt2+n2);
		if(n1==0 || n2==0)
		{
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<n1;++i)
		{
			if(i>0 && alt1[i]==alt1[i-1])
				ans[i] = ans[i-1];
			else
			{
				ans[i] = calculate(alt1[i],alt2,n2);
			}
		}
		cout<<*min_element(ans,ans+n1)<<'\n';
	}
	return 0;
}
int calculate(int element, int *arr, int n)
{
	int lo=0,hi=n-1;
	int index;
	index = find(arr,lo,hi,element);
	if(arr[index] == element)
		return 0;
	else if(arr[index] < element)
	{
		while(index<n-1 && element - arr[index+1] >0)
			index++;
		if(index == n-1)
			return element - arr[index];
		return min(element - arr[index],arr[index+1]-element);
	}
	else if(arr[index] > element)
	{
		while(index>0 &&arr[index-1] - element >0)
			index--;
		if(index == 0)
			return arr[index]-element;
		return min(element - arr[index-1],arr[index]-element);
	}
}

int find(int *arr,int lo, int hi, int element)
{
	if(lo < hi)
	{
		int mid = (lo+hi)/2;
		if(arr[mid]==element)
			return mid;
		else if (arr[mid] < element)
		{
			return find(arr,mid+1,hi,element);
		}
		else if(arr[mid] > element)
		{
			return find(arr,lo,mid-1,element);
		}
	}
	else //lo == hi
		return lo;
}