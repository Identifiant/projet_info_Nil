/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: liam
 *
 * Created on 9 janvier 2018, 10:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lectureBdd.h"
#include "base_de_donnees.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Ville *ville;
    
    /*char nom_fichier[] = "pick_up";
    char pick[] = "pick_up";
    char art[] = "article";
    char entr[] = "entrepots";
    FILE *fichier=NULL;
    fichier = fopen(nom_fichier,"r");
    char renduBdd[100][100];
    char chaine[100];
    int nbLigneDeFichier=0;
    
    if(fichier != NULL) {
        while(!feof(fichier)){
            fscanf(fichier,"%s",chaine);
            strcpy(renduBdd[nbLigneDeFichier],chaine);
            nbLigneDeFichier++;
        } 
    }
    if(strcmp(pick,nom_fichier) == 0 || strcmp(art,nom_fichier) == 0 || strcmp(entr,nom_fichier) == 0){
        
        strcpy(renduBdd[(nb_de_ligne(nom_fichier))-1],"\0");
    }
    
    for(int i=0;i<nb_de_ligne(nom_fichier);i++){
        printf("%s\n",renduBdd[i]);
    }*/
    return (EXIT_SUCCESS);
}

