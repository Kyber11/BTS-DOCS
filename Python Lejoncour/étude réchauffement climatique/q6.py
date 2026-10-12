# -*- coding: utf-8 -*-
"""
Created on Mon Sep 14 08:19:15 2026

@author: armand.beaux
"""

import math 
import pandas as pd
donnees = pd.read_csv('marees_noirmoutier_octobre_2026.csv')

def RecupDonnees(nomDeFichier):
    donnees = pd.read_csv(nomDeFichier)    
    jours = list(donnees['jour'])
    liste_coef_matin = list(donnees['coef_matin'])
    liste_coef_soir = list(donnees['coef_soir'])    
    coef_mois = []   
    for i in range(len(jours)):
        if not math.isnan(liste_coef_matin[i]):
            coef_mois.append(liste_coef_matin[i])
            
        if not math.isnan(liste_coef_soir[i]):
            coef_mois.append(liste_coef_soir[i]) 
    return coef_mois


def rech_max(blabla):
    list_max=[]
    coef=blabla[0]
    precedent=coef
    pente=0
    for elecoef in range(len(blabla)) :
        if coef > precedent :
            pente = 1
        if coef < precedent :
            if pente == 1 :
                list_max.append(elecoef)
            pente = -1
        precedent=coef
    return list_max


# programme principal
liste=RecupDonnees(donnees)
print(rech_max(liste))

