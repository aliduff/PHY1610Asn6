//DGW_analysis.h
//
//preprocessor guard
#ifndef DGW_ANALYSIS_H
#define DGW_ANALYSIS_H
//
//Necessary includes
#include <fftw3.h>
#include <rarray>
#include <complex>
#include <cblas.h>
#include <iostream>
//
typedef std::complex<double> complex;
///@brief computes fast fourier transform using fftw3 library
///@param f function in time domain
///@param fhat where fourier transform is stored
///@param inverse sign convention flag for inverse fourier transform
void fft_fast(const rvector<complex>& f, rvector<complex>& fhat, bool inverse);
//
///@brief Computes the power spectrum of a signal
///@param f the signal
///@param ps where the power spectrum is stored
void power_spectrum(rvector<complex>& f, rvector<double>& ps);
//
///@brief Computes the correlation between two power spectra g1 and g2
///@param g1 power spectrum of predicted/observation signal
///@param g2 power spectrum of observation/predicted signal
///@return the correlation between the two power spectra
double correlation(rvector<double>& g1, rvector<double>& g2);
#endif
