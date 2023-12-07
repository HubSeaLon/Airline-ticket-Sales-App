#include <iostream>
#include <string>
#include "avion.hpp"


void Avion::setNomModele(std::string _nomModele){
    if (_nomModele.length() > 50 ){
                std::cerr << "Max 50 caracteres nomModele" << std::endl;
                nomModele = "Modele inconnu";
              }else{
                nomModele = _nomModele;
              }
}

std::string Avion::getNomModele() const{
    return nomModele;
}

void Avion::setCapacite(int _capacite){
     if (_capacite < 0){
                std::cerr << "Capacite doit etre > 0" << std::endl; 
                capacite = 0;
              }else{
                capacite = _capacite;      
              }
}
        
int Avion::getCapacite() const{
    return capacite;
}

void Avion::setVitesseMoy(double _vitesseMoy){
    if (_vitesseMoy < 0){
                std::cerr << "VitesseMoy doit etre > 0" << std::endl; 
                vitesseMoy = 0.0;
              }else{
                vitesseMoy = _vitesseMoy;      
              }
}

double Avion::getVitesseMoy() const{
    return vitesseMoy;
}


void Avion::setAltitudeMoy(double _altitudeMoy){
    if (_altitudeMoy < 0){
                std::cerr << "altitudeMoy doit etre > 0" << std::endl; 
                altitudeMoy = 0.0;
              }else{
                altitudeMoy = _altitudeMoy;      
              }
}

double Avion::getAltitudeMoy() const{
    return altitudeMoy;
}

void Avion::setPoids(double _poids){
    if (_poids < 0){
                std::cerr << "Poids doit etre > 0" << std::endl; 
                poids = 0.0;
              }else{
                poids = _poids;      
              }
}

double Avion::getPoids() const{
    return poids;
}

void Avion::setDistanceMax(double _distanceMax){
    if (_distanceMax < 0){
                std::cerr << "distanceMax doit etre > 0" << std::endl; 
                distanceMax = 0;
              }else{
                distanceMax = _distanceMax;      
              }
}

double Avion::getDistanceMax() const{
    return distanceMax;
}

void Avion::setDateService(int jour, int mois, int annee){
    dateService.tm_mday = jour;
    dateService.tm_mon = mois - 1;
    dateService.tm_year = annee - 1900;
}
std::string Avion:: getDateService() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateService);
    return std::string(buffer);
}

void Avion::setPays(std::string _pays){
    if (_pays.length() > 30 ){
                std::cerr << "Max 30 caracteres pays" << std::endl;
                pays = "Pays inconnu";
              }else{
                pays = _pays;
              }
}

std::string Avion::getPays() const{
    return pays;
}
