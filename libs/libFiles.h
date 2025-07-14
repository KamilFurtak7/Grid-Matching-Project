#ifndef LIBFILES_H
#define LIBFILES_H

#include <iostream>
#include <string>
using namespace std;

/**
 * Counts the number of non-empty lines in a text file.
 *
 * @param filename Name of the text file.
 * @return Number of non-empty lines in the file.
 */
int f_coutLines(const string& filename);

/**
 * Loads data from a file into a dynamically allocated matrix.
 *
 * @param filename Name of the file to read from.
 * @param matrix Matrix to store the loaded data.
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return true if the operation was successful, false otherwise.
 */
bool f_readFiletoMatrix(const string& filename, double** matrix, int rows, int cols);

/**
 * Writes computation results to a text file.
 *
 * @param filename Name of the output file.
 * @param mseValues Array of MSE values for all grids.
 * @param numGrids Number of available identification grids.
 * @param bestGridIndex Index of the best matching grid.
 * @param knownMatrix Matrix of identification grids.
 * @param cols Number of columns in the matrix.
 * @param bestMSE The lowest MSE value found.
 * @return true if the operation was successful, false otherwise.
 */
bool f_writeResults(const string& filename, double* mseValues, int numGrids, int bestGridIndex, double** knownMatrix, int cols, double bestMSE);

#endif // LIBFILES_H
