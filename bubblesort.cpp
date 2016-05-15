#include<iostream>
#include<cstdio>
#include<cmath>
// Include headers as needed

using namespace std;

int main()
{
	cout << "****************** Bubble Sort ***********************\n";
	cout << "enter no of test cases\n";
	int t;
	cin >> t;
	while(t>0){
		// Write your code here
		int n;
		cout << "enter no of elements to be in array\n";
		cin >> n;
		int a[n];
		cout << "enter array elements of" << n << "size\n";
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int i,j,count=0,flag=0;;
		for(i=0;i<n;i++){
			flag=0;
			for(j=0;j<n-1;j++){
				if(a[j] > a[j+1]){
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
					flag=1;
					count++;
				}
			}
			if(flag==0)
				break;
		}
		cout << "Total no of swaps required to sort in increasing is :" << count;
		cout << "\n" << "\n";
		
		t--;
	}
	cout << "********************* End ********************\n";
	// Return 0 to indicate normal termination
	return 0;
}

