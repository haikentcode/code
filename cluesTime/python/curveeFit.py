import numpy as np
from scipy.optimize import curve_fit

x = np.array([100, 110, 90,85,99,96,102,103,121,1112,126])
y = np.array([1,2,4,1,2,9,3,2,4,1,1])

def fit_func(x, a, b):
    return a*x + b

params = curve_fit(fit_func, x, y)

[a, b] = params[0]

print a,b
