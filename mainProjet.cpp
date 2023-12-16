#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream> 
#include <stdlib.h>
#include "client.cpp"
#include "vol.cpp"
#include "aeroport.cpp"
#include "compagnie.cpp"
#include "avionDeLigne.cpp"
#include "jet.cpp"
#include "Avion.cpp"

const std::string ACCOUNTS_FILE = "accounts.txt";
const std::string TICKETS_FILE = "tickets.txt";

void menuDebut();
void menuPrincipal();
void rubriqueInfo();
void createAccount();
void login();
void infoVol();
void acheterBillet(Vol& vol);


Client client;
Aeroport aeroportDeParis("Aeroport International de Paris", "144 rue de chennviere", 3 );
Aeroport aeroportDeLondre("Aeroport International de Londre", "54 avenue of Boston", 2);
Compagnie AirFrance("Air France", 7, 10, 1933, "France", 33141567800LL, "airfrance@gmail.com", "www.airfrance.com");  
Vol volParisLondre(18, 04, 2023,18, 04, 2023, &aeroportDeParis, &aeroportDeLondre, 140, 246.58, 5, 4, &AirFrance);
 


void acheterBillet(int a, Vol& vol) {
    std::ifstream ticketsFileIn(TICKETS_FILE);
    std::string line;
    bool ticketBooked = false;
    int count = 0;
        while ( std::getline(ticketsFileIn, line)) {
            std::istringstream pm(line);
            std::string premierMot;
            pm >> premierMot;
            if ( premierMot == std::to_string(a) ){
                ++count;
            }
            if (line.find(std::to_string(vol.getIdVol()) + " " + std::to_string(client.getNumeroClient())) != std::string::npos){
                ticketBooked = true;
            }
        }
        if (ticketBooked){
            std::cerr << "Erreur: billet déjà réservé sur votre compte. Si vous souhaitez réserver ce vol pour une autre personne, créer ou connecter un compte à son nom." << std::endl;
        } else {
            std::ofstream ticketsFileOut(TICKETS_FILE, std::ios::app);
            ticketsFileOut << vol.getIdVol() << " " << client.getNumeroClient() << "  " << std::to_string(count) << "  " << "Economie" << "  " << std::to_string(count) << std::endl;
            ticketsFileOut.close();
            std::cout << "Billet reserve!" << std::endl;
        }
}


void menuDebut() {

    int choice;

    do {
        std::cout << "Choisissez une option :" << std::endl;
        std::cout << "                       " << std::endl;
        std::cout << "1. Se connecter" << std::endl;
        std::cout << "                       " << std::endl;
        std::cout << "2. Creer un compte" << std::endl;
        std::cout << "                       " << std::endl;
        std::cout << "0. Quitter" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                login();
                break;
            case 2:
                system("cls");
                createAccount();
                break;
            case 0:
                std::cout << "Au revoir !" << std::endl;
                exit(0);
            default:
                std::cerr << "Option invalide. Veuillez reessayer." << std::endl;
        }
    } while (choice != 0);

}


// Fonction pour créer un compte
void createAccount() {
    std::string username, password, nom, prenom, dateNaissance, ville, numeroTel, mail;
    int ID;

    std::cout << "Entrez votre nom d'utilisateur : ";
    std::cin >> username;

    std::cout << "Entrez votre mot de passe : ";
    std::cin >> password;

    std::cout << "Entrez votre nom: ";
    std::cin >> nom;

    std::cout << "Entrez votre prenom: ";
    std::cin >> prenom;

    std::cout << "Entrez votre date de naissance: ";
    std::cin >> dateNaissance;

    std::cout << "Entrez votre ville: ";
    std::cin >> ville;

    std::cout << "Entrez votre numero de telephone: ";
    std::cin >> numeroTel;

    std::cout << "Entrez votre mail: ";
    std::cin >> mail;

    // Charger les comptes existants depuis le fichier texte
    std::ifstream accountsFileIn(ACCOUNTS_FILE);
    std::string line;
    bool usernameExists = false;
    int lineCount = 0;

    while (std::getline(accountsFileIn, line)) {
        ++lineCount;
        if (line.find(username) != std::string::npos) {
            usernameExists = true;
            break;
        }
    }

    accountsFileIn.close();

    // Vérifier si le nom d'utilisateur existe déjà
    if (usernameExists) {
        std::cerr << "Erreur : Le nom d'utilisateur existe déjà." << std::endl;
        return;
    }
    
    ID = lineCount + 1;

    // Ajouter le nouveau compte
    std::ofstream accountsFileOut(ACCOUNTS_FILE, std::ios::app);
    accountsFileOut << username << " " << password << " " << ID << " " << nom << " " << prenom << " " << dateNaissance << " " << ville << " " << numeroTel << " " << mail << std::endl;
    accountsFileOut.close();

    std::cout << "Compte cree avec succes." << std::endl;
}

// Fonction pour se connecter
void login() {
    std::string username, password;

    std::cout << "Entrez votre nom d'utilisateur : ";
    std::cin >> username;

    std::cout << "Entrez votre mot de passe : ";
    std::cin >> password;

    // Charger les comptes existants depuis le fichier texte
    std::ifstream accountsFileIn(ACCOUNTS_FILE);
    std::string line;
    bool informationsDeConnexion = false;

    while (std::getline(accountsFileIn, line)) {
        if (line.find(username + " " + password) != std::string::npos) {
            informationsDeConnexion = true;
            int IdClient;
            std::string nom, prenom, dateNaissance, ville, numeroTel, mail;
            std::istringstream recuperer(line);          
            recuperer >> username >> password >> IdClient >> nom >> prenom >> dateNaissance >> ville >> numeroTel >> mail;
            client = Client(IdClient,nom,prenom,dateNaissance,ville,numeroTel,mail);
            break;
        }
    }

    accountsFileIn.close();

    // Vérifier si les informations de connexion sont correctes
    if (informationsDeConnexion) {
        system("cls");
        std::cout << "Connexion reussie. Bienvenue, " << username << " !" << std::endl;
        menuPrincipal();

    }

    else {
        std::cerr << "Erreur : Nom d'utilisateur ou mot de passe incorrect." << std::endl;
    }
}


//Fonction pour afficher le menu principal

void menuPrincipal(){

        int choice;
        system("cls");
        do {
            std::cout << "Choisissez une option :" << std::endl;
            std::cout << "1. Consulter des vols" << std::endl;
            std::cout << "2. Consulter votre compte" << std::endl;
            std::cout << "3. Afficher rubrique informations" << std::endl;
            std::cout << "4. Se deconnecter" << std::endl;

            std::cin >> choice;

            switch (choice) {
                case 1:
                    infoVol();
                    break;
                case 2:
                    system("cls");
                    client.displayInfoClient();
/*
                    std::ifstream ticketsFileIn(TICKETS_FILE);
                    std::string line;
                    while ( std::getline(ticketsFileIn, line)) {

                    }*/
                    break;
                case 3:
                    rubriqueInfo();
                    break;
                case 4:
                    std::cout << "Deconnexion reussie. Retour a la page d'accueil." << std::endl;
                    menuDebut();
                    break;
                default:
                    std::cerr << "Option invalide. Veuillez réessayer." << std::endl;
            }
        } while (choice != 3);
}

// Fonction pour afficher rubrique informations 

void rubriqueInfo() {
    system("cls");
    int choice;
    int quitterRubrique;
    do {
        std::cout << "--------------------------------------------------\n";
        std::cout << "--------------RUBRIQUE INFORMATIONS---------------\n";
        std::cout << "\n";
        std::cout << "Choisissez une option : \n";
        std::cout << "1. Consulter les differentes compagnies aeriennes \n";
        std::cout << "2. Consulter les differents aeroports \n";
        std::cout << "3. Consulter les differents avions et leurs caracteristiques \n";
        std::cout << "0. Retour menu \n";
        std::cout << "--------------------------------------------------\n"; 
        
        std::cin >> choice;


        switch (choice) {
            case 1:
                system("cls");
                std::cout << "--------------------------------------------------\n";
                std::cout << "-----------LISTE COMPAGNIES AERIENNES-------------\n";
                std::cout << "\n";
                //AirFrance.displayInfoCompagnie();
                //DeltaAirLines.displayInfoCompagnie();
                //Emirates.displayInfoCompagnie();
                //Lufthansa.displayInfoCompagnie();
                //CQatarAirways.displayInfoCompagnie();

                std::cout << "0. Pour quitter \n";
                std::cin >> quitterRubrique;

                if (quitterRubrique == 0) {
                    std::cout << "Retour au menu principal \n";
                    break;
                } else {
                    while (quitterRubrique != 0) {
                        std::cout << "Veuillez entrer 0 pour quitter \n";
                        std::cin >> quitterRubrique;    
                    }
                }
                break;

            case 2:
                system("cls");
                std::cout << "--------------------------------------------------\n";
                std::cout << "-----------------LISTE AEROPORTS------------------\n";
                std::cout << "\n";
                //aeroportDeParis.displayInfoAeroport();
                //aeroportDeLondre.displayInfoAeroport();
                //aeroportDeBerlin.displayInfoAeroport();

                std::cout << "0. Pour quitter \n";
                std::cin >> quitterRubrique;

                if (quitterRubrique == 0) {
                    std::cout << "Retour au menu principal \n";
                    break;
                } else {
                    while (quitterRubrique != 0) {
                        std::cout << "Veuillez entrer 0 pour quitter \n";
                        std::cin >> quitterRubrique;    
                    }
                }
                break;


            case 3:
                system("cls");
                std::cout << "--------------------------------------------------\n";
                std::cout << "------------------LISTES AVIONS-------------------\n";
                std::cout << "\n";

                std::cout << "LISTE AVIONS DE LIGNES : \n";

                // Avion1.displayInfoAvion();
                // Avion2.displayInfoAvion();
                // Avion3.displayInfoAvion();
                // Avion4.displayInfoAvion();
                // Avion5.displayInfoAvion();

                std::cout << "LISTE JET PRIVES : \n";

                // Jet1.displayInfoAvion();
                // Jet2.displayInfoAvion();
                // Jet3.displayInfoAvion();
                // Jet4.displayInfoAvion();
                // Jet5.displayInfoAvion();

                std::cout << "0. Pour quitter \n";
                std::cin >> quitterRubrique;

                if (quitterRubrique == 0) {
                    std::cout << "Retour au menu principal \n";
                    break;
                } else {
                    while (quitterRubrique != 0) {
                        std::cout << "Veuillez entrer 0 pour quitter \n";
                        std::cin >> quitterRubrique;                   
                    }
                }        
                break;
            case 0:
                std::cout << "Retour au menu principal.\n";
                menuPrincipal();
                return;
            default:
                std::cerr << "Option invalide. Veuillez ressayez. \n";
        }
    } while (true);
}

void infoVol() {
    system("cls");
    int choice;
    int quitterRubrique;
    do {
        std::cout << "--------------------------------------------------\n";
        std::cout << "-----------------------VOLS-----------------------\n";
        std::cout << "\n";
        std::cout << "Choisissez une option : \n";
        std::cout << "1. Afficher les vols \n";
        std::cout << "0. Quitter \n";
        std::cout << "--------------------------------------------------\n"; 
        
        std::cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                std::cout << "--------------------------------------------------\n";
                std::cout << "--------------------LISTE VOLS--------------------\n";
                std::cout << "\n";
                volParisLondre.displayInfoVol();
                //volLondreBerlin.displayInfoVol();
                std::cout << "0. Pour quitter \n ";
                std::cin >> quitterRubrique;

                if (quitterRubrique == 0) {
                    system("cls");
                    std::cout << "Retour au menu principal \n";
                    break;
                } else if (( quitterRubrique > 0 ) and ( quitterRubrique < 6 )) {
                    if ( quitterRubrique == 1 ){
                        acheterBillet(1, volParisLondre);
                    }
                    if ( quitterRubrique == 2 ){
                        //acheterBillet(2, volLondreBerlin);
                    }
                    if ( quitterRubrique == 3 ){
                        //acheterBillet(3, volBerlinParis);
                    }
                    if ( quitterRubrique == 4 ){
                        //acheterBillet(4, volParisNewYork);
                    }
                    if ( quitterRubrique == 5 ){
                        //acheterBillet(5, volNewYorkParis);
                    }
                } else {
                    while (quitterRubrique != 0) {
                        std::cout << "Veuillez entrer 0 pour quitter \n";
                        std::cin >> quitterRubrique;    
                    }
                }
                break;
            case 0:
                std::cout << "Quitter la rubrique informations.\n";
                return;
            default:
                std::cerr << "Option invalide. Veuillez ressayez. \n";
        }
    } while (true);
}






int main() { 
    menuDebut();

    return 0;
}