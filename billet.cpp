#include <iostream>
#include "billet.hpp"
#include "client.hpp"
#include "vol.hpp"  

Billet::Billet(){}

Billet::Billet(int _numeroBillet, std::string _typeClasse, int _siegePassager, Vol* _vol, Client* _client){
    numeroBillet = _numeroBillet;
    typeClasse = _typeClasse;
    siegePassager = _siegePassager;
    vol = _vol;
    client = _client;
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
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "Numero du billet         : "<<getNumeroBillet()<<std::endl;
    std::cout << "Classe                   : "<<getTypClasse()<<std::endl;
    std::cout << "Siege                    : "<<getSiegePassager()<<std::endl;
    std::cout << "Aeroport de depart       : "<<vol->getAeroportDepart()<<std::endl;
    std::cout << "Aeroport d'arrivee       : "<<vol->getAeroportArrivee()<<std::endl;
    std::cout << "Client                   : "<<client->getNom()<<" "<<client->getPrenom()<<std::endl;
    std::cout << "----------------------------------------------------------------\n";
    std::cout << "\n";
}