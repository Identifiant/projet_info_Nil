/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lectureBdd.h
 * Author: liam
 *
 * Created on 9 janvier 2018, 14:52
 */

#ifndef LECTUREBDD_H
#define LECTUREBDD_H
#define TAILLE_MAX 300
#include "base_de_donnees.h"

Ville* chargerBddVille(char nom_fichier[]);
//char** bddEnTableaudeChar(char nom_fichier[]);
int nb_de_ligne(char *nom_fichier);
stock_entrepot charger_entrepot_disptach(char nom_fichier[]);
int charger_dispatch_entrepot(char nom_fichier[]);
disp_pick charger_dipatch_pick_up(char nom_fichier[]);
#endif /* LECTUREBDD_H */

