import numpy as np
import matplotlib.pyplot as plt

def fonctiongraph(marees_noirmoutier_septembre_2026.csv):
    


nb_li, nb_col = 2, 2 # nombre de lignes et de colonnes

tab_X = np.linspace(0, 2*np.pi, 100)
tab_sinX = np.sin(tab_X)
tab_cosX = np.cos(tab_X)

plt.figure("Plusieurs graphiques sur la même figure")



#les 4 petit paragraphe sont les quatre 4 graphique

plt.subplot(nb_li, nb_col, 1) # en haut à gauche
plt.title('sin(x)')
plt.plot(tab_X, tab_sinX)

plt.subplot(nb_li, nb_col, 2) # en haut à droite
plt.title('cos(x)')
plt.plot(tab_X, tab_cosX)

plt.subplot(nb_li, nb_col, 3) # en bas à gauche
plt.title('-sin(x)')
plt.plot(tab_X, -tab_sinX)

plt.subplot(nb_li, nb_col, 4) # en bas à droite
plt.title('-cos(x)')
plt.plot(tab_X, -tab_cosX)




plt.tight_layout() # permet d'espacer convenablement les sous-figures
plt.show()
