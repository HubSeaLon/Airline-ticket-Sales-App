#ifndef COMPAGNIE_HPP
#define COMPAGNIE_HPP

#include <string>
#include <ctime>
#include "aeroport.hpp"

class Compagnie {
private:
    std::string nom;
    tm dateCreation;
    std::string pays;
    int numeroContact;
    std::string mailContact;
    std::string site;

public:
    Compagnie(const std::string& nom, int jour, int mois, int annee, const std::string& pays,
                     int numeroContact, const std::string& mailContact,
                     const std::string& site): nom(nom), pays(pays), numeroContact(numeroContact),
      mailContact(mailContact), site(site){
                        dateCreation.tm_year = annee - 1900;
                        dateCreation.tm_mon = mois - 1;
                        dateCreation.tm_mday = jour;
                        }

    std::string getNom() const;
    void setNom(const std::string& nouveauNom);

    void setdateCreation(int annee, int mois, int jour);
    std::string getdateCreation() const; 

    std::string getPays() const;
    void setPays(const std::string& nouveauPays);

    int getNumeroContact() const;
    void setNumeroContact(int nouveauNumeroContact);

    std::string getMailContact() const;
    void setMailContact(const std::string& nouveauMailContact);

    std::string getSite() const;
    void setSite(const std::string& nouveauSite);

    void displayInfoCompagnie() const;
};

#endif
