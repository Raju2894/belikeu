#include<iostream>
#include<cmath>
#include<stdlib.h>

using namespace std;


int merge(int *a,int *temp,int l,int m,int h){
	int i,j,k,inverseCount=0;
	i=l;j=m;k=l;
	while(i<=m-1&&j<=h){
		if(a[i] <= a[j]){
			temp[k]=a[i];
			i++;
			k++;
		}
		else{
			temp[k]=a[j];
			k++;
			j++;
			inverseCount += m-i;
		}
	}
	while(i<=m-1){
		temp[k] = a[i];
		i++;
		k++;
	}
	while(j<=h){
		temp[k] = a[j];
		k++;
		j++;
	}
	while(l<=h){
		a[l] = temp[l];
		l++;
	}

	return inverseCount;
}


int mergeSort(int *a,int *temp,int l,int h){
	int inversionCount=0,mid;
	if(h>l){
		mid = (l+h)/2;
		inversionCount=mergeSort(a,temp,l,mid);
		inversionCount+=mergeSort(a,temp,mid+1,h);
		inversionCount+=merge(a,temp,l,mid+1,h);
	}

	return inversionCount;
}

int _mergeSort(int *a,int n){
	int *temp = new int[n];
	int r = mergeSort(a,temp,0,n-1);
	return r;
}

int main()
{       
	int t; 
	cout << "******************** Merge Sort *************************\n";
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

	int r = _mergeSort(a,n);
	// output printing
	cout << "sorted array:";
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
 
	cout <<"\n";
	cout << "no of inversions:" << r << endl;
	cout <<"\n";

	// memory leak will not happen
	delete[] a;
	t--;
	}

	return 0;
}

