#Created on Mon Sep 14 09:04:47 2026


import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import statsmodels.api as sm
lowess = sm.nonparametric.lowess

class Climat:
    
    def __init__(self, fichier_csv):
       df=pd.read_csv(fichier_csv)
       # attributs de la classe
       self.annees=list(df['annee'])
       self.anomalies=list(df['anomalie'])
       self.nbLi= df.shape[0]
       self.nbCol=df.shape[1]
       self.enTetes=['annee' , 'anomalie']
       self.moyennes=[]
       self.ylowess=[]
    
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
        
    def CalMoyGlis(self, p):
        n=len(self.anomalies)
        self.moyennes=[]
        somme=0
        for i in range(0,n-p+1):
            for j in range(0,p-1):
                somme+=self.anomalies[i+j]
            m=somme/p
            self.moyennes.append(m)
        return len(self.moyennes)
    
    def lissageLowess(self, f):
        resultat_lowess = lowess(exog=self.annees, endog=self.anomalies, frac=f)
        self.ylowess = list(resultat_lowess[:, 1])
        return self.ylowess
    
    def affichageLowess(self):
        xlowess = self.annees
        plt.plot(self.annees, self.anomalies, "-r")
        k=(len(self.annees)-len(self.moyennes)) // 2
        plt.plot(xlowess, self.ylowess, "-g")
        plt.plot(self.annees[k, -k], self.moyennes, "-r")
        plt.show()
    
    def getNbLi(self):
        return self.nbLi
    
    def getNbCol(self):
        return self.nbCol
    
    def getEnTetes(self):
        return self.enTetes
    
clim= Climat('anomalies_temperature.csv')
clim.CalMoyGlis(7)
clim.lissageLowess(0.2)
clim.affichageLowess()
    



