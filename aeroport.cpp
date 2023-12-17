#include "Aeroport.hpp"


// Méthodes de modification des attributs
void Aeroport::setNom(const std::string& newNom) {
    nom = newNom;
}

void Aeroport::setAdresse(const std::string& newAdresse) {
    adresse = newAdresse;
}

void Aeroport::setNombreTerminal(int newNombreTerminal) {
    nombreTerminal = newNombreTerminal;
}

// Méthodes d'accès aux attributs
std::string Aeroport::getNom() const {
    return nom;
}

std::string Aeroport::getAdresse() const {
    return adresse;
}

int Aeroport::getNombreTerminal() const {
    return nombreTerminal;
}

// Méthode d'affichage des informations de l'aéroport
void Aeroport::displayInfoAeroport() const {
    std::cout << "\n";
    std::cout << "---------------------------------------------------------------\n";
    std::cout << "Nom de l'aeroport     : " << nom << std::endl;
    std::cout << "Adresse de l'aeroport : " << adresse << std::endl;
    std::cout << "Nombre de terminaux   : " << nombreTerminal << std::endl;
    std::cout << "---------------------------------------------------------------\n";
    std::cout << "\n";
}
