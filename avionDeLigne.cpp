#include <iostream>
#include <string>
#include "avionDeLigne.hpp"



void AvionDeLigne::setPlaceBusiness(int _placeBusiness){
    if (_placeBusiness < 0){
                std::cerr << "PlaceBusiness doit etre > 0" << std::endl;
                placeBusiness = 0;
            }else{
                placeBusiness = _placeBusiness;
            }
}
int AvionDeLigne::getPlaceBusiness() const{
    return placeBusiness;
}


void AvionDeLigne::setPlaceEconomie(int _placeEconomie){
     if (_placeEconomie < 0){
                std::cerr << "PlaceEconomie doit etre > 0" << std::endl;
                placeEconomie = 0;
            }else{
                placeEconomie = _placeEconomie;
            }
}
int AvionDeLigne::getPlaceEconomie() const{
    return placeEconomie;
}

void AvionDeLigne::setPlaceFirstClasse(int _placeFirstClasse){
    if (_placeFirstClasse < 0){
                std::cerr << "PlaceBFirstClasse doit etre > 0" << std::endl;
                placeFirstClasse = 0;
            }else{
                placeFirstClasse = _placeFirstClasse;
            }   
}

int AvionDeLigne::getPlaceFirstClasse() const{
    return placeFirstClasse;
}

void AvionDeLigne::displayInfoAvion() const{
    std::cout << "\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "Nom modele             : " << nomModele <<std::endl;
    std::cout << "Capacite               : " << capacite << std::endl;
    std::cout << "Nbre place Business    : " << placeBusiness << std::endl;
    std::cout << "Nbre place Economie    : " << placeEconomie << std::endl;
    std::cout << "Nbre place 1ere classe : " << placeFirstClasse << std::endl;
    std::cout << "Vitesse moy (km/h)     : " << vitesseMoy << std::endl;
    std::cout << "Altitude moy (m)       : " << altitudeMoy << std::endl;
    std::cout << "Poids (t)              : " << poids << std::endl;
    std::cout << "Distance max (km)      : " << distanceMax << std::endl;
    std::cout << "Date service           : " << getDateService() << std::endl;
    std::cout << "Pays                   : " << pays << std::endl;
    std::cout << "Compagnie aerienne     : " << compagnie->getNom() << std::endl;
    std::cout << "-------------------------------------------------\n";
    std::cout << "\n";
}