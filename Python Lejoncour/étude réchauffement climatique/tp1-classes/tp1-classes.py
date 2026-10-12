# -*- coding: utf-8 -*-
"""
Created on Mon Sep 14 09:04:47 2026

@author: armand.beaux
"""

import pandas as pd
import matplotlib.pyplot as plt

class Climat:
    
    def __init__(self, fichier_csv):
       df=pd.read_csv(fichier_csv)
       # attributs de la classe
       self.annees=list(df['annee'])
       self.anomalies=list(df['anomalie'])
       self.nbLi= df.shape[0]
       self.nbCol=df.shape[1]
       self.enTetes=['annee' , 'anomalie']
       self.moyenne=[]
    
    def affichage_graphique(self):
        plt.figure(figsize=(12, 6))
        plt.plot(self.annees, self.anomalies)
        plt.title("Évolution des anomalies de température mondiale (1880 - 2025)", fontsize=14, fontweight='bold', pad=15)
        plt.xlabel("Années", fontsize=12)
        plt.ylabel("Écart de température (°C)", fontsize=12)   
        plt.xlim(1875, 2030)
        plt.grid(axis='y', linestyle='--', alpha=0.5)
        plt.tight_layout()
        plt.show()
        
    def CalcMoyGliss(self, p):
        #calcul des valeurs moyennes 
        
        #ajout des valeur moyenne dans la liste
        moy=
        '''self.moyenne.append(moy)
        nombre_moyennes=len(self.moyenne)
        return nombre_moyennes'''
        pass
    
    def getNbLi(self):
        return self.nbLi
    
    def getNbCol(self):
        return self.nbCol
    
    def getEnTetes(self):
        return self.enTetes
    



clim = Climat("anomalies_temperature.csv")
# suite du programme
nb_lignes = clim.getNbLi()
nb_colonnes = clim.getNbCol()
liste_Entetes = clim.getEnTetes()
clim.affichage_graphique()