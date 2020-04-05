#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int B[1000000];
void merge_sort(int [], int , int );
void merge (int [], int , int , int);
int main()
{
	int n;
	cin>>n;
	int A[n];
	for(int i=0;i<n; i++)
		scanf("%d",&A[i]);//cin>>A[i];
	//sort(A,A+n);
	merge_sort(A,0,n-1);
	for(int i=0;i<n;i++)
		printf("%d\n",A[i]);//cout<<A[i]<<endl;
	return 0;
}
void merge_sort(int A[],int low, int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		merge_sort(A,low,mid);
		merge_sort(A,mid+1,high);
		merge(A,low,mid,high);
	}
	return;
}
void merge(int A[], int low, int mid, int high)
{
	int i=low,j=high,p=low;
	i=p=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(A[i]<=A[j])
		{
			B[p]= A[i];
			i++;
			p++;
		}
		if(A[i]>A[j])
		{
			B[p]= A[j];
			j++;
			p++;
		}
	}
	while(i<=mid)
	{
		B[p]=A[i];
		i++;
		p++;
	}
	while(j<=high)
	{
		B[p]=A[j];
		j++;
		p++;
	}
	for(i=low;i<=high;i++)
	{
		A[i]=B[i];
	}
	return;
}
