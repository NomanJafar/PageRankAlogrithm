# PageRankAlogrithm

WHY THIS ALGOTHITHM SHOUD BE STUDIED?

This Algorithm calculate the rank of pages, if a adjacency matrix of the graph is given as input in text file. PageRank is defined as what is the chance in terms of percentage for a page to get visited by a user.

Google used to Rank the pages in search results according to number of external links attached to that page. lets say if a page have 100 external links added in it. And the other Page has 200 links added then google will rank the second page at higher position than the first. 

It does not matter if Google is using the same strategy today as well but this concept of Ranking pages according to number of external resources attached to that page is quite usefull in finding the probability of finding something when different occurances are attached to each other. And this is very facinating thing for developers.


WALK THROUGH OF PAGE RANK ALGORITHM WITH AN EXAMPLE:
lets assume that we have 4 pages,

Page  A has link of Page B in it.
Page  B has link of Page A and C in it.
Page  C has link of Page D in it.
Page  D has link of Page C in it.

Which Page should be ranked at the Top?
What is the percentage of page A been ranked on top!!!!? Or B or C or D !!!!? 

We can Draw a graph from the problem above.
Here is an Adjecency Matrix of the Graph. (If you don,t know the Adjecency Matrix google it,  that,s very easy!!!  Research!!)

  A B C D
A 0 1 0 0
B 1 0 0 0
C 0 1 0 1
D 0 0 1 0

NOW HERE ARE THE STEPS THAT WE NEED TO FOLLOW TO FIND PAGE RANK

1. Find the out going edges for each Node
Below piece of code will let you get the number of outgoing edges( number of external links a page have ) for each page

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


2. Initially Give all the pages equal page rank. Since we assume that probability of user to go on page is equally distributed among all the pages. That is 1/total pages.

cout<<endl<<"Initial page rank"<<endl;
for(int i=0;i<n;i++){
	pr[i]=(float)1/n;
	cout<<endl<<pr[i]<<endl;
}





3. Call the page rank function on all the pages.

TOTAL PAGE RANK OF A PAGE IS SUM OF TOTAL PAGE RANK OF ITS INCOMING LINKS DIVIDED BY NUMBER OF OUT GOING EDGES

for(int i=0; i<m; i++){
	pagerankArray[i]=findpagerank(i, arr);
}

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







