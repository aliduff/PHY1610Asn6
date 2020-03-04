// ncReader.h
// Necessary include statements
#include "ncReader.h"

using namespace netCDF;

rvector<std::complex<double>>  read_ncFile(std::string filename){
	NcFile ncfile(filename,NcFile::read);
	rvector<std::complex<double>> f(ncfile.getDim("nt").getSize());
	ncfile.getVar("f").getVar(f.data());
	//std::cout << "Opened File" << std::endl;
	//std::cout << "Vector size is: " << f.size() << std::endl;
	return f;
}
