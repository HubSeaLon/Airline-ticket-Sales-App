#include <iostream>
#include "vol.hpp"

Vol::Vol(int _idVol, int jourDepart, int moisDepart, int anneeDepart, int jourArrivee, int moisArrivee, int anneeArrivee, std::string _aeroportDepart, std::string _aeroportArrivee, int _nombrePlaces, double _prix, int _terminalDepart, int _terminalArrivee){
    idVol = _idVol;
    aeroportDepart = _aeroportDepart;
    aeroportArrivee = _aeroportArrivee;
    nombrePlaces = _nombrePlaces;
    prix = _prix;
    terminalDepart = _terminalDepart;
    terminalArrivee = _terminalArrivee;

    dateDepart.tm_year = anneeDepart - 1900;
    dateDepart.tm_mon = moisDepart - 1;
    dateDepart.tm_mday = jourDepart;
    dateArrivee.tm_year = anneeArrivee - 1900;
    dateArrivee.tm_mon = moisArrivee - 1;
    dateArrivee.tm_mday = jourArrivee;
}

void Vol::setIdVol(int _idVol){
    idVol = _idVol;
}
int Vol::getIdVol() const{
    return idVol;
}

void Vol::setDateDepart(int jour, int mois, int annee){
    dateDepart.tm_mday = jour;
    dateDepart.tm_mon = mois - 1;
    dateDepart.tm_year = annee - 1900;
}
std::string Vol::getDateDepart() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateDepart);
    return std::string(buffer);
}

void Vol::setDateArrivee(int jour, int mois, int annee){
    dateArrivee.tm_mday = jour;
    dateArrivee.tm_mon = mois - 1;
    dateArrivee.tm_year = annee - 1900; 
}
std::string Vol::getDateArrivee() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateArrivee);
    return std::string(buffer);
}

void Vol::setAeroportDepart(std::string _aeroportDepart){
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
    std::cout<<"ID du vol: "<<getIdVol()<<std::endl;
    std::cout<<"Date de depart: "<<getDateDepart()<<std::endl;
    std::cout<<"Date d'arrivee: "<<getDateArrivee()<<std::endl;
    std::cout<<"Aeroport de depart: "<<getAeroportDepart()<<std::endl;
    std::cout<<"Aeroport d'arrivee: "<<getAeroportArrivee()<<std::endl;
    std::cout<<"Nombre de places: "<<getNombrePlaces()<<std::endl;
    std::cout<<"Prix: "<<getPrix()<<std::endl;
    std::cout<<"Terminal de depart: "<<getTerminalDepart()<<std::endl;
    std::cout<<"Terminal d'arrivee: "<<getTerminalArrivee()<<std::endl;
}