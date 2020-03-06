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

## all: build all
all: DGW

## DGW: Generate executable for Detecting Gravitational Waves
DGW: DGW.o ncReader.o DGW_analysis.o DGW_results.o
	$(CXX) -L${NETCDF_LIB} -L${FFTW_LIB} -L${BLAS_LIB} ${LDLIBS} DGW_results.o ncReader.o DGW_analysis.o DGW.o -o DGW 

## DGW.o: Compile code for running the program
DGW.o: DGW.cc
	$(CXX) $(CXXFLAGS) -I${BLAS_INC} DGW.cc -c -o DGW.o

## DGW_results.o: Compile module for determining results of analysis
DGW_results.o: DGW_results.cc
	$(CXX) $(CXXFLAGS) DGW_results.cc -c -o DGW_results.o
	
## ncReader.o: Compile module for reading the netcdf files
ncReader.o: ncReader.cc ncReader.h
	$(CXX) $(CXXFLAGS) -I${NETCDF_INC} ncReader.cc -c -o ncReader.o

## DGW_analysis.o: Compile module for analysing the GW signals
DGW_analysis.o: DGW_analysis.cc DGW_analysis.h
	$(CXX) $(CXXFLAGS) -I${FFTW_INC} -I${BLAS_INC} DGW_analysis.cc -c -o DGW_analysis.o

.PHONY : help clean

## clean: Remove generated files
clean: 
	rm -f *.o DGW

## help: display this help message
help: makefile
	@sed -n 's/^##//p' $<
