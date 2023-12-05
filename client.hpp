#ifndef  DEF_CLIENT
#define DEF_CLIENT

#include <string>

class Client{
    private:
        int numeroClient;
        std::string nom;
        std::string prenom;
        std::string dateNaissance;
        std::string adresse;
        int numeroTel;
        std::string mail;

    public:
        Client(int _numeroClient, std::string _nom, std::string _prenom, std::string _date, std::string _adresse, int _numeroTel, std::string _mail);

        void setNumeroClient(int _numeroClient);
        int getNumeroClient() const;

        void setNom(std::string _nom);
        std::string getNom() const;

        void setPrenom(std::string _prenom);
        std::string getPrenom() const;

        void setDateNaissance(std::string _date);
        std::string getDateNaissance() const;

        void setAdresse(std::string _adresse);
        std::string getAdresse() const;

        void setNumeroTel(int _numeroTel);
        int getNumeroTel() const;

        void setMail(std::string _mail);
        std::string getMail() const;

        void displayInfoClient() const;
};
#endif