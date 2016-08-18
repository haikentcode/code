import math as m
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon
def func(x):
 return (x - 1) * (x - 13) *(x - 17) + 85
 
a, b = 2, 9 # integral limits
x = np.linspace(0, 10)
y = func(x)
 
fig, ax = plt.subplots()
plt.plot(x, y, 'r', linewidth=2)
plt.ylim(ymin=0)
 
# Make the shaded region
ix = np.linspace(a, b)
iy = func(ix)
verts = [(a, 0)] + list(zip(ix, iy)) + [(b, 0)]
poly = Polygon(verts, facecolor='0.9', edgecolor='0.5')
ax.add_patch(poly)
 
plt.text(0.5 * (a + b), 30, r"$\int_a^b f(x)\mathrm{d}x$",
 horizontalalignment='center', fontsize=20)
 
plt.figtext(0.9, 0.05, '$x$')
plt.figtext(0.1, 0.9, '$y$')
 
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.xaxis.set_ticks_position('bottom')
 
ax.set_xticks((a, b))
ax.set_xticklabels(('$a$', '$b$'))
ax.set_yticks([])
 
plt.show()
