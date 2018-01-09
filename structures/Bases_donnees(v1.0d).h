#pragma once
#define CONSTANTE_A_CHANGER 100
typedef struct coord {//coordonn�es d'un lieu (latitude, longitude)

	int x; // latitude
	int y; //longitude
}coord;

typedef struct dim{//dimensions d'un objet

	int L;//longueur
	int H;//hauteur
	int P;//profondeur
}dim;

typedef struct departement {

	int Id;//num�ro du d�partement
	coord coordonnees;//coordonnees du centre du departement
}departement;

typedef struct adresse {

	int numero;//num�ro de rue
	char rue[50];//nom de rue
	char ville[50];//nom de ville
	char code_postal[10];
	
}adresse;

typedef struct article {//caract�ristiques d'un article

	int Id;//r�f�rence de l'article
	char nom[50];
	char description[150];
	char type[30];//cat�gorie de l'article (ex:m�nager, electronique, alimentaire etc...)
	dim taille;//dimensions de l'article
}article;

typedef struct entrepot {//caract�ristiques de l'entrep�t + inventaire

	int Id;//num�ro de l'entrep�t
	stock tab_stock[CONSTANTE_A_CHANGER];//inventaire (max fix� � 100 articles diff�rents)
	coord coordonnees;//coordonn�es de l'entrep�t
	livraison tab_livraisons[CONSTANTE_A_CHANGER];//livraisons devant �tre effectu�es par l'entrep�t
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
	stock commande;//article command� + nombre d'articles command�s
	int code;//code pour ouvrir le casier � la r�ception
}commande;

typedef struct  stock {

	int Id_article;//identifiant de l'article
	int Nb;//nombre d'articles restant dans un entrepot ou nombre d'articles command�s
}stock;

typedef struct slot {//caract�ristiques d'un casier d'une pickup station

	dim taille;//dimensions du casier
	int dispo;// disponibilit� du casier: 0=disponible, 1=occup�
	int code; //code correspondant � la commande
}slot;

typedef struct Pickup {//carct�ristiques d'une pickup station

	int Id;// identifiant de la pickup station
	int Nb_places;//nombre de casiers disponibles dans la station
	coord coordonnees;//coodonnees de la station
	adresse adresse; //adresse de la station
	slot tab_slot[]; // tableau contenant les caract�ristiques de tous les casiers de la station
	
}PickupStation;

typedef struct livr {

	adresse adresse_pickup;//adresse de livraison
	commande commande;//commande du client

}livraison;