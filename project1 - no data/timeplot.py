import matplotlib.pyplot as plt
import matplotlib.patches as mp
import numpy as np
import pandas as pd
import math
import scipy.interpolate as ip

def plot_2(list_of_files):
    colors = ['red', 'green']
    array_type = ['uniform_', 'nearly_sorted_']
    handle_list =[]
    for i in range(len(list_of_files)):
        file = list_of_files[i]
        t = pd.read_csv(file, sep=',')
        n = t['n'].values
        seconds = t['seconds'].values
        x = n
        y = seconds
        plt.loglog(x, y, 's', color=colors[i]) #label=("uniform_" + sorting))
        handle_list.append(mp.Patch(color=colors[i], label=array_type[i] + t['funcname'][0]))
        
    plt.xlabel('# of elements')
    plt.ylabel('time in seconds')
    plt.legend(handles=handle_list)
    plt.show()
    plt.close()

def plot_all(list_of_files, array_type):
    colors = ['red', 'yellow', 'green', 'blue', 'black', 'cyan', 'magenta']
    handle_list =[]
    for i in range(len(list_of_files)):
        file = list_of_files[i]
        t = pd.read_csv(file, sep=',')
        n = t['n'].values
        seconds = t['seconds'].values
        x = n
        y = seconds
        plt.loglog(x, y, 's', color=colors[i]) #label=("uniform_" + sorting))
        handle_list.append(mp.Patch(color=colors[i], label=array_type + t['funcname'][0]))
        
    plt.xlabel('# of elements')
    plt.ylabel('time in seconds')
#    plt.legend(handles=handle_list)
    plt.show()
    plt.close()

plot_2(['timings/uniform_bs_timings.csv', 'timings/nearly_sorted_bs_timings.csv'])
plot_2(['timings/uniform_is_timings.csv', 'timings/nearly_sorted_is_timings.csv'])
plot_2(['timings/uniform_stbs_timings.csv', 'timings/nearly_sorted_stbs_timings.csv'])
plot_2(['timings/uniform_ss_1_timings.csv', 'timings/nearly_sorted_ss_1_timings.csv'])
plot_2(['timings/uniform_ss_2_timings.csv', 'timings/nearly_sorted_ss_2_timings.csv'])
plot_2(['timings/uniform_as_1_timings.csv', 'timings/nearly_sorted_as_1_timings.csv'])
plot_2(['timings/uniform_as_2_timings.csv', 'timings/nearly_sorted_as_2_timings.csv'])

plot_all(['timings/uniform_bs_timings.csv','timings/uniform_is_timings.csv','timings/uniform_stbs_timings.csv',
          'timings/uniform_ss_1_timings.csv','timings/uniform_ss_2_timings.csv','timings/uniform_as_1_timings.csv',
          'timings/uniform_as_2_timings.csv'], 'uniform_')
    
plot_all(['timings/nearly_sorted_bs_timings.csv','timings/nearly_sorted_is_timings.csv','timings/nearly_sorted_stbs_timings.csv',
          'timings/nearly_sorted_ss_1_timings.csv','timings/nearly_sorted_ss_2_timings.csv','timings/nearly_sorted_as_1_timings.csv',
          'timings/nearly_sorted_as_2_timings.csv'], 'nearly_sorted_')
    

