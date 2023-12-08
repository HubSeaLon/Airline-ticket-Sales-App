#include <iostream>
#include "billet.hpp"

Billet::Billet(int _numeroBillet, std::string _typeClasse, int _siegePassager){
    numeroBillet = _numeroBillet;
    typeClasse = _typeClasse;
    siegePassager = _siegePassager;
}

void Billet::setNumeroBillet(int _numeroBillet){
    numeroBillet = _numeroBillet;
}
int Billet::getNumeroBillet() const{
    return numeroBillet;
}

void Billet::setTypeClasse(std::string _typeClase){
    typeClasse = _typeClase;
}
std::string Billet::getTypClasse() const{
    return typeClasse;
}

void Billet::setSiegePassager(int _siegePassager){
    siegePassager = _siegePassager;
}
int Billet::getSiegePassager() const{
    return siegePassager;
}

void Billet::displayInfoBillet() const{
    std::cout<<"Numero du billet: "<<getNumeroBillet()<<std::endl;
    std::cout<<"Classe: "<<getTypClasse()<<std::endl;
    std::cout<<"Siege: "<<getSiegePassager()<<std::endl;
}