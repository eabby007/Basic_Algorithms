/* RANDOMISED QUICKSORT */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void swp(int &a,int &b)
{
	int t=a;
	    a=b;
	    b=t;
}

int partition(int *a,int p,int r)
{
	int x=a[r];            // choosing a pivot element.
	int i=p,j=r;
	while(1)
	{
		while(1)       // wherever we find a no. which is less than or equal to pivot* element we mark its location
			{
				if(a[j]<=x)
				break;
				j--;
			}
		
		while(1)       // same as above 
			{
				if(a[i]>=x)
				break;
				i++;
			}
		if(i<j)
			swp(a[i],a[j]); // swaping because the element on left side is greater than pivot.
		else
			return j;
	}
	
	
}

int rand_partition(int *a,int p,int r)      // generating random no. between (p and r)**
{
	srand(time(NULL));
	int ran= rand()%(r-p+1);  // p<=ran<=r
	ran+=p;
	swp(a[ran],a[r]);
	return partition(a,p,r);
}



void quicksort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=rand_partition(a,p,r);
		quicksort(a,p,q-1);            // recursive on less than pivot element
		quicksort(a,q+1,r);            // recursive on greater tha pivot element
		
	}
	
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
	quicksort(arr,0,n-1);
	cout<< "elements in sorted order are :\n";
	for(int i=0;i<n;i++)
	{
		cout<<*arr++<<" ";
	}
	cout<<endl;
	return 0;
}
