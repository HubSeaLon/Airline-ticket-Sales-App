#include <iostream>
#include "vol.hpp"
//#include "compagnie.cpp"
//#include "aeroport.cpp"

Vol::Vol(int jourDepart, int moisDepart, int anneeDepart, int jourArrivee, int moisArrivee, int anneeArrivee, Aeroport* _aeroportDepart, Aeroport* _aeroportArrivee, int _nombrePlaces, double _prix, int _terminalDepart, int _terminalArrivee, Compagnie* _compagnie){
    idVol = ++dernierIdVol;
    aeroportDepart = _aeroportDepart;
    aeroportArrivee = _aeroportArrivee;
    nombrePlaces = _nombrePlaces;
    prix = _prix;
    terminalDepart = _terminalDepart;
    terminalArrivee = _terminalArrivee;
    compagnie = _compagnie;

    dateDepart.tm_year = anneeDepart - 1900;
    dateDepart.tm_mon = moisDepart - 1;
    dateDepart.tm_mday = jourDepart;
    dateArrivee.tm_year = anneeArrivee - 1900;
    dateArrivee.tm_mon = moisArrivee - 1;
    dateArrivee.tm_mday = jourArrivee;
}

int Vol::dernierIdVol = 0;

int Vol::getIdVol() const{
    return idVol;
}

void Vol::setDateDepart(int annee, int mois, int jour){
    dateDepart.tm_mday = jour;
    dateDepart.tm_mon = mois - 1;
    dateDepart.tm_year = annee - 1900;  
}
std::string Vol::getDateDepart() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateDepart);
    return std::string(buffer);
}

tm Vol::getDateDepart1() const{
    return dateDepart;
}

void Vol::setDateArrivee(int annee, int mois, int jour){
    dateArrivee.tm_mday = jour;
    dateArrivee.tm_mon = mois - 1;
    dateArrivee.tm_year = annee - 1900; 
}
std::string Vol::getDateArrivee() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateArrivee);
    return std::string(buffer);
}

std::string Vol::getAeroportDepart() const {
    return aeroportDepart->getNom();
}

std::string Vol::getAeroportArrivee() const {
    return aeroportArrivee->getNom();
}

void Vol::setNombrePlaces(int _nombrePlaces){
    nombrePlaces = _nombrePlaces;
}
int Vol::getNombrePlaces() const{
    return nombrePlaces;
}

void Vol::setPrix(double _prix){
    prix = _prix;
}
double Vol::getPrix() const{
    return prix;
}

void Vol::setTerminalDepart(int _terminalDepart){
    terminalDepart = _terminalDepart;
}
int Vol::getTerminalDepart() const{
    return terminalDepart;
}

void Vol::setTerminalArrivee(int _terminalArrivee){
    terminalArrivee = _terminalArrivee;
}
int Vol::getTerminalArrivee() const{
    return terminalArrivee;
}

void Vol::displayInfoVol() const{
    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "ID du vol                : "<<getIdVol()<<std::endl;
    std::cout << "Date de depart           : "<<getDateDepart()<<std::endl;
    std::cout << "Date d'arrivee           : "<<getDateArrivee()<<std::endl;
    std::cout << "Aeroport de depart       : "<<aeroportDepart->getNom()<<std::endl;
    std::cout << "Aeroport d'arrivee       : "<<aeroportArrivee->getNom()<<std::endl;
    std::cout << "Nombre de places         : "<<getNombrePlaces()<<std::endl;
    std::cout << "Prix                     : "<<getPrix()<<std::endl;
    std::cout << "Terminal de depart       : "<<getTerminalDepart()<<std::endl;
    std::cout << "Terminal d'arrivee       : "<<getTerminalArrivee()<<std::endl;
    std::cout << "Compagnie                : "<<compagnie->getNom()<<std::endl;
    std::cout << "-------------------------------------------------------------------\n";
    std::cout << "\n";
    std::cout << "\n";
}


bool compareVols(const Vol& vol1, const Vol& vol2) {
    if (vol1.getDateDepart1().tm_year == vol2.getDateDepart1().tm_year) {
        if (vol1.getDateDepart1().tm_mon == vol2.getDateDepart1().tm_mon) {
            return vol1.getDateDepart1().tm_mday < vol2.getDateDepart1().tm_mday;
        }
        return vol1.getDateDepart1().tm_mon < vol2.getDateDepart1().tm_mon;
    }
    return vol1.getDateDepart1().tm_year < vol2.getDateDepart1().tm_year;
}


void afficherVolsTries(const std::vector<Vol>& vols) {
    // Copier le vecteur de vols pour ne pas modifier l'ordre original
    std::vector<Vol> volsCopie = vols;

    // Trier les vols en utilisant la fonction de comparaison
    std::sort(volsCopie.begin(), volsCopie.end(), compareVols);

    // Afficher les vols triés
    for (std::vector<Vol>::const_iterator it = volsCopie.begin(); it != volsCopie.end(); ++it) {
        it->displayInfoVol();
        std::cout << "------------------------" << std::endl;
    }
}

/*
int main() {
    // Create Aeroports
    Aeroport* aeroportDepart1 = new Aeroport("Depart Airport 1", "adresse1", 4);
    Aeroport* aeroportArrivee1 = new Aeroport("Arrival Airport 1", "adresse2", 4);

    Aeroport* aeroportDepart2 = new Aeroport("Depart Airport 2", "adresse3", 4);
    Aeroport* aeroportArrivee2 = new Aeroport("Arrival Airport 2", "adresse4", 4);

    // Create Compagnies
    Compagnie* compagnie1 = new Compagnie("Air France", 7, 10, 1933, "France", 33141567800LL, "airfrance@gmail.com", "www.airfrance.com");
    Compagnie* compagnie2 = new Compagnie("Lufthansa", 6, 4, 1955, "Germany", 491711470, "lufthansa@gmail.com", "www.lufthansa.com");

    // Create a vector of Vol objects
    std::vector<Vol> vols;

    // Add flights to the vector
    vols.push_back(Vol(13, 12, 2023, 20, 12, 2023, aeroportDepart1, aeroportArrivee1, 100, 500.0, 1, 2, compagnie1));
    vols.push_back(Vol(15, 12, 2023, 22, 12, 2023, aeroportDepart2, aeroportArrivee2, 120, 600.0, 3, 4, compagnie2));

    // Display sorted information about the flights
    afficherVolsTries(vols);

    // Clean up dynamically allocated memory
    delete aeroportDepart1;
    delete aeroportArrivee1;
    delete compagnie1;

    delete aeroportDepart2;
    delete aeroportArrivee2;
    delete compagnie2;

    return 0;
}*/



