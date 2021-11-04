#include <iostream> //cout,cin
#include <iomanip>  //setw
using namespace std;
//Structures
//MovieData- Contains basic information for one Movie
struct MovieData{
    char tit[30];          //Name of Movie
    char dir[30];          //Name of Director
    unsigned short yr;  //Year Movie was Released
    unsigned short tme; //Running Time
};
//Movies- Contains basic information of all movies entered
struct Movies{
    MovieData *mveData;  //Pointer to Structure MovieData
    short tot;           //Total number of Movies
};
//Function Prototypes
void showHdr();          //Displays header message
Movies *getDat();//Gets data for movies
void showDat(Movies *);
int main(){
	//Declare Variables
	Movies *all;          //Structure containing all movie data
	//Process
	showHdr();           //Prompt User for input
	all=getDat();        //Get User Input for all Movies
	//Output
	showDat(all);        //Display Information about Movies
	//Cleanup
	delete [] all->mveData;
	delete all;
	
	return 0;
}
//Function Implementation
void showHdr(){
    cout<<"This program reviews structures\n"
        <<"Input how many movies, the Title of the Movie,"
        <<"Director, Year Released, and the Running Time in (minutes).\n\n";
}
Movies *getDat(){
    //Declare Structure array
    Movies *ptr=new Movies;             
    cin>>ptr->tot;                      //Read the total number of movies
    //Dynamically allocate array for MovieData 
    ptr->mveData=new MovieData [ptr->tot];  
    //Read Movie Title
    for(int i=0;i<ptr->tot;i++){
        cin.ignore();
        cin.get(ptr->mveData[i].tit,19);
        cin.ignore();
        cin.get(ptr->mveData[i].dir,19);
        cin.ignore();
        cin>>ptr->mveData[i].yr>>ptr->mveData[i].tme;
    }
    return ptr;
}
void showDat(Movies *ptr){
    for(int i=0;i<ptr->tot;i++){
        cout<<left;
        cout<<setw(11)<<"Title:"<<ptr->mveData[i].tit<<endl;
        cout<<setw(11)<<"Director:"<<ptr->mveData[i].dir<<endl;
        cout<<setw(11)<<"Year:"<<ptr->mveData[i].yr<<endl;
        cout<<setw(11)<<"Length:"<<ptr->mveData[i].tme<<endl;
        if(i!=ptr->tot-1){
            cout<<endl;
        }
    }
}