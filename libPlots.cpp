#include "libs/LibPlots.h"
#include <fstream>
#include <iomanip>  // For more precise numeric output

// Function to save data to a .txt file with 4 columns: X(t), Y(t) of Unknown Model, Y(t) of Best Match, X(t) of Best Match
void saveDataForPlot(const string& dataFile, double** unknownMatrix, double** bestMatrix, int cols) {
    ofstream data(dataFile);
    if (!data.is_open()) {
        cerr << "Error: Cannot open file " << dataFile << " for writing data!\n";
        return;
    }

    int paramCols = cols - 100;
    data << std::fixed << std::setprecision(15);

    for (int i = 0; i < 100; ++i) {
        double x_t = unknownMatrix[1][paramCols + i];       // X(t) of unknown model
        double y_t_unknown = unknownMatrix[0][paramCols + i]; // Y(t) of unknown model
        double y_t_best = bestMatrix[0][paramCols + i];     // Y(t) of best matched model
        double x_t_best = bestMatrix[1][paramCols + i];     // X(t) of best matched model

        data << x_t << " " << y_t_unknown << " " << y_t_best << " " << x_t_best << "\n";
    }

    data.close();
}

// Function to generate a Python script that plots the results
void generatePythonScript(const string& scriptFile, const string& dataFile, const string& outputFile, const string& title) {
    ofstream script(scriptFile);
    if (!script.is_open()) {
        cerr << "Error: Cannot open file " << scriptFile << " for writing script!\n";
        return;
    }

    script << "import matplotlib.pyplot as plt\n";
    script << "import numpy as np\n";

    // Load data
    script << "data = np.loadtxt('" << dataFile << "')\n";
    script << "x_t = data[:,0]  # X(t)\n";
    script << "y_unknown = data[:,1]  # Y(t) of unknown model\n";
    script << "y_best = data[:,2]  # Y(t) of best match\n";
    script << "x_best = data[:,3]  # X(t) of best match\n";

    // Create plot
    script << "plt.figure(figsize=(8,6))\n";
    script << "plt.plot(x_t, y_unknown, 'r--', linewidth=2, label='Unknown engine model')\n";
    script << "plt.plot(x_best, y_best, 'k-', linewidth=2, label='Model from identification grid')\n";
    script << "plt.title('" << title << "')\n";
    script << "plt.xlabel('X(t)')\n";
    script << "plt.ylabel('Y(t)')\n";
    script << "plt.legend(loc='upper right')\n";
    script << "plt.grid(True)\n";

    // Save and show plot
    script << "plt.savefig('" << outputFile << "', dpi=300)\n";
    script << "plt.show()\n";

    script.close();
}
