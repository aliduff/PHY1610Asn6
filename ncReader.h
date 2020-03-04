//ncReader.h 
//
//preprocessor guard
#ifndef NCREADER_H
#define NCREADER_H
//
//The necessary include statements
#include <rarray>
#include <netcdf>
#include <complex>

///@brief 
///@param 
///@returnv
rvector<std::complex<double>> read_ncFile(std::string filename);
//
#endif
