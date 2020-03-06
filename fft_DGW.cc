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

void power_spectrum(rvector<complex>& f, rvector<double>& ps)
{
	int n = f.size();
	double F1,F2;
	for(int i = 0; i<n; i++){
		F1 = norm(f[i]);
		F2 = (f[i]*conj(f[i])).real();
		//std::cout << F1-F2 << std::endl;
		ps[i] = F1;
	}
}

double correlation(rvector<double>& g1, rvector<double>& g2)
{
	double C,D,F,G;
	int N = g1.size();
	D = cblas_ddot(N,g1.data(),1,g2.data(),1); //Dot product of g1 g2
	F = cblas_ddot(N,g1.data(),1,g1.data(),1); //g1 dot g1
	G = cblas_ddot(N,g2.data(),1,g2.data(),1); //g2 dot g2
	C = D / std::sqrt(F*G) ;
	return C;
}
