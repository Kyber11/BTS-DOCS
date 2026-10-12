import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm
lowess = sm.nonparametric.lowess

# générer un nuage de points aléatoires qu'il faudra lisser
n = 100
x = np.linspace(0, 10, n)
y = (x + np.random.random(n)) ** 2

# choix du paramètre frac de la fonction lowess pour le lissage
f = 0.4

# calculer le lissage à l'aide de la fonction lowess
# exog=x : abscisses des points 
# endog=y : ordonnées des points
resultat_lissage = lowess(exog=x, endog=y, frac=f)

# resultat_lissage est un tableau numpy à 2 dimensions
# 1ère colonne : valeurs de abscisses après lissage
# 2ème colonne : valeurs des ordonnées après lissage
x_lowess = resultat_lissage[:, 0]
y_lowess = resultat_lissage[:, 1]

plt.figure("Lissage à l'aide de la fonction lowess")
plt.title(f"Paramètre frac={f}")
plt.xlabel('x')
plt.ylabel('y')
# tracer le nuage de points
plt.plot(x, y, ".b")
# tracer la courbe lissée obtenue avec lowess
plt.plot(x_lowess, y_lowess, "r")
plt.show()