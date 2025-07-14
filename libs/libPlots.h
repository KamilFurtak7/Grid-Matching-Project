#ifndef LIBPLOTS_H
#define LIBPLOTS_H

#include <iostream>
#include <string>
using namespace std;

/**
 * Saves data to a text file for use in plotting (e.g. with Python).
 *
 * @param dataFile Name of the file where data will be saved.
 * @param unknownMatrix Matrix of the unknown model.
 * @param bestMatrix Matrix of the best-matching model.
 * @param cols Number of columns in the matrices.
 */
void saveDataForPlot(const string& dataFile, double** unknownMatrix, double** bestMatrix, int cols);

/**
 * Generates a Python script to plot the data using matplotlib.
 *
 * @param plotFile Name of the script file to be generated.
 * @param dataFile Name of the file containing the data to plot.
 * @param outputFile Name of the output image file.
 * @param title Title to be displayed on the plot.
 */
void generatePythonScript(const string& plotFile, const string& dataFile, const string& outputFile, const string& title);

#endif // LIBPLOTS_H
