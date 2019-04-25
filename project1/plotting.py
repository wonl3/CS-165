import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_polynomials_and_their_negations():
    x = np.linspace(0, 2, 100)

    plt.plot(x, x, label='linear')
    plt.plot(x, x**2, label='quadratic')
    plt.plot(x, x**3, label='cubic')

    plt.xlabel('x label')
    plt.ylabel('y label')

    plt.title("Simple Plot")
    plt.legend()
    plt.show()
    #plt.savefig('curves.png')

    plt.clf()
    x = np.linspace(0, 2, 100)

    plt.plot(x, -x, label='linear')
    plt.plot(x, -x**2, label='quadratic')
    plt.plot(x, -x**3, label='cubic')

    plt.xlabel('x label')
    plt.ylabel('y label')

    plt.title("Simple Plot")
    plt.legend()
    plt.show()
    #plt.savefig('curves_neg.png')
    plt.close()

def plot_timings_from_file(fname1, fname2):
    timings = pd.read_csv(fname1, sep=',')
    n1 = timings['n'].values
    seconds1 = timings['seconds'].values
    x1 = n1
    y1 = seconds1
    plt.loglog(x1, y1, 's')
    s = ip.UnivariateSpline(x1, y1, s = 0)
    x1s = np.linspace(min(x1), max(x1), 1000)
    y1s = s(x1s)
    
    timings2 = pd.read_csv(fname2, sep=',')
    n2 = timings2['n'].values
    seconds2 = timings2['seconds'].values
    x2 = n2
    y2 = seconds2
    plt.loglog(x2, y2, 's')
    s = ip.UnivariateSpline(x1, y1, s = 0)
    x2s = np.linspace(min(x2), max(x2), 1000)
    y2s = s(x2s)
    
    plt.plot(x1s, y1s, x2s, y2s)
#    plt.plot(x2s, y2s)
    
    plt.xlabel('# of elements')
    plt.ylabel('time in seconds')
    plt.title('Performance of introsort')
    plt.show()
    plt.close()

plot_timings_from_file('timings/uniform_ss_1_timings.csv', 'timings/nearly_sorted_ss_1_timings.csv')
#plot_timings_from_file('timings.csv')
#plot_polynomials_and_their_negations()
