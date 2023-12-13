#include <iostream>
#include "vol.hpp"

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

/*void Vol::setAeroportDepart(std::string _aeroportDepart){
    aeroportDepart = _aeroportDepart;
}
std::string Vol::getAeroportDepart() const{
    return aeroportDepart;
}

void Vol::setAeroportArrivee(std::string _aeroportArrivee){
    aeroportArrivee = _aeroportArrivee;
}
std::string Vol::getAeroportArrivee() const{
    return aeroportArrivee;
}*/


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
    std::cout<<"ID du vol: "<<getIdVol()<<std::endl;
    std::cout<<"Date de depart: "<<getDateDepart()<<std::endl;
    std::cout<<"Date d'arrivee: "<<getDateArrivee()<<std::endl;
    std::cout<<"Aeroport de depart: "<<aeroportDepart->getNom()<<std::endl;
    std::cout<<"Aeroport d'arrivee: "<<aeroportArrivee->getNom()<<std::endl;
    std::cout<<"Nombre de places: "<<getNombrePlaces()<<std::endl;
    std::cout<<"Prix: "<<getPrix()<<std::endl;
    std::cout<<"Terminal de depart: "<<getTerminalDepart()<<std::endl;
    std::cout<<"Terminal d'arrivee: "<<getTerminalArrivee()<<std::endl;
    std::cout<<"Compagnie: "<<compagnie->getNom()<<std::endl;
}

/*int main() {
    
    Aeroport* aeroportDepart = new Aeroport("Depart Airport", "adresse", 4);
    Aeroport* aeroportArrivee = new Aeroport("Ariv Airport", "adresse", 4);
    Compagnie* compagnie = new Compagnie("Air France", 7, 10, 1933, "France", 33141567800LL, "airfrance@gmail.com", "www.airfrance.com");

    
    Vol vol(2023, 12, 13, 2023, 12, 20, aeroportDepart, aeroportArrivee, 100, 500.0, 1, 2, compagnie);

    
    vol.displayInfoVol();

    
    vol.setNombrePlaces(120);
    vol.setPrix(550.0);
    vol.setTerminalDepart(3);
    vol.setTerminalArrivee(4);

    
    vol.displayInfoVol();

    
    delete aeroportDepart;
    delete aeroportArrivee;
    delete compagnie;

    return 0;
}*/