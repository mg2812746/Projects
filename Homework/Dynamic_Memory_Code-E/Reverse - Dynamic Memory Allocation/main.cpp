#include <iostream>
using namespace std;
//Function Prototypes
int *getData(int &);            //Fill the array
int *sort(const int *,int);     //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int);  //Print the array
int main(){
	//your code here
	int *ptr;
	int *srt;
	int *rev;
	int size;
	//Input array size and Create array
	ptr=getData(size);
	//Sort array in ascending order
	srt=sort(ptr,size);
	//Sort array in descending order
	rev=reverse(srt,size);
	//Display Data of sorted array and reversed array
	prntDat(srt,size);
	cout<<endl;
	prntDat(rev,size);
	//Cleanup
	delete [] ptr;
	delete [] srt;
	delete [] rev;
	return 0;
}
//Function Implementations
int *getData(int &size){
    cin>>size;
    int *p=new int [size];
    for(int i=0;i<size;i++){
        cin>>p[i];
    }
    return p;
}
int *sort(const int *arr,int size){
    //Dynamically allocate new array
    int *srt= new int [size];
    //Copy original array to new array
    for(int i=0;i<size;i++){
        srt[i]=arr[i];
    }
    int indx,   //Index value
        min;    //smaller value
    //Sort the copy and return the sorted array pointer
    for(int i=0;i<size-1;i++){
        indx=i;
        min=srt[i];
        for(int j=i+1;j<size;j++){
            if(srt[j]<min){
                min=srt[j];
                indx=j;
            }
        }
        srt[indx]=srt[i];
        srt[i]=min;
    }
    return srt;
}
int *reverse(const int *arr,int size){
    int *rev= new int [size];
    //Copy sorted array to new array
    for(int i=0;i<size;i++){
        rev[i]=arr[i];
    }
    //Reverse order of the new array
    int indx,   //Index value
        max;    //larger value
    //Sort the copy in reverse order and return the reversed array pointer
    for(int i=0;i<size-1;i++){
        indx=i;
        max=rev[i];
        for(int j=i+1;j<size;j++){
            max=rev[j];
            indx=j;
            rev[indx]=rev[i];
            rev[i]=max;
        }
    }
    return rev;
}
void prntDat(const int *arr,int size){
    for(int i=0;i<size;i++){
        i==size-1?cout<<arr[i]:cout<<arr[i]<<" ";
    }
}