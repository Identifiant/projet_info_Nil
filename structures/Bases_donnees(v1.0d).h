#pragma once
#define CONSTANTE_A_CHANGER 100
typedef struct coord {//coordonnées d'un lieu (latitude, longitude)

	int x; // latitude
	int y; //longitude
}coord;

typedef struct dim{//dimensions d'un objet

	int L;//longueur
	int H;//hauteur
	int P;//profondeur
}dim;

typedef struct departement {

	int Id;//numéro du département
	coord coordonnees;//coordonnees du centre du departement
}departement;

typedef struct adresse {

	int numero;//numéro de rue
	char rue[50];//nom de rue
	char ville[50];//nom de ville
	char code_postal[10];
	
}adresse;

typedef struct article {//caractéristiques d'un article

	int Id;//référence de l'article
	char nom[50];
	char description[150];
	char type[30];//catégorie de l'article (ex:ménager, electronique, alimentaire etc...)
	dim taille;//dimensions de l'article
}article;

typedef struct entrepot {//caractéristiques de l'entrepôt + inventaire

	int Id;//numéro de l'entrepôt
	stock tab_stock[CONSTANTE_A_CHANGER];//inventaire (max fixé à 100 articles différents)
	coord coordonnees;//coordonnées de l'entrepôt
	livraison tab_livraisons[CONSTANTE_A_CHANGER];//livraisons devant être effectuées par l'entrepôt
}entrepot;

typedef struct client {//informations d'un client

	int Id;//identifiant du client (4 chiffres)
	char nom[20];
	char prenom[20];
	adresse adresse;
	int code;//mot de passe du client
	int tel;
}client;

typedef struct commande {
	int Id_client;
	stock commande;//article commandé + nombre d'articles commandés
	int code;//code pour ouvrir le casier à la réception
}commande;

typedef struct  stock {

	int Id_article;//identifiant de l'article
	int Nb;//nombre d'articles restant dans un entrepot ou nombre d'articles commandés
}stock;

typedef struct slot {//caractéristiques d'un casier d'une pickup station

	dim taille;//dimensions du casier
	int dispo;// disponibilité du casier: 0=disponible, 1=occupé
	int code; //code correspondant à la commande
}slot;

typedef struct Pickup {//carctéristiques d'une pickup station

	int Id;// identifiant de la pickup station
	int Nb_places;//nombre de casiers disponibles dans la station
	coord coordonnees;//coodonnees de la station
	adresse adresse; //adresse de la station
	slot tab_slot[]; // tableau contenant les caractéristiques de tous les casiers de la station
	
}PickupStation;

typedef struct livr {

	adresse adresse_pickup;//adresse de livraison
	commande commande;//commande du client

}livraison;