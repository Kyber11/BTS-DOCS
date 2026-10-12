import matplotlib.pyplot as plt

import pandas as pd

donnees = pd.read_csv('marees_noirmoutier_septembre_2026.csv')
taille = donnees.shape
print(taille)
nb_lignes, nb_colonnes = donnees.shape
print('Nombre de lignes :', nb_lignes)
print('Nombre de colonnes :', nb_colonnes)
print(donnees)
print(donnees['coef_matin'])
print(donnees['coef_matin'].max())
print(donnees['coef_soir'].max())

# rang de la ligne ou se trouve le coefficient maximum
i = donnees['coef_matin'].idxmax()
j = donnees['coef_soir'].idxmax()

# jour correspondant
jour_coef_max_matin = donnees['jour'][i]
jour_coef_max_soir = donnees['jour'][j]
print("Coefficient maximum :", jour_coef_max_matin, jour_coef_max_soir)
liste_jour = list(donnees['jour'])
liste_coef_matin = list(donnees['coef_matin'])
liste_coef_soir = list(donnees['coef_soir'])
print(liste_jour)

plt.xlim(1, 30)
plt.ylim(20, 120)
plt.show()

plt.figure('Marées à Noirmoutier')
plt.title('Septembre 2026')
plt.xlabel("Jour du mois")
plt.ylabel("Coefficient de la marée du matin")
plt.plot(liste_jour, liste_coef_matin, ".-b")
plt.plot(liste_jour, liste_coef_soir, ".-r")
plt.plot((1,30), (40, 40), "--y")
plt.plot((1,30), (60, 60), "--y")
plt.show()
