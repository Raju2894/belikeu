#include<iostream>

#include<stdio.h> 
#include<stdlib.h> // if we want to use malloc we need this library

using namespace std;

void merge(int  lc,int *left,int rc,int *right,int *a){
	int i=0,j=0,k=0,c=0;
	while(i < lc && j < rc){
		if(left[i] <= right[j]){
			a[k] = left[i];
			k++;
			i++;
		}
		else{
			a[k] = right[j];
			k++;
			j++;
		}
	}
	
	while(i<lc){
		a[k] = left[i];
			k++;
			i++;
	}
	while(j<rc){
		a[k] = right[j];
			k++;
			j++;
	}
	
}

void mergesort(int *a,int n){
    
	int mid;
	if(n<2)
		return;
	mid = n/2;
	int *left = new int[mid];
	int *right = new int[n-mid];
	for(int i=0;i<mid;i++)
		left[i]=a[i];
	for(int i=mid;i<n;i++)
		right[i-mid]=a[i];
	
	mergesort(left,mid);
	mergesort(right,n-mid);
	
	merge(mid,left,n-mid,right,a);	
	delete[] left;
	delete[] right;
}

	




int main(){
	int t;
	cout << "********************Merge Sort *************************\n";
	cout << "Enter no of test cases\n"; 
	cin >> t;
	while(t>0){
	cout << "Enter no of elements to be in array\n";
	int n;
	cin >> n;
	int *a = new int[n];//we can use (int*)malloc(n*sizeof(int));
	cout << "Enter array elements of size:" << n << "\n";
	//input scanning
	for(int i=0;i<n;i++)
		cin >> a[i];

	mergesort(a,n);
	// output printing
	cout << "sorted array:";
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
 
	cout <<"\n";
	//cout << "no of inversions:" << r << endl;
	cout <<"\n";

	// memory leak will not happen
	delete[] a;
	t--;
	}
	return 0;
}
