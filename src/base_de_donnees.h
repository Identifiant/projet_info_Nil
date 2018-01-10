/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   base_de_donnees.h
 * Author: liam
 *
 * Created on 9 janvier 2018, 10:29
 */

#ifndef BASE_DE_DONNEES_H
#define BASE_DE_DONNEES_H

typedef struct  stock {

	int Id_article;//identifiant de l'article
	int Nb;//nombre d'articles restant dans un entrepot
}stock;

typedef struct commande {
	int Id_client;
	stock commande;//article commandé + nombre d'articles commandés
	int code;//code pour ouvrir le casier à la réception
}commande;

typedef struct adresse {

	int numero;//numéro de rue
	char rue[50];//nom de rue
	char ville[50];//nom de ville
	char code_postal[10];
	
}adresse;

typedef struct livr{

	adresse adresse_pickup;//adresse de livraison
	commande commande;//commande du client

}livraison;


typedef struct coord {//coordonnées d'un lieu (latitude, longitude)

	double x; // latitude
	double y; //longitude
}coord;

typedef struct dim{//dimensions d'un objet

	int L;//longueur
	int H;//hauteur
	int P;//profondeur
}dim;

typedef struct Ville {

	char nom[100];//numéro du département
	coord coordonnees;//coordonnees du centre du departement
}Ville;

typedef struct article {//caractéristiques d'un article

	int Id;//référence de l'article
	char nom[50];
	char description[150];
	char type[30];//catégorie de l'article (ex:ménager, electronique, alimentaire etc...)
	dim taille;//dimensions de l'article
}article;

typedef struct entrepot {//caractéristiques de l'entrepôt + inventaire

	int Id;//numéro de l'entrepôt
	stock tab_stock[100];//inventaire (max fixé à 100 articles différents)
	coord coordonnees;//coordonnées de l'entrepôt
	livraison tab_de_livraison[100];
}entrepot;

typedef struct client {//informations d'un client

	int Id;//identifiant du client (4 chiffres)
	char nom[20];
	char prenom[20];
	adresse adresse;
	int code;//mot de passe du client
	int tel;
}client;


typedef struct slot {//caractéristiques d'un casier d'une pickup station

	dim taille;//dimensions du casier
	int dispo;// disponibilité du casier: 0=occupe, 1=disponible
	int code; //code correspondant à la commande
}slot;

typedef struct Pickup {//carctéristiques d'une pickup station

	int Id;// identifiant de la pickup station
	int Nb_places;//nombre de casiers disponibles dans la station
	coord coordonnees;//coodonnees de la station
	slot tab_slot[]; // tableau contenant les caractéristiques de tous les casiers de la station
}PickupStation;

typedef struct stock_entrepot{
    
    int Id_article;
    int Nb;
    dim dim_article;
    
}stock_entrepot;

typedef struct disp_pick{
    
    int Id_com;
    int type;
    int nb_objets;
}disp_pick;

#endif /* BASE_DE_DONNEES_H */

