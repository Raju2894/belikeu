#include<iostream>
#include<cmath>

using namespace std;



int quick(int arr[], int left, int right) //quicksort takes an array, the leftmost index and the rightmost index
{
	  int comparison = 0;
      int i = left;
	  int j = right;
	  int tmp;
	  int pivot = arr[(left + right) / 2];
      /* partition */
      while (i <= j) {
			comparison++;
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quick(arr, left, j);
      if (i < right)
            quick(arr, i, right);
	  
	  return comparison;
}

int main(){
	int t;
	cin >> t;
	while(t>0){
		int n;
		cin >> n;
		int *a = new int[n];
		int *b = new int[n];		
		for(int i=0;i<n;i++){
			cin >> a[i];
			b[i] = a[i];
		}
		int g=quick(a,0,n-1);
		
		cout <<"df" << g << endl;
		for(int i=0;i<n;i++)
			cout << a[i] << " ";


		t--;
	}
	return 0;
}

