/*VERSION 1 .. */
#include<iostream>
using namespace std;

void merge(int a[],int p,int q,int r);
void mergesort(int a[],int p,int r){
	
	if(p<r)
	{
		int q=(p+r)/2;
		mergesort(a,p,q);           //sorting leftpart first -i.e- dividing
		mergesort(a,q+1,r);         //sorting rightpart after first -i.e- dividing
		merge(a,p,q,r);             // solving and merging !!
	}
	
}
void merge(int a[],int p,int q,int r)
{
	
	int *array1,*array2,lft,ryt;
	lft=q-p+1;
	ryt=r-q;
	array1=new int [lft];                      //Allocating new left sub array dynamically
	array2=new int [ryt];                      ////Allocating new right sub array dynamically
	for(int i=0;i<lft;i++)
	{
		array1[i]=a[p+i];
	}
	for(int i=0;i<ryt;i++)
	{
		array2[i]=a[q+1+i];
	}	
	int i=0,j=0,k=p;                           //initialising k=p as it is the base index for main array (**imp)
	while(i<lft && j<ryt)                     // Comparing the lft and ryt sub array
	{
		if(array1[i]<array2[j] )
		{
			a[k++]=array1[i++];
		}
		else
		{
			a[k++]=array2[j++];
		}
	}
	while(i<lft)                         // copying remaining subarray from lft to main
	{
		a[k++]=array1[i++];
	}
	while(j<ryt)                         //// copying remaining subarray from ryt to main
	{
		a[k++]=array2[j++];
	}
	return;
}

int main()
{
	int n;
	cout<<"enter no of elements to be sorted\n";
	cin>>n;
	int *arr=new int[n];
	cout <<"Enter the elements \n";
	for(int i=0;i<n;i++)
	{
		cin>>*(arr+i);
	}
	mergesort(arr,0,n-1);
	cout<< "elements in sorted order are :\n";
	for(int i=0;i<n;i++)
	{
		cout<<*arr++<<" ";
	}
	cout<<endl;
	return 0;
}
