//DGW.cc
///@author Alistair 
///@brief This code mimics one of the methods used by LIGO for
/// detecting gravitational waves. 
/// Requires gwdata folder which contains 32 mock detections and a 
/// Gravity wave prediction, stored as nc files.
//
//Necessary modules to include
#include "DGW_analysis.h"
#include "ncReader.h"
#include "DGW_results.h"
#include <rarrayio>
#include <rarray>
#include <iostream>
///@brief This code finds the 5 most significant candidates from the observation
///set. The analysis follows the oversimplified representation of LIGOs
/// "Matched Filtered Algorithm". 
int main(int argc, char* argv[]){
	// ================ THE PREDICTED GW SIGNAL ================= //
	rvector<std::complex<double>> pgw;
	pgw = read_ncFile("./gwdata/GWprediction.nc");
	int n = pgw.size();
	// Compute the fft of the Predicted Gravity Wave Signal
	rvector<std::complex<double>> pgwhat(n);
	fft_fast(pgw,pgwhat,true);
	//Compute the power spectrum of Prediction
	rvector<double> PS_pgw(n);
	power_spectrum(pgwhat,PS_pgw);
	
	// =================== OBSERVATION DATA ===================== //
	// Variables used repeatedly in loop
	rvector<std::complex<double>> d; //detection waveform
	rvector<std::complex<double>> dhat(n); //fourier transform of waveform
	rvector<double> PS_d(n); //Power spectrum
	rarray<double,1> C(32);	//Store the Correlation coefficients
	
	std::string filebase = "./gwdata/detection"; // xx.nc added
	char spnum[50]; //character buffer stream
	int check; //Check if filename generates properly
	std::string samplename; //which detection we are looking at
	//Loop over all samples
	for(int i=0;i<32;i++){
		check = sprintf(spnum, "%02d",i+1);
		samplename = filebase+spnum+".nc"; //Generate sample filename
		//Generate Power spectrum
		d = read_ncFile(samplename);
		fft_fast(d,dhat,true);
		power_spectrum(dhat,PS_d);
		//Correlation value for detectionXX and Prediction
		C[i] = correlation(PS_pgw,PS_d);
	}
	// ============= DETERMINE N MOST SIGNIFICANT ============= //
	rarray<int,1> indexList;
	indexList = findtop(C); //Sort the Correlations
	//Find Top N now that we have sorted list
	write_results(C,indexList,5);	
	//Make sure to close files and dynamically allocated arrays!
	C.clear();
	pgw.clear(); pgwhat.clear(); PS_pgw.clear();
	d.clear(); dhat.clear(); PS_d.clear();
	indexList.clear();
	return 0;
}
