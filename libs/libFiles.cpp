#include "LibFiles.h"
#include <fstream>
#include <sstream>
#include <iomanip>

// Count the number of non-empty lines in a file
int f_coutLines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        if (!line.empty()) {
            ++lineCount;
        }
    }

    file.close();
    return lineCount;
}

// Load file contents into a 2D matrix
bool f_readFiletoMatrix(const string& filename, double** matrix, int rows, int cols) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file \"" << filename << "\" for reading.\n";
        return false;
    }

    string line;
    int rowIndex = 0;

    while (rowIndex < rows && getline(file, line)) {
        if (line.empty()) continue;

        istringstream lineStream(line);
        for (int col = 0; col < cols; ++col) {
            if (!(lineStream >> matrix[rowIndex][col])) {
                cerr << "Error: Invalid data format in file \"" << filename << "\" at line " << (rowIndex + 1) << ".\n";
                file.close();
                return false;
            }
        }
        ++rowIndex;
    }

    file.close();
    return rowIndex == rows;
}

// Save MSE results and best matching grid to file
bool f_writeResults(const string& filename, double* mseValues, int numGrids, int bestGridIndex, double** knownMatrix, int cols, double bestMSE) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open file \"" << filename << "\" for writing.\n";
        return false;
    }

    // Defaultfloat to prevent trailing zeros
    outFile << defaultfloat << setprecision(5);

    outFile << "MSE values for all grids:\n";
    for (int i = 0; i < numGrids; ++i) {
        outFile << mseValues[i] << " ";
    }

    outFile << defaultfloat << setprecision(5);
    outFile << "\nMinimum MSE error: " << bestMSE << "\n";

    outFile << defaultfloat << setprecision(10);
    outFile << "Y,X vector of the best matching grid:\n";
    for (int j = 0; j < cols; ++j) {
        outFile << knownMatrix[2 * bestGridIndex][j] << " ";
    }

    outFile << "\n\n";

    for (int j = 0; j < cols; ++j) {
        outFile << knownMatrix[2 * bestGridIndex + 1][j] << " ";
    }

    outFile.close();
    return true;
}
