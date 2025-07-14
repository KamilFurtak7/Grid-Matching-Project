import matplotlib.pyplot as plt
import numpy as np
data = np.loadtxt('plot.txt')
x_t = data[:,0]  # X(t)
y_unknown = data[:,1]  # Y(t) of unknown model
y_best = data[:,2]  # Y(t) of best match
x_best = data[:,3]  # X(t) of best match
plt.figure(figsize=(8,6))
plt.plot(x_t, y_unknown, 'r--', linewidth=2, label='Unknown engine model')
plt.plot(x_best, y_best, 'k-', linewidth=2, label='Model from identification grid')
plt.title('Grid Match Visualization')
plt.xlabel('X(t)')
plt.ylabel('Y(t)')
plt.legend(loc='upper right')
plt.grid(True)
plt.savefig('grid.png', dpi=300)
plt.show()
