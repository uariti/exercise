//============================================================================
// Name        : quicksort.cpp
// Author      : Marco Aurelio
// Version     :
// Copyright   : free
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void quickSort (int array[], int p, int r);
int partition (int array[], int p, int r);
void printa ( int A[], int size ) {
	cout << "a:";
	for(int i=0;i<size;i++) {
		cout << A[i] << ",";
	}
	cout << endl;
}
int size=0;

int main() {
	int a[] = { 8,2,6,1,5,6,7,8,1,3,0,2,3,4,7 };
	size =  (int) (sizeof(a)/sizeof(a[0]));
	cout << size << endl;
//	partition( a, 0, size -2);
//	printa( a, size);

	quickSort ( a, 0, size - 1 );
	printa( a, size);
	cout << "O imundo" << endl; // prints O imundo
	return 0;
}
void exchange(int A[],int i,int j) {
	int ttt=A[i];
	A[i]=A[j];
	A[j]=ttt;
}

int partition ( int A[], int p, int r) {
	int x=A[r];
	int i = p-1;
	for (int j=p;j<=r-1;j++ ){
		if (A[j] <= x) {
			i++;
			exchange(A,i,j);
		}
	}
	exchange(A,i+1,r);
	return i+1;
}

void quickSort (int A[], int p, int r){
	if ( p < r ) {
		cout << p << " " << r << " > ";
		printa( A, size );
		int q=partition( A, p, r);
		quickSort( A, p, q-1);
		quickSort( A, q+1, r);
	}
}
