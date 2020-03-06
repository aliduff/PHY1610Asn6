//DGW_results.h
//
//preprocessor guard
#ifndef DGW_RESULTS_H
#define DGW_RESULTS_H
//
//Necessary includes
#include <rarray>

///@brief This sorts an array from largest to smallest value and returns
///the original indices of the sorted array
///@param Arr The array of type double that we want to sort
///@return rarray<int,1> an array of the original indices in order sorted by values in Arr.
rarray<int,1> findtop(rarray<double,1> Arr);

///@brief Helper function for find_top. Swaps the position of an element j of the arrays Arr and index with their respective element at position j-1. 
///@param Arr the array of correlation values
///@param index the array of indices (serves to track which sample has the highest correlations)
///@param j the index of the element we want to move to position j-1. 
void swap_assist(rarray<double,1> Arr, rarray<int,1> index, int j);


///@brief This outputs the results of the top N samples by correlation
///@param correlation the array of correlation values
///@param samples which sample number is associated with each correlation value
///@param N how many candidates do we want to report, the top N correlations.  
void write_results(rarray<double,1> correlation, rarray<int,1> samples,int N);

#endif
