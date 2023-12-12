#include "Compagnie.hpp"
#include "aeroport.hpp"
#include "aeroport.cpp"
#include <iostream>
#include <ctime>

std::string Compagnie::getNom() const {
    return nom;
}

void Compagnie::setNom(const std::string& nouveauNom) {
    nom = nouveauNom;
}

void Compagnie::setdateCreation(int annee, int mois, int jour){
    dateCreation.tm_mday = jour;
    dateCreation.tm_mon = mois - 1;
    dateCreation.tm_year = annee - 1900;  
}
std::string Compagnie::getdateCreation() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateCreation);
    return std::string(buffer);
}

std::string Compagnie::getPays() const {
    return pays;
}

void Compagnie::setPays(const std::string& nouveauPays) {
    pays = nouveauPays;
}

int Compagnie::getNumeroContact() const {
    return numeroContact;
}

void Compagnie::setNumeroContact(int nouveauNumeroContact) {
    numeroContact = nouveauNumeroContact;
}

std::string Compagnie::getMailContact() const {
    return mailContact;
}

void Compagnie::setMailContact(const std::string& nouveauMailContact) {
    mailContact = nouveauMailContact;
}


std::string Compagnie::getSite() const {
    return site;
}

void Compagnie::setSite(const std::string& nouveauSite) {
    site = nouveauSite;
}

void Compagnie::displayInfoCompagnie() const {
    std::cout << "Nom de la compagnie : " << nom << std::endl;
    std::cout << "Date de creation : " << Compagnie::getdateCreation() << std::endl;
    std::cout << "Pays : " << pays << std::endl;
    std::cout << "Numero de contact : " << numeroContact << std::endl;
    std::cout << "Mail de contact : " << mailContact << std::endl;
    std::cout << "Site web : " << site << std::endl;
    std::cout << "Aeroport : " << aeroport->getNom() << std::endl;
}