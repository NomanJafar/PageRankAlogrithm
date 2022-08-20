#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int m=4,n=4,k=4,l=4;
int outgoing[m];
float pr[m];
float pagerankArray[m];



// pass the page number as argument and get the page rank
float findpagerank(int pageno, int arr[m][n]){
	float total=0;
	for(int i=0;i<n;i++){
	
		if(arr[pageno][i]==1){
			
			total=(float)total+((float)(pr[i])  /  (outgoing[i]));		
	}
	
}
			//	cout <<endl<< setprecision(4) <<total <<endl;
return total;
}








int main()
{

cout<< fixed;

int arr[m][n];
double mul[k][l];
ifstream iFile;
iFile.open("in.txt");

for(int i=0;i<m;i++)
{
	for(int j=0;j<n;j++)
	{
		iFile>>arr[i][j];
	
	}
	
}
iFile.close(); 


cout<<endl<<" given adjency matrix"<<endl;
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++)
	{
		cout<<arr[i][j]<<"       ";
	}
	cout<<endl;
}







cout<<" No of outgoing edges"<<endl;
for(int i=0;i<n;i++){
	outgoing[i]=0;
	for(int j=0;j<m;j++)
	{
		if(arr[j][i]==1){
			outgoing[i]++;
		}
		
		
	}
cout<<outgoing[i]<<endl;
}




cout<<endl<<"Initial page rank"<<endl;
for(int i=0;i<n;i++){
	pr[i]=(float)1/n;
	cout<<endl<<pr[i]<<endl;
}




//store pagerank of all pages into the array 
for(int i=0; i<m; i++){
	pagerankArray[i]=findpagerank(i, arr);
}









for(int i=0; i<m; i++){
	
	cout<<endl<<"page rank of of page "<<" "<<i+1<<" "<<"  is  "<< pagerankArray[i]<<endl;
}





}
