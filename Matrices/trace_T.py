##-------------------------------------------------------------------------
##
## question 2 : tracer l'évolution de la température en fonction de x et t
##              * Condition pour choix de dt et dx : dt/(dx^2) < 1
##              * j'ai pris pour le sets de data créés : 
##                  -> dx = 0.05
##                  -> dt = 0.0001
##              * On remarque que l'utilisation de coefficients randoms ne 
##                semble pas affecter l'allure globale de l'évolution de la 
##                chaleur.
##              
##-------------------------------------------------------------------------

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

## écrire l'adresse du fichier data_used.txt avant de lancer le programme 
file_adress_Euler_implicite = "/Users/jonasamar/Jonasamar_PartageCpp/Matrices/data/D_rdm_Euler_implicite.txt" 
file_adress_Euler_explicite = "/Users/jonasamar/Jonasamar_PartageCpp/Matrices/data/D_rdm_Euler_explicite.txt" 
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



