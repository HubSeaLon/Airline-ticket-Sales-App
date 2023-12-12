#ifndef COMPAGNIE_HPP
#define COMPAGNIE_HPP

#include <string>
#include <ctime>

class Compagnie {
private:
    std::string nom;
    tm dateCreation;
    std::string pays;
    unsigned long long numeroContact;
    std::string mailContact;
    std::string site;

public:
    Compagnie(const std::string& nom, int jour, int mois, int annee, const std::string& pays,
              unsigned long long numeroContact, const std::string& mailContact,
              const std::string& site);

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
