/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOM 100
#include "base_de_donnees.h"
#define SEPARATEUR ','



int nb_de_ligne(char *nom_fichier)
{
    FILE *fichier = NULL;
    
    fichier = fopen(nom_fichier,"r");
    
    int nbOfLine = 0;
    
    char line[1000]="";
    
    if(fichier != NULL) {
        
        while(fgets(line,sizeof(line),fichier)!= NULL){
            nbOfLine++;
            //printf("%d ",nbOfLine);
        }
    }else{
        printf("Impossible d'ouvrir le fichier");
    }
    
    return nbOfLine;
}

Ville* chargerBddVille(Ville ville,char nom_fichier[]){
    
    FILE *fichier = NULL;
    
    fichier = fopen(nom_fichier,"r");   
    char nomVille[1000]="";
    char longitude[1000]="";
    char latitude[1000]="";
    Ville *tab;
    tab = (Ville*)malloc(sizeof(Ville)*(nb_de_ligne(nom_fichier)/3));
    int compteur=0;
    int autreCompteur=0;
    
    if(fichier != NULL){
        for(int i=0;i<nb_de_ligne(nom_fichier);i++){
            if(compteur == 0){
                fgets(nomVille,sizeof(nomVille),fichier);
                strcpy(tab[autreCompteur].nom,nomVille);      
            }else if(compteur == 1){
                fgets(longitude,sizeof(longitude),fichier);
                tab[autreCompteur].coordonnees.x = atof(longitude);
            }else if(compteur == 2){
                fgets(latitude,sizeof(latitude),fichier);
                tab[autreCompteur].coordonnees.y = atof(latitude);  
            }
            compteur++;
            if (compteur>=3){
                compteur=0;
                autreCompteur++;
            }
        }
        return tab;
    }else{
        return 0;
    }
}


