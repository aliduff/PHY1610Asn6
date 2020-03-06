#The Makefile
CXX = g++
CXXFLAGS = -std=c++14
NETCDF_LIB = ${SCINET_NETCDF_ROOT}/lib
NETCDF_INC = ${SCINET_NETCDF_ROOT}/include
FFTW_LIB = ${SCINET_FFTW_ROOT}/lib
FFTW_INC = ${SCINET_FFTW_ROOT}/include
LDLIBS = -lnetcdf_c++4 -lfftw3 -lopenblas

BLAS_INC=${HOME}/OpenBLAS/include/
BLAS_LIB=${HOME}/OpenBLAS/lib/
#LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${HOME}/OpenBLAS/lib/

all: DGW

DGW: DGW.o ncReader.o fft_DGW.o DGW_results.o
	$(CXX) -L${NETCDF_LIB} -L${FFTW_LIB} -L${BLAS_LIB} ${LDLIBS} DGW_results.o ncReader.o fft_DGW.o DGW.o -o DGW 

DGW.o: DGW.cc
	$(CXX) $(CXXFLAGS) -I${BLAS_INC} DGW.cc -c -o DGW.o

DGW_results.o: DGW_results.cc
	$(CXX) $(CXXFLAGS) DGW_results.cc -c -o DGW_results.o
	
ncReader.o: ncReader.cc ncReader.h
	$(CXX) $(CXXFLAGS) -I${NETCDF_INC} ncReader.cc -c -o ncReader.o

fft_DGW.o: fft_DGW.cc fft_DGW.h
	$(CXX) $(CXXFLAGS) -I${FFTW_INC} -I${BLAS_INC} fft_DGW.cc -c -o fft_DGW.o

#Help and phony rules

clean: 
	rm -f *.o DGW
