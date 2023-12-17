#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> // Bibliothèque permettant de "clear" l'invité de commandes
#include <sstream>  // Bibliothèque permettant d'attribuer à des variables les n ièmes premiers mots d'uine ligne 

// Implémentation des classes
#include "client.cpp"
#include "vol.cpp"
#include "aeroport.cpp"
#include "compagnie.cpp"
#include "avionDeLigne.cpp"
#include "jet.cpp"
#include "Avion.cpp"
#include "billet.cpp"

const std::string ACCOUNTS_FILE = "accounts.txt";
const std::string TICKETS_FILE = "tickets.txt";

void menuDebut();
void menuPrincipal();
void rubriqueInfo();
void createAccount();
void login();
void infoVol();
void infoCompte();
void acheterBillet(Vol& vol);

// Initialisation d'un objet Client
Client client;

// Initialisation d'un objet Billet
Billet billet;

// Initialisation des aeroports
Aeroport aeroportDeParis("Aeroport de Paris-Charles de Gaulle", "6 rue des bruyeres 95931 Roissy", 8 );
Aeroport aeroportDeLondres("London City Airport", "Hartmann Rd, London E16 2PX", 4);
Aeroport aeroportDeBerlin("Aeroport Willy-Brandt", "Melli-Beese-Ring 1,12529 Schonefeld", 5);
Aeroport aeroportDeNewYork("Aeroport international John F. Kennedy", "Queens, État de New York 11430", 6);

// Initialisation des compagnies
Compagnie AirFrance("Air France", 7, 10, 1933, "France", 33141567800LL, "airfrance@gmail.com", "www.airfrance.com");  
Compagnie DeltaAirLines("Delta Air Lines", 30, 05, 1924, "Etats-Unis", 18002211212LL, "deltaairlines@gmail.com", "deltaairlines.com");
Compagnie Emirates("Emirates", 25, 03, 1985, "Emirates Arabes Unis", 971600555555LL, "emirates@gmail.com", "emirates.com");
Compagnie Lufthansa("Lufthansa", 6, 01, 1953, "Allemagne", 496986799799LL, "lufthansa@gmail.com", "lufthansa.com");
Compagnie QatarAirways("Qatar Airways", 22, 11, 1993, "Qatar", 97440226000LL, "quatar@gmail.com", "qatar.com");

// Initialisation des vols
Vol volParisLondres(18, 04, 2023,18, 04, 2023, &aeroportDeParis, &aeroportDeLondres, 140, 246.58, 5, 4, &AirFrance);
Vol volLondresBerlin(20, 04, 2023, 22, 04, 2023, &aeroportDeLondres, &aeroportDeBerlin, 120, 198.75, 3, 2, &Lufthansa);
Vol volBerlinParis(24, 04, 2023, 25, 04, 2023, &aeroportDeBerlin, &aeroportDeParis, 160, 305.20, 1, 3, &AirFrance);
Vol volParisNewYork(30, 04, 2023, 05, 05, 2023, &aeroportDeParis, &aeroportDeNewYork, 200, 560.40, 7, 8, &Emirates);
Vol volNewYorkParis(8, 05, 2023, 15, 05, 2023, &aeroportDeNewYork, &aeroportDeParis, 180, 495.90, 6, 5, &DeltaAirLines);

// Initialisation des avions
AvionDeLigne Avion1("Boeing 737", 150, 900, 11000, 350, 5000, 1,1,2023, "France", &QatarAirways, &volParisLondres, 20, 100, 30);
AvionDeLigne Avion2("Boeing A380", 853, 900, 13100, 1235, 15200, 25,10,2007, "France", &DeltaAirLines, &volNewYorkParis, 98, 555, 14);
AvionDeLigne Avion3("Boeing 777", 550, 905, 13100, 239.370, 15843, 7,6,1995, "Etats-Unis", &Emirates, &volParisNewYork, 70, 430, 50);

JetPrive Jet1("Gulfstream G650", 19, 956, 15545, 24.5, 12964, 01,01,2012, "Etats-Unis", &Lufthansa, &volLondresBerlin, 1,1,1);
JetPrive Jet2("Bombardier Global 7500", 19, 930, 15545, 24.5, 14264, 01,01,2018, "Canada", &AirFrance, &volBerlinParis, 1,2,1);
 

void menuDebut() {

    int choice;

    do {
        system("cls");
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
        do {
            system("cls");
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
                    infoCompte();
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
    int choice;
    int quitterRubrique;
    do {
        system("cls");
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "--------------------RUBRIQUE INFORMATIONS--------------------\n";
        std::cout << "\n";
        std::cout << "Choisissez une option : \n";
        std::cout << "1. Consulter les differentes compagnies aeriennes \n";
        std::cout << "2. Consulter les differents aeroports \n";
        std::cout << "3. Consulter les differents avions et leurs caracteristiques \n";
        std::cout << "0. Retour menu \n";
        std::cout << "-------------------------------------------------------------\n"; 
        
        std::cin >> choice;


        switch (choice) {
            case 1:
                system("cls");
                std::cout << "----------------------------------------------------------------\n";
                std::cout << "-------------------LISTE COMPAGNIES AERIENNES-------------------\n";
                std::cout << "\n";
                AirFrance.displayInfoCompagnie();
                DeltaAirLines.displayInfoCompagnie();
                Emirates.displayInfoCompagnie();
                Lufthansa.displayInfoCompagnie();
                QatarAirways.displayInfoCompagnie();

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
                std::cout << "-----------------------------------------------------------------\n";
                std::cout << "-------------------------LISTE AEROPORTS-------------------------\n";
                std::cout << "\n";
                aeroportDeParis.displayInfoAeroport();
                aeroportDeLondres.displayInfoAeroport();
                aeroportDeBerlin.displayInfoAeroport();

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
                std::cout << "-----------------------------------------------------------------\n";
                std::cout << "--------------------------LISTES AVIONS--------------------------\n";
                std::cout << "\n";

                std::cout << "LISTE AVIONS DE LIGNES : \n";

                Avion1.displayInfoAvion();
                Avion2.displayInfoAvion();
                Avion3.displayInfoAvion();

                std::cout << "LISTE JET PRIVES : \n";

                Jet1.displayInfoAvion();
                Jet2.displayInfoAvion();

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

// Fonction permettant à l'utilisateur de réserver un billet


void acheterBillet(int a, Vol& vol) {
    std::ifstream ticketsFileIn(TICKETS_FILE);
    std::string line;
    bool ticketBooked = false;
    int count = 1;
        while ( std::getline(ticketsFileIn, line)) {
            std::istringstream pm(line);
            std::string premierMot;
            pm >> premierMot;
            // "if" comptant le nombre de billets déjà réservés afin d'attribuer un numero de billet et un siege à l'utilisateur
            if ( premierMot == std::to_string(a) ){
                ++count;
            }
            if (line.find(std::to_string(vol.getIdVol()) + " " + std::to_string(client.getNumeroClient())) != std::string::npos){
                ticketBooked = true;
            }
        }
        // Vérification si l'utilisateur n'a pas déjà acheté le billet ou si des places sont encore disponibles dans le vol
        if ((ticketBooked) or ( count > vol.getNombrePlaces() )){
            std::cerr << "Erreur: billet deja reserve sur votre compte. Si vous souhaitez reserver ce vol pour une autre personne, creer ou connecter un compte a son nom." << std::endl;
        } else {
            // Ajout de la réservation du client pour le vol choisi dans le fichier
            std::ofstream ticketsFileOut(TICKETS_FILE, std::ios::app);
            ticketsFileOut << vol.getIdVol() << " " << client.getNumeroClient() << "  " << count << "  " << "Premiere classe" << "  " << count << std::endl;
            ticketsFileOut.close();
            std::cout << "Billet reserve!" << std::endl;
        }
}

void infoVol() {
    int choice;
    int quitterRubrique;
    do {
        system("cls");
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
                std::cout << "----------------------------------------------------------------------\n";
                std::cout << "------------------------------LISTE VOLS------------------------------\n";
                std::cout << "\n";
                volParisLondres.displayInfoVol();
                volLondresBerlin.displayInfoVol();
                volBerlinParis.displayInfoVol();
                volParisNewYork.displayInfoVol();
                volNewYorkParis.displayInfoVol();
                std::cout << "\n";
                std::cout << "Choisissez une option : \n";
                std::cout << " 0. Pour quitter  \n ";
                std::cout << "1. Pour reserver le vol Paris-Londres \n ";
                std::cout << "2. Pour reserver le vol Londres-Berlin \n ";
                std::cout << "3. Pour reserver le vol Berlin-Paris \n ";
                std::cout << "4. Pour reserver le vol Paris-New York \n ";
                std::cout << "5. Pour reserver le vol New York-Paris \n ";

                std::cin >> quitterRubrique;

                if (quitterRubrique == 0) {
                    system("cls");
                    std::cout << "Retour au menu principal \n";
                    break;
                } else if (( quitterRubrique > 0 ) and ( quitterRubrique < 6 )) {
                    if ( quitterRubrique == 1 ){
                        acheterBillet(1, volParisLondres);
                    }
                    if ( quitterRubrique == 2 ){
                        acheterBillet(2, volLondresBerlin);
                    }
                    if ( quitterRubrique == 3 ){
                        acheterBillet(3, volBerlinParis);
                    }
                    if ( quitterRubrique == 4 ){
                        acheterBillet(4, volParisNewYork);
                    }
                    if ( quitterRubrique == 5 ){
                        acheterBillet(5, volNewYorkParis);
                    }
                } else {
                    while (( quitterRubrique < 0 ) and ( quitterRubrique > 5 )) {
                        std::cout << "Veuillez entrer une option proposee \n";
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


// Fonction pour afficher les différentes informations de l'utilisateur

void infoCompte(){

    int IDVol, IDClient, NumeroBil, Siege, choixC;
    std::string Classe;
    do {
        std::ifstream ticketFileIn(TICKETS_FILE);
        std::string lines;
        //system("cls");
        std::cout << "--------------------------------------------------\n";
        std::cout << "----------------------COMPTE----------------------\n";
        std::cout << "\n";
        std::cout << "Choisissez une option : \n";
        std::cout << "1. Afficher vos informations personelles \n";
        std::cout << "2. Afficher vos bilets reserves \n";
        std::cout << "0. Quitter \n";
        std::cout << "--------------------------------------------------\n";

        std::cin >> choixC;

        switch (choixC) {
            case 1:
                // Affichage des donnees personelles du client
                system("cls");
                client.displayInfoClient();
                break;
            case 2:
                system("cls");
                // Revue de toutes les lignes du document tickets.txt pour vérifier si le client a réservé un ou plusieurs vols et ainsi les afficher si oui
                while ( std::getline(ticketFileIn, lines)) {
                    std::istringstream billets(lines);
                    billets >> IDVol >> IDClient >> NumeroBil >> Classe >> Siege;
                    std::string sc = std::to_string(client.getNumeroClient());

                    if (lines.substr(2, sc.length()) == sc) {
                        switch (IDVol) {
                            case 1:
                                billet = Billet(NumeroBil, Classe, Siege, &volParisLondres, &client);
                                billet.displayInfoBillet();
                                break;
                            case 2:
                                billet = Billet(NumeroBil, Classe, Siege, &volLondresBerlin, &client);
                                billet.displayInfoBillet();
                                break;
                            case 3:
                                billet = Billet(NumeroBil, Classe, Siege, &volBerlinParis, &client);
                                billet.displayInfoBillet();
                                break;
                            case 4:
                                billet = Billet(NumeroBil, Classe, Siege, &volParisNewYork, &client);
                                billet.displayInfoBillet();
                                break;
                            case 5:
                                billet = Billet(NumeroBil, Classe, Siege, &volNewYorkParis, &client);
                                billet.displayInfoBillet();
                                break;
                            default:
                                return;
                        }
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