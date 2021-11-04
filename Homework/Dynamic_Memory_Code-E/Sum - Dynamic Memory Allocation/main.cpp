#include <iostream>

using namespace std;
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array
int main(){
    //your code here
    //Declare variables
    int *ptr,
	*sum;
    int size;
    //Determine array size from input and allocate array
    ptr=getData(size);
    //Compute successive sums from preceding members in array and return pointer to that array
    sum=sumAry(ptr,size);
    //Display original array
    prntAry(ptr,size);
    cout<<endl;
    //Display array with successive sums
    prntAry(sum,size);
    //Cleanup
    delete [] ptr;
    delete [] sum;
    return 0;
}
//Function Prototypes
//Return the array size and the array from the inputs
int *getData(int &size){
    cin>>size;
    int *p=new int [size];
    for(int i=0;i<size;i++){
        cin>>p[i];
    }
    return p;
}        
//Return the array with successive sums
int *sumAry(const int *arr,int size){
    int *s= new int [size];
    int j=0;    //counter for iteration
    s[j]=arr[j];
    j++;
    int tmpSum=0;
    for(int i=0;i<size-1;i++){
        tmpSum+=arr[i];
        s[j]=tmpSum+arr[i+1];
        j++;
    }
    return s;
}
//Print the array
void prntAry(const int *sum,int size){
    for(int i=0;i<size;i++){
        i==size-1?cout<<sum[i]:cout<<sum[i]<<" ";
    }
}