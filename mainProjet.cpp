#include <iostream>
#include <fstream>
#include <string>

const std::string ACCOUNTS_FILE = "accounts.txt";

void menuDebut();
void menuPrincipal();
void rubriqueInfo();
void createAccount();
void login();


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
                login();
                break;
            case 2:
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
    std::string username, password, nom, prenom, adresse, numeroTel, mail;
    int jourN, moisN, anneeN, ID;

    std::cout << "Entrez votre nom d'utilisateur : ";
    std::cin >> username;

    std::cout << "Entrez votre mot de passe : ";
    std::cin >> password;

    std::cout << "Entrez votre nom: ";
    std::cin >> nom;

    std::cout << "Entrez votre prenom: ";
    std::cin >> prenom;

    std::cout << "Entrez votre jour de naissance: ";
    std::cin >> jourN;

    std::cout << "Entrez votre mois de naissance: ";
    std::cin >> moisN;

    std::cout << "Entrez votre annee de naissance: ";
    std::cin >> anneeN;

    std::cout << "Entrez votre adresse: ";
    std::cin >> adresse;

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
    accountsFileOut << username << " " << password << " " << ID << " " << nom << " " << prenom << " " << jourN << " " << moisN << " " << anneeN << " " << adresse << " " << numeroTel << " " << mail <<std::endl;
    accountsFileOut.close();

    //ici?  Client client(ID,nom,prenom,jourN,moisN,anneeN,adresse,numeroTel,mail);

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
            break;
        }
    }

    accountsFileIn.close();

    // Vérifier si les informations de connexion sont correctes
    if (informationsDeConnexion) {
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
            std::cout << "Choisissez une option :" << std::endl;
            std::cout << "1. Consulter des vols" << std::endl;
            std::cout << "2. Consulter votre compte" << std::endl;
            std::cout << "3. Afficher rubrique informations" << std::endl;
            std::cout << "4. Se deconnecter" << std::endl;

            std::cin >> choice;

            switch (choice) {
                case 1:
                    std::cout << "Fonctionnalite non implementee pour l'instant." << std::endl;
                    break;
                case 2:
                    std::cout << "Fonctionnalite non implementee pour l'instant." << std::endl;
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
        std::cout << "\n";
        std::cout << "\n";
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
                std::cout << "\n";
                std::cout << "\n";
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
                std::cout << "\n";
                std::cout << "\n";
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
                std::cout << "\n";
                std::cout << "\n";
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

int main() {
    menuDebut();

    return 0;
}