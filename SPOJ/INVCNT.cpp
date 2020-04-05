# include <iostream>

using namespace std;
int A[200005],temp[200005];
//int ans;

long long int count_and_sort(int,int);
long long int merge_and_count(int,int,int);

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,i;
	long long int ans; //ans is declared here
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans = 0;
		for(i=0 ; i<n ; ++i)
			cin>>A[i];
		ans = count_and_sort(0,n-1);
		cout<<ans<<'\n';
	}
	return 0;
}
long long int count_and_sort(int start, int end)
{
	if(start < end)
	{
		int mid = (start + end)/2;
		long long int x,y,z;
		x=count_and_sort(start,mid);
		y=count_and_sort(mid+1,end);
		z=merge_and_count(start,mid,end);
		return x+y+z;
	}
	else
		return 0;
}
long long int merge_and_count(int start,int mid, int end)
{
	int a,b,c;
	a=start;
	b=mid+1;
	c=start;
	long long int count = 0;
	while(a <= mid && b <=end)
	{
		if(A[a] < A[b])
		{
			temp[c] = A[a];
			c++;
			a++;
		}
		else if (A[a] > A[b])
		{
			temp[c] = A[b];
			count += (mid - a + 1);;
			b++;
			c++;			
		}
	}
	while(a <= mid)
	{
		temp[c] = A[a];
		a++;
		c++;
	}
	while(b <= end)
	{
		temp[c] = A[b];
		b++;
		c++;
	}
	for(int i= start; i<=end ;++i)
		A[i] = temp[i];
	return count;
}