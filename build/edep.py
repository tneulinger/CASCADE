import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("edep.dat")

edep_hist = np.histogram(data, bins=100)[0]

plt.semilogy(edep_hist)
plt.grid()
plt.show()
