//DGW.cc
///@author Alistair 
///@brief This code mimics one of the methods used by LIGO for
/// detecting gravitational waves. 
/// Requires gwdata folder which contains 32 mock detections and a 
/// Gravity wave prediction, stored as nc files.
//
//Necessary modules to include
#include "fft_DGW.h"
#include "ncReader.h"
#include "DGW_results.h"
#include <rarrayio>
#include <rarray>
#include <iostream>
//
int main(int argc, char* argv[]){
	//The code
	// ================ READ THE PREDICTED GW SIGNAL ============ //
	rvector<std::complex<double>> pgw;
	pgw = read_ncFile("./gwdata/GWprediction.nc");
	int n = pgw.size();
	// Compute the fft 
	rvector<std::complex<double>> pgwhat(n);
	fft_fast(pgw,pgwhat,true);
	//Compute the power spectrum of Prediction
	rvector<double> PS_pgw(n);
	power_spectrum(pgwhat,PS_pgw);
	
	// Variables used repeatedly in loop
	rvector<std::complex<double>> d; //detection waveform
	rvector<std::complex<double>> dhat(n);
	rvector<double> PS_d(n); //Power spectrum
	rarray<double,1> C(32);	
	
	std::string filebase = "./gwdata/detection"; // xx.nc added
	char spnum[50];
	int check;
	std::string samplename;
	//Loop - The above process could be modularized??
	for(int i=0;i<32;i++){
		check = sprintf(spnum, "%02d",i+1);
		samplename = filebase+spnum+".nc";
		d = read_ncFile(samplename);
		fft_fast(d,dhat,true);
		power_spectrum(dhat,PS_d);
		//Correlation
		C[i] = correlation(PS_pgw,PS_d);
		//std::cout << "Correlation for " + samplename + " is : " << C[i] << std::endl;
	}
	//Determine 5 most significant samples
	//Sort samples and track sample number
	rarray<int,1> indexList;
	
	indexList = findtop(C);
	std::cout << indexList << std::endl;
	
	//Find Top N now that we have sorted list
	write_results(C,indexList);	
	//Make sure to close files and dynamically allocated arrays!
	C.clear();
	return 0;
}
