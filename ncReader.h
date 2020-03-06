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

///@brief read the netcdf file that stores the gravitational wave data
///@param filename the name of the file we want to open and process
///@return the complex valued signal data
rvector<std::complex<double>> read_ncFile(std::string filename);
//
#endif
