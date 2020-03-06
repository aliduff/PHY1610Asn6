//DGW_results.h
//
//preprocessor guard
#ifndef DGW_RESULTS_H
#define DGW_RESULTS_H
//
//Necessary includes
#include <rarray>

///@brief
///@param
rarray<int,1> findtop(rarray<double,1> Arr);

///@brief
///@param
void swap_assist(rarray<double,1> Arr, rarray<int,1> index, int j);


///@brief
///@param
void write_results(rarray<double,1> correlation, rarray<int,1> samples);

#endif
