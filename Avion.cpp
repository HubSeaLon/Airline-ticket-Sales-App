#include <iostream>
#include <string>
#include "avion.hpp"
#include "jet.hpp"
#include "avionDeLigne.hpp"

// DEF AVION // 

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



//  DEF AVION DE LIGNE  //


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
    std::cout << "Nom modele : " << nomModele << std::endl;
    std::cout << "Capacite : " << capacite << std::endl;
    std::cout << "Nombre place Business : " << placeBusiness << std::endl;
    std::cout << "Nombre place Economie : " << placeEconomie << std::endl;
    std::cout << "Nombre place Premiere classe : " << placeFirstClasse << std::endl;
    std::cout << "Vitesse moy : " << vitesseMoy << std::endl;
    std::cout << "Altitude moy: " << altitudeMoy << std::endl;
    std::cout << "Poids : " << poids << std::endl;
    std::cout << "Distance max : " << distanceMax << std::endl;
    std::cout << "Date service : " << getDateService() << std::endl;
    std::cout << "Pays : " << pays << std::endl;
    std::cout << "\n";
    std::cout << "\n";
}

// DEF JET PRIVE // 

void JetPrive::setNombreSalon(int _nombreSalon){
    if (_nombreSalon < 0){
                std::cerr << "nombreSalon doit etre > 0" << std::endl;
                nombreSalon = 0;
            }else{
                nombreSalon = _nombreSalon;
            }
}

int JetPrive::getNombreSalon() const{
    return nombreSalon;
}

void JetPrive::setNombreBar(int _nombreBar){
     if (_nombreBar < 0){
                std::cerr << "nombreBar doit etre > 0" << std::endl;
                nombreBar = 0;
            }else{
                nombreBar = _nombreBar;
            }
}
int JetPrive::getNombreBar() const{
    return nombreBar;
}

void JetPrive::setNombreJacuzzi(int _nombreJacuzzi){
    if (_nombreJacuzzi < 0){
                std::cerr << "nombreJacuzzi doit etre > 0" << std::endl;
                nombreJacuzzi = 0;
            }else{
                nombreJacuzzi = _nombreJacuzzi;
            }
}
int JetPrive::getNombreJacuzzi() const{
    return nombreJacuzzi;
}

void JetPrive::displayInfoAvion() const{
    std::cout << "Nom modele : " << nomModele << std::endl;
    std::cout << "Capacite : " << capacite << std::endl;
    std::cout << "Nombre salon : " << nombreSalon << std::endl;
    std::cout << "Nombre bar : " << nombreBar << std::endl;
    std::cout << "Nombre jacuzzi : " << nombreJacuzzi << std::endl;
    std::cout << "Vitesse moy : " << vitesseMoy << std::endl;
    std::cout << "Altitude moy: " << altitudeMoy << std::endl;
    std::cout << "Poids : " << poids << std::endl;
    std::cout << "Distance max : " << distanceMax << std::endl;
    std::cout << "Date service : " << getDateService() << std::endl;
    std::cout << "Pays : " << pays << std::endl;
    std::cout << "\n";
    std::cout << "\n";
}



int main(int argc, char const *argv[])
{
    std::cout << "Liste des avions de lignes : \n";
    std::cout << "\n";

    AvionDeLigne Avion1("Boeing 737", 150, 900, 11000, 350, 5000, 1,1,2023, "France", 20, 100, 30);
    Avion1.displayInfoAvion();

    AvionDeLigne Avion2("Boeing 430", 200, 1000, 12000, 400, 7000, 5,4,2022, "France", 20, 150, 30);
    Avion2.displayInfoAvion();

    AvionDeLigne Avion3("Boeing A380", 500, 900, 10670, 560, 15200, 25,10,2007, "France", 150, 250, 100);
    Avion3.displayInfoAvion();

    std::cout << "Liste des jets prives : \n";
    std::cout << "\n";

    JetPrive Jet1("Gulfstream G650", 19, 956, 15545, 24.5, 12964, 01,01,2012, "Etats-Unis",1,1,1);
    Jet1.displayInfoAvion();

    JetPrive Jet2("Bombardier Global 7500", 19, 930, 15545, 24.5, 14264, 01,01,2018, "Canada",1,2,1);
    Jet2.displayInfoAvion();

    JetPrive Jet3("Dassault Falcon 8X", 14, 900, 15545, 19.3, 11945, 01,01,2016, "France",1,1,2);
    Jet3.displayInfoAvion();

    return 0;
}
