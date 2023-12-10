#ifndef AEROPORT_HPP
#define AEROPORT_HPP

#include <iostream>
#include <string>

class Aeroport {
private:
    std::string nom;
    std::string adresse;
    int nombreTerminal;

public:
    // Constructeur
    Aeroport();

    // Méthodes de modification des attributs
    void setNom(const std::string& newNom);
    void setAdresse(const std::string& newAdresse);
    void setNombreTerminal(int newNombreTerminal);

    // Méthodes d'accès aux attributs
    std::string getNom() const;
    std::string getAdresse() const;
    int getNombreTerminal() const;

    // Méthode d'affichage des informations de l'aéroport
    void displayInfoAeroport() const;
};

#endif
