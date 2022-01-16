# -*- coding: utf-8 -*-
##-------------------------------------------------------------------------
##
## question 2 : tracer l'évolution de la température en fonction de x et t
##              * Avec Euler explicite, pour les pas de temps et d'espace , 
##              j'ai réaliser un grand nombre de tests et finalement opté 
##              pour dt = 0.0005 et dx = 0.01
##              * Avec Euler implicite, pour les pas de temps et d'espace , 
##              j'ai opté pour dt = 0.0005 et dx = 0.01
##              
##-------------------------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import os

## écrire l'adresse du fichier data_used.txt avant de lancer le programme 
file_adress_Euler_implicite = "/Users/jonasamar/Jonasamar_PartageCpp/Matrices/data/rd_test2_Euler_implicite.txt" 
file_adress_Euler_explicite = "/Users/jonasamar/Jonasamar_PartageCpp/Matrices/data/rd_test2_Euler_explicite.txt" 
t_f = 0.05

def trace_T(file_adress, tf = 0.05):
    """ 
        args : none
        return : rien
        But : Trace l'évolution de la température en fonction de x et de t à partir du 
              fichier texte créé précédemment
    """
        
    T = pd.read_csv(file_adress, sep = ";", encoding = "utf-8")
    lx, lt = T.shape
     
    dx = 1/lx
    dt = tf/lt
    plt.xticks(range(0, lt, int(lt/10) + 1), [round(i*dt,2) for i in range(0, lt, int(lt/10) + 1)])
    plt.yticks(range(0, lx, int(lx/20) + 1), [round(i*dx,2) for i in range(0, lx, int(lx/20) + 1)])
    plt.xlabel("t")
    plt.ylabel("x")
    plt.title("T(x,t)")
    plt.imshow(T, cmap='viridis', aspect = 'auto')
    plt.colorbar()
    plt.show()

    return

trace_T(file_adress_Euler_implicite, t_f)

trace_T(file_adress_Euler_explicite, t_f)



