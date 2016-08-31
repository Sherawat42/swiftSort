#include <iostream>
// #include <cstdlib>
using namespace std;

void merge(int arr[], int startI, int endI){
	int i = startI, j = 1+(startI+endI)/2;
	int l=0;
	for(;i<=(startI+endI)/2;i++){
		if(arr[i] > arr[j]){
			swap(arr[i],arr[j]);
			for(int l=j;l<endI && arr[l+1]<arr[l];l++){
				swap(arr[l], arr[l+1]);
				j=l;
			}
		}
	}
}

void sort(int arr[],int startI, int endI){
    if(startI<endI){
        sort(arr,startI,(startI+endI)/2);
        sort(arr,1+(startI+endI)/2,endI);
        merge(arr,startI,endI);
    }
}

void printArray(int arr[], int size){
	for(int i=0;i<size;i++)
		cout<<arr[i]<<endl;
}

int main(){
	float timeAverage = 0;
	clock_t t1,t2;
	for(int i=0; i<10;i++){
		int arr[1000000];
		for(int i=0;i<1000000;i++)
			arr[i] = rand()%1000000;
		// printArray(arr,1000000);
		// cout<<"Sorting...\n";
		t1 = clock();
		sort(arr,0,1000000-1);
		t2 = clock();
		timeAverage += ((float)t2-(float)t1)/CLOCKS_PER_SEC/10;
		// printArray(arr,100000010);
		// cout<<"Done"<<endl;
	}
	cout<<timeAverage<<endl;
}
