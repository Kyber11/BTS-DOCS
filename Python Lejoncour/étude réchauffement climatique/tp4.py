# -*- coding: utf-8 -*-
"""
Created on Mon Sep  7 10:21:48 2026

@author: armand.beaux
"""


#tp1 et 2


import matplotlib.pyplot as plt

import pandas as pd

donnees = pd.read_csv('marees_noirmoutier_octobre_2026.csv')
taille = donnees.shape
nb_lignes, nb_colonnes = donnees.shape


# rang de la ligne ou se trouve le coefficient maximum
i = donnees['coef_matin'].idxmax()
j = donnees['coef_soir'].idxmax()

# jour correspondant
jour_coef_max_matin = donnees['jour'][i]
jour_coef_max_soir = donnees['jour'][j]
liste_jour = list(donnees['jour'])
liste_coef_matin = list(donnees['coef_matin'])
liste_coef_soir = list(donnees['coef_soir'])


plt.xlim(1, 30)
plt.ylim(20, 120)
plt.show()

plt.figure('Marées à Noirmoutier')
plt.title('2026')
plt.xlabel("Jour du mois")
plt.ylabel("Coefficient de la marée du matin")
plt.plot(liste_jour, liste_coef_matin, ".-b")
plt.plot(liste_jour, liste_coef_soir, ".-r")
plt.plot((1,30), (40, 40), "--y")
plt.plot((1,30), (60, 60), "--y")
plt.show()


# tp3


'''
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
'''


# tp4

#q1

def lireCoef_mois(Nomfichier): #q1
    listeCoef_mois=[]
    classes = pd;read_csv(Nomfichier)
    listeCoef_matin=[]
    listeCoef_soir=[]
    n=donnee.shape[0]
    for q in range(n):
        if pd.isna(liste_coef_matin[q])== False:
            listeCoef_mois.extend(liste_coef_matin)
        if pd.isna(liste_coef_soir[q])== False:    
            listeCoef_mois.extend(liste_coef_soir)
        return listeCoef_mois
'''
#q2
def afficher(NomFichier)


liste_Coef_mois = lireCoef_mois('marees_noirmoutier_octobre_2026.csv')'''