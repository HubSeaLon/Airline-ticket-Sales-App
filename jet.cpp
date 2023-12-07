#include <iostream>
#include <string>
#include "Avion.cpp"

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