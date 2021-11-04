#include <iostream>
using namespace std;
//Function Prototypes
int **getData(int &,int &);              //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);            //Deallocate memory
int sum(const int * const *, int,int);   //Return the Sum

int main(){
	//your code here
	//Declare variables
	int **arr;
	int row,
	    col;
    int tot;
	//Read 2-D array size and return ptr to 2-D array
    arr=getData(row,col);
    //Return the sum of array
    tot=sum(arr,row,col);
    //Print the original 2-D array
    prntDat(arr,row,col);
    //Print the sum of the 2-D array
    cout<<"\n"<<tot;
	//Cleanup Properly
	destroy(arr,row,col);
	return 0;
}
//Function Implementation
//Return the 2-D array and its size.
int **getData(int &row,int &col){
    cin>>row>>col;
    int **ptr=new int *[row];
    for(int i = 0; i < row; i++){
    ptr[i] = new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>ptr[i][j];
        }
    }
    return ptr;
}        
//Print the 2-D Array
void prntDat(const int* const *arr,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            j!=col-1?cout<<arr[i][j]<<" ":
                     cout<<arr[i][j];
        }
        if(i!=row-1){
            cout<<endl;
        }
    }
}
//Deallocate memory
void destroy(int **arr,int row,int col){
    for(int i=0;i<row;i++){
        delete arr[i];
    }
    delete [] arr;
}     
//Return the Sum
int sum(const int * const *arr, int row,int col){
    int tot=0;    //Total sum of matrix entries
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            tot+=arr[i][j];
        }
    }
    return tot;
}