//fft_DGW.cc
//
//Necessary includes
#include "fft_DGW.h"
#include <iostream>
///@brief
///@param
void fft_fast(const rvector<complex>& f, rvector<complex>& fhat, bool inverse)
{
	int n = f.size();
	fftw_plan p = fftw_plan_dft_1d(n,(fftw_complex*)f.data(),(fftw_complex*)fhat.data(),inverse?FFTW_BACKWARD:FFTW_FORWARD,FFTW_ESTIMATE);
	fftw_execute(p);
	fftw_destroy_plan(p);
	
//	std::cout << "Computed FFT" << std::endl;
}

void power_spectrum(rvector<complex>& f, rvector<complex>& ps)
{
	int n = f.size();
	double Fi;
	for(int i = 0; i<n; i++){
		Fi = norm(f[i]);
		ps[i] = Fi*Fi;
	}
}
