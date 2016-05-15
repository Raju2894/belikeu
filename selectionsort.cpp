#include<iostream>

#include<stdio.h> 
#include<stdlib.h> // if we want to use malloc we need this library

using namespace std;

int selectionsort(int *p,int n){
	int minindex,j,i,c=0,f=0;
	for( i=0;i<n-1;i++){
		minindex = i;
		f=0;
		for(j=i+1;j<n;j++){
			if(p[j]<p[minindex]){
				minindex=j;
			}
		}
		if(minindex!=i){
		int temp = p[i];
		p[i]=p[minindex];
		p[minindex]=temp;
		c++;
		}
	}
	return c;
}


int main(){
	int t;
	cout << "********************Selection Sort *************************\n";
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

	int r=selectionsort(a,n);
	// output printing
	cout << "sorted array:";
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
 
	cout <<"\n";
	cout << "minimum number of swaps:" << r << "\n";
	cout <<"\n";

	// memory leak will not happen
	delete[] a;
	t--;
	}
	return 0;
}
