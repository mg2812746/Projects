#include <iostream>
using namespace std;
//Function Prototypes
int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory
int main(){
	//your code here
	//Variables
	int **aug,      //Pointer to 2-D Augmented Matrix
	    **ptr;      //Pointer to 2-D Original Matrix
	int row,        //Number of rows
	    col;        //Number of columns
	//Read array size and return pointer to 2-D array
	ptr=getData(row,col);
	//Augment and copy orignal array into returned pointer to augmented array
	aug=augment(ptr,row+1,col+1);
	//Display the matrices
	printDat(ptr,row,col);
	cout<<'\n';
	printDat(aug,row+1,col+1); 
	//Cleanup
	destroy(ptr,row);
	destroy(aug,row+1);
	return 0;
}
//Function Implementation
//Get the Matrix Data
int **getData(int &row,int &col){
    cin>>row>>col;
    int **ptr= new int *[row];
    for(int i=0;i<row;i++){
    ptr[i] = new int [col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>ptr[i][j];
        }
    }
    return ptr;
}
//Print the Matrix
void printDat(const int * const *arr,int row,int col){
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
//Augment the original array
int **augment(const int * const *arr,int row,int col){
    int **a=new int *[row];    //Allocate rows
    //Allocate Columns
    for(int i=0;i<row;i++){
        a[i]= new int [col];
    }
    //Assign 0's to the first entry of each row and to entire first row
    for(int i=0;i<row;i++){
        a[i][0]=0;
    }
    for(int i=0;i<col;i++){
        a[0][i]=0;
    }
    //Augment original array into new array
    for(int i=0;i<row-1;i++){
        for(int j=0;j<col-1;j++){
            a[i+1][j+1]=arr[i][j];   
        }
    }
    return a;
}
//Destroy the Matrix, i.e., reallocate memory
void destroy(int **arr,int row){
    for(int i=0;i<row;i++){
        delete arr[i];
    }
    delete [] arr;
}