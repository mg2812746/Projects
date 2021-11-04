#include <iostream>

using namespace std;
int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array
int main(){
	//your code here
	int size;   //Number of elements in array
	int *ptr;   //Original Array
	int *aug;   //Augmented array
	//Read the array size and return pointer to array
	ptr=getData(size);
	//Augnment the array and copy the original array
	aug=augment(ptr,size);
	//Print the array
	prntAry(ptr,size);
	cout<<'\n';
	prntAry(aug,size+1);
	//Cleanup
	delete [] ptr;
	delete [] aug;
	return 0;
}
//Read the array
int *getData(int &size){
    cin>>size;
    int *p=new int [size];
    for(int i=0;i<size;i++){
        cin>>p[i];
    }
    return p;
}
//Augment and copy the original array
int *augment(const int *arr,int size){
    int *a=new int [size+1];
    a[0]=0;
    for(int i=0;i<size;i++){
        a[i+1]=arr[i];
    }
    return a;
}
//Print the array
void prntAry(const int *arr,int size){
    for(int i=0;i<size;i++){
        i==size-1?cout<<arr[i]:cout<<arr[i]<<" ";
    }
}