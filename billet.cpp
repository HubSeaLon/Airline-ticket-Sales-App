#include <iostream>
#include "billet.hpp"

Billet::Billet(int _numeroBillet, std::string _date,  std::string _paysDepart, std::string _paysArrivee, double _prix, std::string _typeClasse, int _terminalDepart, int _terminalArrivee, int _siegePassager){
    numeroBillet = _numeroBillet;
    dateVol = _date;
    paysDepart = _paysDepart;
    paysArrivee = _paysArrivee;
    prix = _prix;
    typeClasse = _typeClasse;
    terminalDepart = _terminalDepart;
    terminalArrivee = _terminalArrivee;
    siegePassager = _siegePassager;
}

void Billet::setNumeroBillet(int _numeroBillet){
    numeroBillet = _numeroBillet;
}
int Billet::getNumeroBillet() const{
    return numeroBillet;
}

void Billet::setDateVol(std::string _date){
    dateVol = _date;
}
std::string Billet::getDateVol() const{
    return dateVol;
}

void Billet::setPaysDepart(std::string _paysDepart){
    paysDepart = _paysDepart;
}
std::string Billet::getPaysDepart() const{
    return paysDepart;
}

void Billet::setPaysArrivee(std::string _paysArrivee){
    paysArrivee = _paysArrivee;
}
std::string Billet::getPaysArrivee() const{
    return paysArrivee;
}

void Billet::setPrix(double _prix){
    prix = _prix;
}
double Billet::getPrix() const{
    return prix;
}

void Billet::setTypeClasse(std::string _typeClase){
    typeClasse = _typeClase;
}
std::string Billet::getTypClasse() const{
    return typeClasse;
}

void Billet::setTerminalDepart(int _terminalDepart){
    terminalDepart = _terminalDepart;
}
int Billet::getTerminalDepart() const{
    return terminalDepart;
}

void Billet::setTerminalArrivee(int _terminalArrivee){
    terminalArrivee = _terminalArrivee;
}
int Billet::getTerminalArrivee() const{
    return terminalArrivee;
}

void Billet::setSiegePassager(int _siegePassager){
    siegePassager = _siegePassager;
}
int Billet::getSiegePassager() const{
    return siegePassager;
}

void Billet::displayInfoBillet() const{
    std::cout<<"Numero du billet: "<<getNumeroBillet()<<std::endl;
    std::cout<<"Date du vol: "<<getDateVol()<<std::endl;
    std::cout<<"Pays de depart: "<<getPaysDepart()<<std::endl;
    std::cout<<"Pays d'arrivee: "<<getPaysArrivee()<<std::endl;
    std::cout<<"Prix: "<<getPrix()<<std::endl;
    std::cout<<"Classe: "<<getTypClasse()<<std::endl;
    std::cout<<"Terminal de depart: "<<getTerminalDepart()<<std::endl;
    std::cout<<"Terminal d'arrivee: "<<getTerminalArrivee()<<std::endl;
    std::cout<<"Siege: "<<getSiegePassager()<<std::endl;
}