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



int nb_de_ligne(char nom_fichier[])
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
    tab = (Ville*)malloc(sizeof(Ville)*(nb_de_ligne(nom_fichier)/3));//allocation d'un tableau de type ville pour 
                                                                     // contenir l'ensemble des villes présentes dans le fichier 
    int compteur=0;
    int autreCompteur=0;
    
    if(fichier != NULL){
        for(int i=0;i<nb_de_ligne(nom_fichier);i++){
            if(compteur == 0){
                fgets(nomVille,sizeof(nomVille),fichier);//lecture d'un nom de ville
                strcpy(tab[autreCompteur].nom,nomVille);//copie de la ligne lue dans le tableau nom de la structure ville      
            }else if(compteur == 1){
                fgets(longitude,sizeof(longitude),fichier);//lecture longitude
                tab[autreCompteur].coordonnees.x = atof(longitude);//sauvegarde la longitude en tant que coordonnée x sou forme de flottant dans la structure ville
            }else if(compteur == 2){
                fgets(latitude,sizeof(latitude),fichier);//lecture latitude
                tab[autreCompteur].coordonnees.y = atof(latitude); //sauvegarde la longitude en tant que coordonnée x sou forme de flottant dans la structure ville 
            }
            compteur++;//incrémentation du compteur
            if (compteur>=3){//Twist :toutes les 3 lignes, on remet à 0 le compteur                
                compteur=0;  //Comme ça, il y aura toujours un cas ou le compteur est à 0,1 et 2
                autreCompteur++;//qui correspond au cas ou est lu le nom, la longitude et la latitude d'une ville
            }
        }
        fclose(fichier);
        return tab;
    }else{
        return 0;
    }
}
    
/*char **bddEnTableaudechar(char nom_fichier[]){
	
    
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
    return renduBdd;
}*/


//le fichier texte comporte 5 lignes en tout et pour tout
stock_entrepot charger_entrepot_disptach(char nom_fichier[]){
    
    stock_entrepot reponse;
    
    FILE *fichier = fopen(nom_fichier,"r");
    char champ[100];
    int compteur=0;
    
    if(fichier != NULL){
        for(int i=0;i<nb_de_ligne(nom_fichier);i++){
            if(compteur == 0){
                //on est à la 1ère ligne, champ ID de l'article
                fgets(champ,sizeof(champ),fichier);
                reponse.Id_article = atoi(champ);
            }else if(compteur == 1){
                //2ème ligne, champ nombres d'articles
                fgets(champ,sizeof(champ),fichier);
                reponse.Nb = atoi(champ);
            }else if(compteur == 2){
                //3ème ligne, chmap hauteir de l'article
                fgets(champ,sizeof(champ),fichier);
                reponse.dim_article.H = atoi(champ);
            }else if(compteur == 3){
                //4ème ligne, champ longueur de l'article
                fgets(champ,sizeof(champ),fichier);
                reponse.dim_article.L = atoi(champ);
            }else if(compteur == 4){
                //5ème ligne, champ profondeur de l'article
                fgets(champ,sizeof(champ),fichier);
                reponse.dim_article.P = atoi(champ);
            }
            compteur++;
        }
        return reponse;
        fclose(fichier);
    }
}


//1 seule ligne en tout et pour tout dans le fichier
int charger_dispatch_entrepot(char nom_fichier[]){
    
    int idArticle;
    char champ[100];
    FILE *fichier = NULL;
    
    if(fichier != NULL){
        for(int i=0;i<nb_de_ligne(nom_fichier);i++){
            //Seule ligne du fichier, l'ID de l'article
            fgets(champ,sizeof(champ),fichier);
            idArticle = atoi(champ);
        }
    }
    return idArticle;
}

disp_pick charger_dipatch_pick_up(char nom_fichier[]){
    
    char champ[100];
    FILE *fichier = NULL;
    int compteur=0;
    
    disp_pick commande;
    
    if(fichier != NULL){
        for(int i=0;i<nb_de_ligne(nom_fichier);i++){
            if(compteur==0){
                fgets(champ,sizeof(champ),fichier);
                commande.Id_com = atoi(champ);
            }else if(compteur == 1){
                fgets(champ,sizeof(champ),fichier);
                commande.nb_objets = atoi(champ);
            }else if(compteur == 2){
                fgets(champ,sizeof(champ),fichier);
                commande.type = atoi(champ);
            }
            compteur++;
        }
        return commande;
    }else{
        printf("Impossible d'ouvrir le fichier");
    }
}



