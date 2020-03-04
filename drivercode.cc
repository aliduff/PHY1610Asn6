//The driver code for the assignment
//
//
//Necessary include statements
#include "fft_DGW.h"
#include "ncReader.h"

int main(int argc, char* argv[]){
	// ----------- NC READER ----------------- //
	rvector<std::complex<double>> f;
	f = read_ncFile("./gwdata/detection01.nc");	
	int n = f.size();
	//std::cout << "Vector size in driver code is: " << n << std::endl;
//	for (int i=0; i<1; i++)
		//std::cout << f[i] << std::endl;
	
	
	// ================ FFTW ================ //
	rvector<std::complex<double>> fhat(n);
	fft_fast(f, fhat, false);

	// =============== TEST SINC ============//
	/*const int m = 16384;
	std::complex<double> r[m];
	std::complex<double> rhat[m];
	for(int i = 0; i<m; i++) {
		double x = 60*(i/double(m) - 0.5);
		if (x!= 0.0) r[i] = sin(x)/x; else r[i] = 1.0;
	}
	//fft_fast(r,rhat,false);
	fftw_plan p = fftw_plan_dft_1d(m,(fftw_complex*)r,(fftw_complex*)rhat,FFTW_FORWARD,FFTW_ESTIMATE);
	fftw_execute(p);
	fftw_destroy_plan(p);
	*/
	for (int i = 0; i<n; i++)
		std::cout << norm(f[i]) << "," << norm(fhat[i]) << std::endl;
	
	return 0;
}
