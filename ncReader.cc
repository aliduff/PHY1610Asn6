// ncReader.cc
// Necessary include statements
#include "ncReader.h"

using namespace netCDF;

//Documentation in .h
rvector<std::complex<double>>  read_ncFile(std::string filename){
	NcFile ncfile(filename,NcFile::read);
	rvector<std::complex<double>> f(ncfile.getDim("nt").getSize());
	ncfile.getVar("f").getVar(f.data());
	ncfile.close();
	return f;
}
