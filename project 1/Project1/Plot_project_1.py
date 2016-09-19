import numpy as np
import pylab as pl


with open(Plots, 'r') as file:
	lines = file.readlines()
	y1 = np.zeros(len(lines[0]))
	for i in range(len(lines)):
		y[i] = np.array(lines[i].split())
		y[i] = y[i].astype(np.float)

with open(Plots, 'r') as file:
	lines = file.readlines()
	y2 = np.zeros(len(lines[0]))
	for i in range(len(lines)):
		y[i] = np.array(lines[i].split())
		y[i] = y[i].astype(np.float)

with open(Plots, 'r') as file:
	lines = file.readlines()
	y2 = np.zeros(len(lines[0]))
	for i in range(len(lines)):
		y[i] = np.array(lines[i].split())
		y[i] = y[i].astype(np.float)
n = 1000.

x1 = np.linspace(0,1,n)

figure(1)
pl.plot(x,y,'r-')
pl.xlabel('Grid points')
pl.ylabel('v(x)')

figure(2)
pl.plot(x,y,'r-')
pl.xlabel('Grid points')
pl.ylabel('v(x)')

figure(3)
pl.plot(x,y,'r-')
pl.xlabel('Grid points')
pl.ylabel('v(x)')

