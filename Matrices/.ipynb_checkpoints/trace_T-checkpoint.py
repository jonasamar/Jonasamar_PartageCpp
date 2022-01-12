# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os

def trace_T(file_name, tf = 0.05):
    """ 
        args : none
        return : rien
        But : Trace l'évolution de la température en fonction de x et de t à partir du 
              fichier texte créé précédemment
    """
    
    os.chdir('data')
    
    T = pd.read_csv(file_name, sep = ";", encoding = "utf-8")
    lx, lt = T.shape
     
    dx = 1/lx
    dt = tf/lt
    print(T)
    plt.xticks(range(0, lt, int(lt/20) + 1), [i*dt for i in range(0, lt, int(lt/20) + 1)])
    plt.yticks(range(0, lx, int(lx/20) + 1), [i*dx for i in range(0, lx, int(lx/20) + 1)])
    plt.xlabel("t")
    plt.ylabel("x")
    plt.title("T(x,t)")
    plt.imshow(T, cmap='viridis')
    plt.colorbar()
    plt.show()

    return


trace_T("test7.txt")


