#include<iostream>
#include<cmath>

using namespace std;

int g=0,k=0;

void swap(int *a,int *b){
	int *temp = a;
	a=b;
	b=temp;
}

int pivot(int *a,int l,int h){
	int pivot = a[h];
	int pivot1 = a[l];
	int s = l,r=l;
	int f=0;
	if(f==0){
	for(int i=l;i<h;i++){
		if(a[i] <= pivot){
			swap(a[i],a[s]);
			g++;
			s++;
		}
	}
	f=1;
	}
	else if(f==1){
		for(int i=l;i<h;i++){
			if(a[i] <= pivot){
				swap(a[i],a[r]);
				k++;
				r++;
			}
	}
	}

	swap(a[s],a[h]);
	g++;
	k++;
	return s;
}


void quicksort(int *a, int l,int h){
	int pi;
	if(l < h){
		pi = pivot(a,l,h);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,h);
	}
}


int main(){
	int t;
	cin >> t;
	while(t>0){
		int n;
		cin >> n;
		int *a = new int[n];
		for(int i=0;i<n;i++)
			cin >> a[i];


		quicksort(a,0,n-1);

		cout <<"" <<  k << g << endl;
		for(int i=0;i<n;i++)
			cout << a[i] << " ";


		t--;
	}
	return 0;
}
