#include "Compagnie.hpp"
#include <iostream>
#include <ctime>

Compagnie::Compagnie(const std::string& nom, const std::string& dateCreation, const std::string& pays,
                     int numeroContact, const std::string& mailContact, const std::string& directeur,
                     const std::string& site)
    : nom(nom), dateCreation(dateCreation), pays(pays), numeroContact(numeroContact),
      mailContact(mailContact), directeur(directeur), site(site) {}

std::string Compagnie::getNom() const {
    return nom;
}

void Compagnie::setNom(const std::string& nouveauNom) {
    nom = nouveauNom;
}

const std::string& Compagnie::getDateCreation() const {
    return dateCreation;
}

void Compagnie::setDateCreation(const std::string& nouvelleDateCreation) {
    dateCreation = nouvelleDateCreation;
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

std::string Compagnie::getDirecteur() const {
    return directeur;
}

void Compagnie::setDirecteur(const std::string& nouveauDirecteur) {
    directeur = nouveauDirecteur;
}

std::string Compagnie::getSite() const {
    return site;
}

void Compagnie::setSite(const std::string& nouveauSite) {
    site = nouveauSite;
}

void Compagnie::displayInfoCompagnie() const {
    std::cout << "Nom de la compagnie : " << nom << std::endl;
    std::cout << "Date de creation : " << dateCreation << std::endl;
    std::cout << "Pays : " << pays << std::endl;
    std::cout << "Numero de contact : " << numeroContact << std::endl;
    std::cout << "Mail de contact : " << mailContact << std::endl;
    std::cout << "Directeur : " << directeur << std::endl;
    std::cout << "Site web : " << site << std::endl << std::endl;
}

int main() {
    
    Compagnie maCompagnie("Ma Compagnie", "15/02/2023", "France", 123456789,
                          "contact@macompagnie.com", "Directeur", "www.macompagnie.com");

    // Affichage des informations de la compagnie
    maCompagnie.displayInfoCompagnie();

    // Utilisation des getters
    std::cout << "Nom de la compagnie : " << maCompagnie.getNom() << std::endl;
    std::cout << "Date de creation : " << maCompagnie.getDateCreation() << std::endl;
    std::cout << "Pays : " << maCompagnie.getPays() << std::endl;
    std::cout << "Numero de contact : " << maCompagnie.getNumeroContact() << std::endl;
    std::cout << "Mail de contact : " << maCompagnie.getMailContact() << std::endl;
    std::cout << "Directeur : " << maCompagnie.getDirecteur() << std::endl;
    std::cout << "Site web : " << maCompagnie.getSite() << std::endl << std::endl;

    // Utilisation des setters
    maCompagnie.setNom("Nouveau Nom");
    maCompagnie.setDateCreation("20/03/2023");
    maCompagnie.setPays("Nouveau Pays");
    maCompagnie.setNumeroContact(987654321);
    maCompagnie.setMailContact("nouveau@mail.com");
    maCompagnie.setDirecteur("Nouveau Directeur");
    maCompagnie.setSite("www.nouveausite.com");

    // Affichage des nouvelles informations
    maCompagnie.displayInfoCompagnie();

    return 0;
}