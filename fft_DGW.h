//fft_DGW.h
//
//preprocessor guard
#ifndef FFT_DGW_H
#define FFT_DGW_H
//
//Necessary includes
#include <fftw3.h>
#include <rarray>
#include <complex>
#include <cblas.h>
#include <iostream>
//
typedef std::complex<double> complex;
///@brief
///@param
void fft_fast(const rvector<complex>& f, rvector<complex>& fhat, bool inverse);
//
///@brief
///@param
void power_spectrum(rvector<complex>& f, rvector<double>& ps);
//
///@brief
///@param
double correlation(rvector<double>& g1, rvector<double>& g2);
#endif
