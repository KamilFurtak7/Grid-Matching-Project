#ifndef LIBARRAYS_H
#define LIBARRAYS_H

#include <iostream>
using namespace std;

/**
 * Allocates a dynamic 2D array (matrix).
 *
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return Pointer to the created matrix.
 */
double** f_createMatrix(int rows, int cols);

/**
 * Frees memory occupied by a dynamic 2D matrix.
 *
 * @param matrix Pointer to the matrix to free.
 * @param rows Number of rows in the matrix.
 */
void f_deleteMatrix(double** matrix, int rows);

/**
 * Computes the Mean Squared Error (MSE) between an unknown model and a known grid model.
 *
 * @param unknownMatrix Matrix of the unknown model.
 * @param knownMatrix Matrix of the identification grid.
 * @param gridIndex Index of the grid to compare with.
 * @param cols Number of columns in the matrix.
 * @return Computed MSE value.
 */
double f_comMSE(double** unknownMatrix, double** knownMatrix, int gridIndex, int cols);

/**
 * Finds the index of the best matching grid based on MSE.
 *
 * @param unknownMatrix Matrix of the unknown model.
 * @param knownMatrix Matrix of the identification grid.
 * @param numGrids Number of available grids.
 * @param cols Number of columns in the matrix.
 * @param outMinMSE Reference to store the minimum MSE value found.
 * @param mseValues Array to store all computed MSE values.
 * @return Index of the best matching grid.
 */
int f_bestMatch(double** unknownMatrix, double** knownMatrix, int numGrids, int cols, double& outMinMSE, double* mseValues);

#endif // LIBARRAYS_H
