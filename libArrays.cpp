#include "libs/LibArrays.h"
#include <cmath>

// Function to dynamically create a 2D matrix
double** f_createMatrix(int rows, int cols) {
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
    }
    return matrix;
}

// Function to properly free memory of a dynamically allocated 2D matrix
void f_deleteMatrix(double** matrix, int rows) {
    if (!matrix) return;
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; // Free each row individually
    }
    delete[] matrix; // Free the matrix
}

// Function to compute MSE (Mean Squared Error) between unknown and known grid
double f_comMSE(double** unknownMatrix, double** knownMatrix, int gridIndex, int cols) {
    int paramStart = cols - 100; // Start index of time-series data
    double mse = 0.0; // Accumulated squared error

    // Row indices
    int rowY = 2 * gridIndex;       // Y row in known grid
    int rowX = 2 * gridIndex + 1;   // X row in known grid
    int unkY = 0;                   // Y row in unknown model
    int unkX = 1;                   // X row in unknown model

    // Iterate over the last 100 columns containing X(t), Y(t)
    for (int j = paramStart; j < cols; ++j) {
        double diffY = unknownMatrix[unkY][j] - knownMatrix[rowY][j];
        double diffX = unknownMatrix[unkX][j] - knownMatrix[rowX][j];
        mse += diffY * diffY + diffX * diffX;
    }

    return sqrt(mse); // Return root of the sum of squared differences
}

// Function to determine which known grid is the best match (lowest MSE)
int f_bestMatch(double** unknownMatrix, double** knownMatrix, int numGrids, int cols, double& outMinMSE, double* mseValues) {
    double minMSE = 1e308; // Very large initial value
    int bestIndex = -1;

    for (int i = 0; i < numGrids; ++i) {
        double mse = f_comMSE(unknownMatrix, knownMatrix, i, cols);
        mseValues[i] = mse;

        // Update minimum if a better match is found
        if (mse < minMSE) {
            minMSE = mse;
            bestIndex = i;
        }
    }

    outMinMSE = minMSE;
    return bestIndex;
}
