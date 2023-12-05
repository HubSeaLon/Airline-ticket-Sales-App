#ifndef COMPAGNIE_HPP
#define COMPAGNIE_HPP

#include <string>
#include <ctime>

class Compagnie {
private:
    std::string nom;
    std::string dateCreation;
    std::string pays;
    int numeroContact;
    std::string mailContact;
    std::string directeur;
    std::string site;

public:
    Compagnie(const std::string& nom, const std::string& dateCreation, const std::string& pays,
              int numeroContact, const std::string& mailContact, const std::string& directeur,
              const std::string& site);

    std::string getNom() const;
    void setNom(const std::string& nouveauNom);

    const std::string& getDateCreation() const;
    void setDateCreation(const std::string& nouvelleDateCreation);

    std::string getPays() const;
    void setPays(const std::string& nouveauPays);

    int getNumeroContact() const;
    void setNumeroContact(int nouveauNumeroContact);

    std::string getMailContact() const;
    void setMailContact(const std::string& nouveauMailContact);

    std::string getDirecteur() const;
    void setDirecteur(const std::string& nouveauDirecteur);

    std::string getSite() const;
    void setSite(const std::string& nouveauSite);

    void displayInfoCompagnie() const;
};

#endif
