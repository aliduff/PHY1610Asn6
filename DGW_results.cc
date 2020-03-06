//DGW_results.cc
//
//Necessary include
#include "DGW_results.h"
#include <iostream>
#include <rarrayio>

rarray<int,1> findtop(rarray<double,1> Arr){
	int N = Arr.size();
	//Create index list
	rarray<int,1> indexList(N);
	for(int i = 0; i<N;i++)	
		indexList[i] = i+1;
	
	// Bubble sort - with index list going along for the ride
	double right, left;
	for(int i=0; i<N; i++){
		for(int j=N; j>i; j--){
			right = Arr[j];
			left = Arr[j-1];
			if(right > left)
				swap_assist(Arr,indexList,j); 
		}
	}
	//And this returns full indexList though and sorts the Correlations
	return indexList;
}

void swap_assist(rarray<double,1> Arr,rarray<int,1> index,int j){
	double temp;
	temp = Arr[j-1];
	Arr[j-1] = Arr[j];
	Arr[j] = temp;
	temp = index[j-1];
	index[j-1] = index[j];
	index[j] = temp;
}

void write_results(rarray<double,1> correlation, rarray<int,1> samples){
	std::cout << "The write_results method" << std::endl;
	int N = 5;
	std::string filebase = "detection";
	char spnum[50];
	int check;
	std::string samplename;
	for(int i=0; i<N; i++){
		check = sprintf(spnum, "%02d",samples[i]);
		samplename = filebase+spnum+".nc";
		std::cout<< i+1 << " : "+samplename+" with correlation :"<<correlation[i] <<std::endl;
	}
}





