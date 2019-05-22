import matplotlib.pyplot as plt
import matplotlib.patches as mp
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def log_array(arr):
    return np.array([math.log(e, 10) for e in arr])

def get_regression_line_coefficients(x, y):
    return np.polyfit(log_array(x), log_array(y), 1)

def linear_regression(file, algo):
    def plot_size_vs_times_log_log():
        plt.subplot(2, 1, 1)
        plt.loglog(x, y1, 's', label='y1=x')
        plt.loglog(x, y2, 's', label='y2=log(x)')
        plt.loglog(x, y3, 's', label='y3=x^2')
        plt.loglog(x, y4, 's', label='y4=x^3')
        plt.loglog(x_csv, y_csv, 's', label=algo)
        plt.grid(which='both')
        plt.legend()

    def plot_regression_lines(): 
        plt.subplot(2, 1, 2)
        m, b = get_regression_line_coefficients(x, y1)
        x2 = np.array(range(5))
        plt.plot(x2, m*x2 + b, label=f'y = x, y1 ~ {round(m, 2)}x + {round(b, 2)}')
        m, b = get_regression_line_coefficients(x, y2)
        plt.plot(x2, m*x2 + b, label=f'y = x^0.58, y2 ~ {round(m, 2)}x + {round(b, 2)}')
        m, b = get_regression_line_coefficients(x, y3)
        plt.plot(x2, m*x2 + b, label=f'y = x^0.51, y3 ~ {round(m, 2)}x + {round(b, 2)}')
  #      m, b = get_regression_line_coefficients(x, y4)
 #       plt.plot(x2, m*x2 + b, label=f'y4 ~ {round(m, 2)}x + {round(b, 2)}')
        m, b = get_regression_line_coefficients(x_csv, y_csv)
        plt.plot(x2, m*x2 + b, label=f'{algo}, y_csv ~ {round(m, 2)}x + {round(b, 2)}')
        plt.legend()
        plt.grid(which='both')
        plt.xticks(x2)
        plt.yticks(np.arange(12))

    plt.figure(figsize=(8,8))
    x = np.array([10**idx for idx in range(2, 21)])
    y1 = np.array([x for x in x]) 
    y2 = np.array([math.pow(x, 0.58) for x in x]) 
    y3 = np.array([math.pow(x, 0.51) for x in x])
#    y3 = np.array([math.log(math.log(x, 10), 10) for x in x]) 
#    y4 = np.array([x**3 for x in x])
    
    t = pd.read_csv(file, sep=',')
    n = t['n'].values
    wastes = t['waste'].values
    x_csv = n
    y_csv = wastes
    
#    plot_size_vs_times_log_log()
    plot_regression_lines()    
    plt.show()

def plot_one(file, algo):
    t = pd.read_csv(file, sep=',')
    n = t['n'].values
    wastes = t['waste'].values
    x = n
    y = wastes
    plt.loglog(x, y, 's')
    plt.xlabel('n')
    plt.ylabel('waste')
    plt.title('Performance of ' + algo)
    plt.show()
    plt.close()
    
def plot_all(list_of_files):
    colors = ['red', 'yellow', 'green', 'blue', 'black', 'cyan', 'magenta']
    handle_list =[]
    for i in range(len(list_of_files)):
        file = list_of_files[i]
        t = pd.read_csv(file, sep=',')
        n = t['n'].values
        wastes = t['waste'].values
        x = n
        y = wastes
        plt.loglog(x, y, 's', color=colors[i]) #label=("uniform_" + sorting))
        handle_list.append(mp.Patch(color=colors[i], label=t['funcname'][0]))
        
    plt.xlabel('# of elements')
    plt.ylabel('waste')
    plt.legend(handles=handle_list)
    plt.show()
    plt.close()

linear_regression('csv_files/next_fit.csv', 'next_fit')
linear_regression('csv_files/first_fit.csv', 'first_fit')
linear_regression('csv_files/first_fit_dec.csv', 'first_fit_dec')
linear_regression('csv_files/best_fit.csv', 'best_fit')
linear_regression('csv_files/best_fit_dec.csv', 'best_fit_dec')

#plot_one('csv_files/next_fit.csv', 'next_fit')
#plot_one('csv_files/first_fit.csv', 'first_fit')
#plot_one('csv_files/first_fit_dec.csv', 'first_fit_dec')
#plot_one('csv_files/best_fit.csv', 'best_fit')
#plot_one('csv_files/best_fit_dec.csv', 'best_fit_dec')

#plot_all(['csv_files/next_fit.csv','csv_files/first_fit.csv', 'csv_files/first_fit_dec.csv', 'csv_files/best_fit.csv', 'csv_files/best_fit_dec.csv'])
