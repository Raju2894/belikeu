#include<iostream>
#include<cmath>

using namespace std;

int g=0;
int pivot(int *a,int l,int h){
	cout << h << l << "pi\n";
	int pivot = a[l];
	int start = l+1;
	for(int i=l+1;i<=h;i++){
		if(a[i] <= pivot){
			int temp = a[i];
			a[i]=a[start];
			a[start] = temp;
			start++;
		}
	}
	int temp = a[l];
	a[l]=a[start-1];
	a[start-1] = temp;
	return start-1;
}
	
void quick(int *a,int l,int h){
	int pi=0;
	if(l>=h)
		return ;
	if(l<h){
		pi = pivot(a,l,h);
		cout << "index" << pi << "\n";
		quick(a,l,pi-1);
		quick(a,pi+1,h);
	}
}



int main(){
	int n;
	cin >> n;
	int *a = new int[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	
	quick(a,0,n-1);

	for(int i=0;i<n;i++)
		cout << a[i] <<" ";
	cout << "ad" << g << endl;	
	delete[] a;
	return 0;
}
