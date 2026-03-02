# Engine Model Identification using MSE

This project identifies an unknown engine model by comparing its behavior to a set of known reference models (grids) using **Mean Squared Error (MSE)**. It loads trajectory data, finds the best-matching grid, and generates a visualization of the results using Python and matplotlib.

## Project Structure

```plaintext
├── main.cpp             # Main logic
├── libs/               
│   ├── libArrays.h/.cpp # Matrix allocation and MSE computation
│   ├── libFiles.h/.cpp  # File loading and result saving
│   └── libPlots.h/.cpp  # Data export and Python plot generation
├── siatka_SEAK.txt      # Unknown model input file
├── nmSEAK.txt           # Known reference grid data
├── plot_script.py       # (auto-generated) Python script to draw plot
├── results.txt          # Output summary
└── plot.png      # Final comparison chart
```

## How to Run
Make sure the files siatka_SEAK.txt and nmSEAK.txt are placed in the same folder as main.cpp.
Next run the program.
The program will:
1. Load and process both data files
2. Calculate the MSE for each reference model
3. Determine the best-matching grid
4. Save the result summary to results.txt
5. Export plotting data to plot_data.txt
6. Generate a Python script: plot_script.py

## Plotting the Results
After the C++ program runs, generate the plot using:
python plot_script.py
This will produce grid.png — a side-by-side visual comparison of the unknown model and the best-matching reference.

## Requirements
1.C++
- C++11 or higher
- g++ or compatible compiler

2.Python
- Python 3.x
- matplotlib
- numpy
