#include <iostream>
#include <string>
#include "libs/LibArrays.h"
#include "libs/LibFiles.h"
#include "libs/libPlots.h"

using namespace std;

int main() {
    string knownFile, GridsFile, outputFile;

    cout << "=== Grid Matching Program ===" << endl;

    cout << "Enter the name of the file with the unknown model (e.g., nmSEAK.txt): ";
    cin >> knownFile;

    cout << "Enter the name of the file with all grid candidates (e.g., siatka_SEAK.txt): ";
    cin >> GridsFile;

    cout << "Enter the name of the output file (e.g., results.txt): ";
    cin >> outputFile;

    int cols = 106;

    int knownLines = f_coutLines(knownFile);
    int GridsLines = f_coutLines(GridsFile);

    double** knownMatrix = f_createMatrix(knownLines, cols);
    double** allGridsMatrix = f_createMatrix(GridsLines, cols);

    f_readFiletoMatrix(knownFile, knownMatrix, knownLines, cols);
    f_readFiletoMatrix(GridsFile, allGridsMatrix, GridsLines, cols);

    int numGrids = GridsLines / 2;
    double bestMSE;
    double* mseValues = new double[numGrids];

    int bestIndex = f_bestMatch(knownMatrix, allGridsMatrix, numGrids, cols, bestMSE, mseValues);

    f_writeResults(outputFile, mseValues, numGrids, bestIndex, allGridsMatrix, cols, bestMSE);

    saveDataForPlot("plot.txt", knownMatrix, &allGridsMatrix[2 * bestIndex], cols);
    generatePythonScript("plot_script.py", "plot.txt", "plot.png", "Grid Match Visualization");

    cout << "Matching complete. Results saved to '" << outputFile << "'." << endl;
    cout << "Plot will be generated as 'plot.png' after running plot_script.py." << endl;

    delete[] mseValues;
    f_deleteMatrix(knownMatrix, knownLines);
    f_deleteMatrix(allGridsMatrix, GridsLines);

    return 0;
}
