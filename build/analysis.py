import numpy as np
import matplotlib.pyplot as plt
import xml.etree.ElementTree as ET
tree = ET.parse("ALPHA_ENERGY.xml")
root = tree.getroot()

histogram1d = root[1]
axis        = histogram1d[1]
statistics  = histogram1d[2]
data1d      = histogram1d[3]

numberOfBins = int(axis.attrib["numberOfBins"])
min_energy   = float(axis.attrib["min"]) # MeV
max_energy   = float(axis.attrib["max"]) # MeV

binNum  = np.array([])
entries = np.array([])

for member in data1d:
    binNum  = np.append(binNum,  int(member.attrib["binNum"]))
    entries = np.append(entries, int(member.attrib["entries"]))

binEnergy  = (binNum+0.0) * (max_energy - min_energy)/numberOfBins
logEntries = np.log10(entries)


plt.step(binEnergy, logEntries, '.')
plt.xlabel("Energy (MeV)")
plt.grid()
plt.show()
