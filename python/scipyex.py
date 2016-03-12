import matplotlib.pyplot as plt
import numpy as np
from scipy import special, optimize
f = lambda x: -special.jv(3, x)
sol = optimize.minimize(f, 1.0)
x = np.linspace(0, 10, 5000)
plt.plot(x, special.jv(3, x), '-', sol.x, -sol.fun, 'o')
plt.savefig('plot.png', dpi=96)
