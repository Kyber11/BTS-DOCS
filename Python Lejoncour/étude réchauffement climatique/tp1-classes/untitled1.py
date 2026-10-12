# -*- coding: utf-8 -*-
"""
Created on Mon Sep 21 11:49:57 2026

@author: armand.beaux
"""

import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm
lowess = sm.nonparametric.lowess
# générer un nuage de 100 points aléatoires qu'il faudra lisser
# premier point en x=0 et dernier point en x=10
n = 100
x = np.linspace(0, 10, n)
# déterminer aléatoirement l’abscisse des points
y = (x + np.random.random(n)) ** 2
# choix du paramètre frac de la fonction lowess pour le lissage
f =0.4
# exog=x : abscisses des points 
# endog=y : ordonnées des points
resultat_lowess = lowess(exog=x, endog=y, frac=f)
# resultat_lowess est un tableau numpy à 2 dimensions
# 1ère colonne : valeurs de abscisses
# 2ème colonne : valeurs des ordonnées
xlowess = resultat_lowess[:, 0]
ylowess = resultat_lowess[:, 1]
# tracer le nuage de points
plt.plot(x, y, ".b")
# tracer la courbe lissée obtenue avec lowess
plt.plot(xlowess, ylowess, "r")
plt.show()